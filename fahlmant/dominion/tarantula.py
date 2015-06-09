import os
import sys
import subprocess
import re

def main():
    testcount = 1000
    fails = 0
    passes = 0
    counter = 0
    linesindom = 1351
    covered = []
    all_tests = []

    for x in range(0, testcount):
        output = subprocess.check_output(["./miniontest"])
        fails += int(output)
        new_out = subprocess.check_output(["gcov dominion.c"], shell=True)
        gcov_file = open("dominion.c.gcov", "r")
    
        for line in gcov_file:
            linenum = line.split(':')[1]
            if('-' in linenum or '#####' in linenum):
                pass
            else:
                num = int(linenum)
                covered.append(num)
        if(output is 1):
            for y in range(0, covered.length):
                covered[y][0] = 1
        all_tests.append(covered)        
                
    passes = testcount - fails
    
    if passes  is 1000:
        print("All tests passed")
#    elif passes is 0:
#        print("All tests failed")
    else:
        for x in range(0, fails):
            print(all_tests[x], end=' ')
        

if __name__ == '__main__':
    main()
