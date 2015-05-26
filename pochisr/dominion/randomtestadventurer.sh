for (( i = 1; i <= 1000000; i++ )); do
	echo ------------------
	echo SEED = $i
	echo ------------------
	./randomtestadventurer $i 2>&1
	s=$?
	if [[ $s != 0 ]]; then
		echo '******************'
		echo ERROR CODE = $s
		echo '******************'
		echo
	fi
done
