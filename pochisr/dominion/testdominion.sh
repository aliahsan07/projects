for (( i = 1; i <= 1000000; i++ )); do
	echo '##################'
	echo SEED = $i
	echo '##################'

	diff -u3 <(./testdominion $i 2>&1) <(./testdominion_alt $i 2>&1) | \
		tail -n +3 | head -n 20
done
