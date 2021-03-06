from __future__ import division
import commands
import os, re
from operator import itemgetter
def gcov():
    #os.system("make clean unit3")
    os.system("rm -f dominion.c.gcov dominion.gcda")
    ret = runTest()
    os.system("gcov dominion.c")
    return ret

def runTest():
    (ret, output) = commands.getstatusoutput("unittest3")
    #Test failed (returned 0)
    if (ret == 0): 	
	ret = False
    #test passed (returned true)
    else: 
	ret = True
    return ret


def parseFile(lines, passed, start):
    file = open("dominion.c.gcov")
    index = 0
    for line in file.readlines():
	#strip out num times run
	lineStart = line[0:10]
	lineStart = re.sub("[-#: ]", "", lineStart)
	try:
	    numRuns = int(float(lineStart))
	except:
	    numRuns = 0
	
        if(testPassed):
	    if(start == True):
	        lines.append([numRuns, 0])
	    else:
	        lines[index][0] += numRuns
	else:
	    if(start == True):
		lines.append([0, numRuns])
	    else:
		lines[index][1] += numRuns
	index += 1
    file.close()
    return lines


def suspicionEval(lineRuns, passed, failed):
    susp = []
    lineNo = -4
    for line in lineRuns:
	if(line[1] == 0):
            susp.append([0, lineNo])
	else:
	    s = ((1.0)*(line[1]/failed))/((line[1]/failed) + (line[0])/passed) 
     	    susp.append([s, lineNo])
	lineNo += 1 
    
    sorted(susp, key=itemgetter(0))
    
    print "\n\n"
    for l in susp:
	if(l[0] > 0):
	    print "Suspiciousness: %f\nLine: %i\n\n" %(l[0], l[1])
        
#main
totalFailed = 0
totalPassed = 0
start = True
lineRuns = []  #[numTimesPassed][numTimesFailed]
for x in range(0, 100):
    testPassed = gcov()
    if(testPassed):
	totalPassed += 1
    else:
	totalFailed += 1
    lineRuns = parseFile(lineRuns, testPassed, start)
    start = False
    
print "Num tests passed: %i\n Num tests failed %i" % (totalPassed, totalFailed)
suspicionEval(lineRuns, totalPassed, totalFailed);


