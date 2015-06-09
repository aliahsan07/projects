# $Id: MyDD.py,v 1.1 2001/11/05 19:53:33 zeller Exp $
# Template for adapting delta debugging.  Areas to customize are
# tagged with `FIXME'.

import DD
import string
import commands

class MyDD(DD.DD):
    def __init__(self):
        DD.DD.__init__(self)
        
    def _test(self, deltas):

	# FIXME: Set up a test function that takes a set of deltas and
        # returns either self.PASS, self.FAIL, or self.UNRESOLVED.

        input = ""
        for (index, character) in deltas:
            input = input + character

        #Write input to 'input.c'
        out = open('input.c', 'w')
        out.write(input)
        out.close()

        print self.coerce(deltas)

        (status, output) = commands.getstatusoutput("gcc -o testdominion.out testdominion.o rngs.o -Wall -fpic -coverage -lm -g; ./testdominion.out 5")

        print output
        print "Exit code", status

        if status == 0:
            return self.PASS
        elif string.find(output, "Segmentation fault") >= 0:
            return self.FAIL
        return self.UNRESOLVED

    def coerce(self, deltas):
        input = ""
        for (index, character) in deltas:
            input = input + character
        return input


if __name__ == '__main__':
    deltas = []
    index = 1
    for character in open("dominion.c").read():
        deltas.append((index, character))
        index = index + 1
   
    # FIXME: Insert your deltas here
    mydd = MyDD()
    
    print "Simplifying failure-inducing input..."
    c = mydd.ddmin(deltas)              # Invoke DDMIN
    print "The 1-minimal failure-inducing input is", mydd.coerce(c)
    print "Removing any element will make the failure go away."
    # print
    
    #print "Isolating the failure-inducing difference..."
    #(c, c1, c2) = mydd.dd(deltas)	# Invoke DD
    #print "The 1-minimal failure-inducing difference is", c
    #print c1, "passes,", c2, "fails"




# Local Variables:
# mode: python
# End:
