prog=./$1

for (( i = 1; i <= 10000; i++ )); do
	echo ------------------
	echo SEED = $i
	echo ------------------
	$prog $i 2>&1
	s=$?
	if [[ $s != 0 ]]; then
		echo '******************'
		echo ERROR CODE = $s
		echo '******************'
		echo
	fi
done
