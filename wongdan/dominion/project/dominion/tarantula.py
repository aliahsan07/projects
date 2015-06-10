import time
import os
import sys
import re
import math
import operator
import functools

MAX_LINE = 2000
lineType = []
linePassCount = [0] * MAX_LINE
lineFailCount = [0] * MAX_LINE
suspect = [0] * MAX_LINE
print os.getcwd()

curFiles = []
for f in os.listdir(os.getcwd()):
	if f.split("_")[-1] == "dominion.c.gcov":
		curFiles.append(os.path.join(str(os.getcwd()), str(f)))
		print "File located = " + str(f)

for fileName in curFiles:

	if fileName.split("_")[1] == "Fail":
		passed = False
		print fileName + "Failed"
	else:
		passed = True
		print fileName + "Passed"

	x = 0
	fo = open(fileName, "r")
	for l in fo.readlines():
		temp = l.split(":")
		temp = temp[0]
		if temp[-1] == "0" or temp[-1] == "1" or temp[-1] == "2" or temp[-1] == "3" or temp[-1] == "4" or temp[-1] == "5" or temp[-1] == "6" or temp[-1] == "7" or temp[-1] == "8" or temp[-1] == "9":
			temp = re.sub(r'[^\d.]+','',temp)

			if(passed):
				linePassCount[x] = int(linePassCount[x]) + int(temp)
			else:
				lineFailCount[x] = int(linePassCount[x]) + int(temp)

		x = x + 1
	fo.close()
	print "found" + str(x) + "lines in file"

print " "

for x in range (0,2000):
	if lineFailCount[x] == 0:
		suspect[x] = 0
	else:
		suspect[x] = float(lineFailCount[x]) / (float(lineFailCount[x]) + float(linePassCount[x]))

print " "
print "Suspect lines found: "
for x in range(0, MAX_LINE):
	if suspect[x] > .75:
		print "Line number = " + str(x + 1) + " is suspect = " + str(suspect[x])

print "Done"
