for (( i = 1; i <= 1000000; i++ )); do
	echo '##################'
	echo SEED = $i
	echo '##################'

	./fdiff <(./testdominion $i 2>&1) <(./testdominion_alt $i 2>&1) 10
done
