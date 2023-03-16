#! /bin/bash

declare -r dir=tests/tests_files
declare -r dir_og=original
declare -r dir_new=tested
test_word_assignament=(
	"a="
	"a= "
	"a+="
	"a+= "
	"a+a="
	"a=a"
	"a+=a"
	"a=a\"dquoted text\"unquoted"
	"a=b'squoted text'unquoted"
	"a="
	"a= "
	"a==a"
	"a=a="
	"a+=a="
	"varname=\"this a normal var\"a'quoted 'Unquoted Hola"
	"a+=\"hola que tal  esta todo\"	other        words"
	"a+=\"hola que tal  esta todo\""
	"a=a b=b  c=c"
	"a=|"
	"a=echo|cat"
)

test_word=(
	"hola"
	" "
	"a\"hola que tal  esta todo\"a"
	"a\"hola que tal  esta todo\"a Bien Gracias por preguntar"
	"a\"hola\"a Bien Gracias por preguntar"
	"a\"hola\"a Bien Gracias por preguntar"
	"a\"ho\"'adios'a word"
	"hola ñ"
)

test_pipe=(
	"\"A		 |    B\""
	"A|B"
	"A|B"
	"A	 |	 B"
)

test_parenthesis=(
	'(hola (a))'
	"hola ()"
)
test_syntax=(
	">>>"
)

function check_files()
{
	./test -c "$1" | cat -e > $dir/$dir_new/test.$nbr
	diff $dir/$dir_og/test.$nbr $dir/$dir_new/test.$nbr
	if [[ $? -eq 0 ]]
	then
		echo -ne "\033[32mOK $nbr\033[0m"
	else
		echo -ne "\033[31mKO $nbr\033[0m"
	fi
	yellow_text " input \"$1\""
	let "nbr++"
}

function yellow_text()
{
	echo -e "\033[33m$1\033[0m"
}

function red_text()
{
	echo -e "\033[31m$1\033[0m"
}

function green_text()
{
	echo -e "\033[32m$1\033[0m"
}

yellow_text "WORD_ASSIGNAMENT"
nbr=0;
for name in "${test_word_assignament[@]}"
do
	check_files "$name"
done
yellow_text "WORDS"
for name in "${test_word[@]}"
do
	check_files "$name"
done
yellow_text "PIPE"
for name in "${test_pipe[@]}"
do
	check_files "$name"
done
yellow_text "Parenthesis"
for name in "${test_parenthesis[@]}"
do
	check_files "$name"
done
yellow_text "Syntax analyzer"
for name in "${test_syntax[@]}"
do
	check_files "$name"
done
#:e include/lxr.h:vsplit Makefile:tabnew src/test/test.c:vsplit tests/tester.sh
