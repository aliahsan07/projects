import os
import sys
import subprocess
import re

def main():
	testCount = 1000
	fails = 0
	passes = 0
	counter = 0
	domLines = 1351
	covered = []
	allTests = []

	for x in range (0, testCount):
		output = subprocess.check_output(["./cardtest3"])
		fails += int(output)
		new_out = subprocess.check_output(["gcov dominion.c"], shell = True)
		gcov_file = open ("dominion.c.gcov", "r")

		for line in gcov_file:
			linenum = line.split(":")[1]
			if ('-' in linenum or '#####' in linenum):
				pass
			else:
				num = int(linenum)
				covered.append(num)
		if(output is 1):
			for y in range(0, covered.length):
				covered[y][0] = 1
		allTests.append(covered)

	passes = testCount + fails

	if passes is 1000:
		print("All tests passed")
	else:
		for x in range(0, fails):
			print("Hi")

if __name__ == '__main__':
	main()
