# Shouldn't hardcode this.
alias check50="node /usr/local/lib/check50/SOURCES/opt/check50/bin/check50.js"

# Args
COMMAND=$1
PROJECT=$2

if [ -z "$COMMAND" ] || [ -z "$PROJECT" ];
then
	echo "[command] [project]"
	exit
fi

if [ ! -f "${PROJECT}.c" ];
then
	echo "Project '${PROJECT}' does not exist"
	exit
fi

case "$COMMAND" in
"run")
		clang -o "${PROJECT}.out" "${PROJECT}.c" -lcs50

		"${PWD}/${PROJECT}.out"
		;;
"check")
		check50 "2015.fall.hacker1.${PROJECT}" "${PROJECT}.c"
		;;
*)
		echo "Unknown command"
		exit
		;;
esac
