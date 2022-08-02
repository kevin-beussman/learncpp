#!/bin/zsh

#Usage: zsh $(%s.%N) [options]
function show_help(){
	echo "
	Usage: zsh $ZSH_ARGZERO [options]

	Options:

	-n name				Unique name for project
	-h 				Display this help message and exit
	"
}

function escape(){
	exit -1
}

function help_and_escape(){
	show_help
	escape
}

ONE=1
getCreds=0
while getopts n:h flag
do
	case "${flag}" in
		n) name=${OPTARG};;
		h) help_and_escape;;
	esac
done
if [ -z "${name+xxx}" ];
then 
	echo "name not set. Set it with -n flag."
	escape
fi
if [ -z "${name}" ] && [ "{name+xxx}" = "xxx" ];
then
	echo "name set but empty. Set it with -n flag."
	escape
fi

mkdir $name
cp -r HelloWorldMultifile/.vscode $name