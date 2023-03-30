#! /bin/bash

declare -r dir=tests/tests_files
declare -r dir_og=original
declare -r dir_new=tested
declare -r diff_file=diff_file
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
	"(hola (a))"
	"(a)"
)

test_syntax=(
	"hola ()"
	">>>"
	"<>>"
	"<<>"
	">>>>>"
	"w (a)"
	"()"
)
test_regex=(
	"*"
	"a*"
	"*a"
	"*a*"
	"a*a*a"
)
test_target=(
	"anything"
	"a"
	"aa"
	"ab"
	"ba"
	"aaa"
)

function check_files()
{
	local	ok=0;
	if [[ $# -gt 2 ]]
	then
		./test -c "$1" "$2" $3 2>&1| cat -e> $dir/$dir_new/test.$nbr
	else
		./test -c "$1" 2>&1| cat -e> $dir/$dir_new/test.$nbr
	fi
	# Uncomment the comment below to silence error msg
	diff $dir/$dir_og/test.$nbr $dir/$dir_new/test.$nbr > $diff_file #2>/dev/null
	if [[ $? -eq 0 ]]
	then
		echo -ne "\033[32mOK $nbr\033[0m"
	else
		echo -ne "\033[31mKO $nbr\033[0m"
	# uncomment the below comment to show the result of diff in error case
		ok=1
	fi
	if [[ $# -gt 1 ]]
	then
		yellow_text " input \"$1\" regex \"$2\" target\"$3\""
	else
		yellow_text " input \"$1\""
	fi
	if test $ok -eq 1
	then
		red_text `cat $diff_file`
	fi
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

if [[ $# -eq 0 ]]
then
	yellow_text "\tWORD_ASSIGNAMENT"
	nbr=0;
	for name in "${test_word_assignament[@]}"
	do
		check_files "$name"
	done
	yellow_text "\tWORDS"
	for name in "${test_word[@]}"
	do
		check_files "$name"
	done
	yellow_text "\tPIPE"
	for name in "${test_pipe[@]}"
	do
		check_files "$name"
	done
	yellow_text "\tParenthesis"
	for name in "${test_parenthesis[@]}"
	do
		check_files "$name"
	done
	yellow_text "Syntax analyzer"
	for name in "${test_syntax[@]}"
	do
		check_files "$name"
	done
else
	nbr=41
fi

yellow_text "Regex"
for name in "${test_regex[@]}"
do
	for target in "${test_target[@]}"
	do
		check_files a "$name" "$target"
	done
done
rm -f $diff_file
#:e include/lxr.h:vsplit Makefile:tabnew src/test/test.c:vsplit tests/tester.sh
