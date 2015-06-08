temp=$(mktemp)
time_us=80000

trap "rm $temp" EXIT

for (( i = 1; i <= 1000000; i++ )); do
	echo '##################'
	echo "SEED = $i"
	echo '##################'
	echo

	echo $i 1>&2

	stdbuf -o0 $1 $i $time_us >$temp 2>&1
	if [[ $? != 0 ]]; then
		cat $temp
	else
		echo PASS
	fi

	echo
done
