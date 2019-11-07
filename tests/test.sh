#!/bin/zsh

PATH_42sh=../../42sh

RED='\e[0;31m'
GREEN='\e[0;32m'
BLACK='\e[0;0m'

chmod 755 tests_file/*
rm diff_* 2>&-

init()
{
	touch test1 test2 test3
}

cd 42sh_env
init
cd ../bash_env
init
cd ..

for file in tests_file/*
do
	file=$(echo $file | sed -e 's:tests_file/::g')
	cd 42sh_env
	$PATH_42sh < ../tests_file/$file >"../42sh_result/result_$file" 2>"../42sh_result/result_$file"
	cd ../bash_env
	bash < ../tests_file/$file >"../bash_result/result_$file" 2>"../bash_result/result_$file"
	cd ..
	diff bash_result/result_$file 42sh_result/result_$file 1>/dev/null 2>/dev/null
	if [ $? = 0 ]; then
		echo "${GREEN}$file${BLACK}"
	else
		echo "${RED}$file${BLACK}"
		echo "diff placed in : diff_$file"
		diff bash_result/result_$file 42sh_result/result_$file > diff_$file;
	fi
done