import time
import os
import sys
import re
import math
import operator
import functools

MAX_LINE = 2000
lineType = []
linePassCnt = [0] * MAX_LINE
lineFailCnt = [0] * MAX_LINE 
suspect = [0] * MAX_LINE 
print os.getcwd()

#Get all files in current dirctory that are dominion.c.gcov
curFiles = []
for f in os.listdir(os.getcwd()):
    if f.split("_")[-1] == "dominion.c.gcov":
        curFiles.append(os.path.join(str(os.getcwd()) ,str(f)))
        print "found file =" + str(f)

#for each file
for fileName in curFiles:
   
    if fileName.split("_")[1] == "fail":
        passed = False
        print fileName + " failed"
    else:
        passed = True
        print fileName + " passed"

    x = 0
    fo = open(fileName, "r")
    for l in fo.readlines():
        temp = l.split(":")
        temp = temp[0]
        if temp[-1] == "0" or temp[-1] == "1" or temp[-1] == "2" or temp[-1] == "3" or temp[-1] == "4" or temp[-1] == "5" or temp[-1] == "6" or temp[-1] == "7" or temp[-1] == "8" or temp[-1] == "9":
            temp = re.sub(r'[^\d.]+','',temp)

            if(passed):
                #print "pass" + str(temp)
                linePassCnt[x] = int(linePassCnt[x]) + int(temp) 
            else:
                #print "fail" + str(temp)
                lineFailCnt[x] = int(linePassCnt[x]) + int(temp)
        x = x + 1
    fo.close()
    print "found " + str(x) + " lines in file"

print " "
#calcualte odd of suspect line from 0 to 1
for x in range(0,2000):
    #print "x=" + str(x)
    if lineFailCnt[x] == 0:
        suspect[x] = 0
        #print suspect[x]
    else:
        suspect[x] = float(lineFailCnt[x]) / (float(lineFailCnt[x]) + float(linePassCnt[x]))
        #print suspect[x]

print " "
print "suspect lines fournd :"
for x in range(0,MAX_LINE):
    if suspect[x] > .75:
        print "line number=" + str(x + 1) + " is suspect=" + str(suspect[x])

print "done"