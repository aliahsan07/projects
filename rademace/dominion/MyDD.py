import DD
import commands
import string


class MyDD(DD.DD):
    def __init__(self):
        DD.DD.__init__(self)
        
    def _test(self, deltas):
        # FIXME: Set up a test function that takes a set of deltas and
        # returns either self.PASS, self.FAIL, or self.UNRESOLVED.
        # Build input
        input = ""
        for (index, character) in deltas:
            input = input + character

       
        # Invoke dominion.c
        (status, output) = commands.getstatusoutput(
            "passing_test " + input)

        #print "output", output
        print "Exit Code", status

        # Determine outcome
        if status == 0:
            return self.PASS
        elif string.find(output, "INVALID") >= 0:
            return self.FAIL
        return self.UNRESOLVED

if __name__ == '__main__':
    # FIXME: Insert your deltas here 
     deltas = []
    index = 1
		f = open('failing_test.c', 'r')
    for line in f:
        deltas.append((index, line))
        index = index + 1

    	
    mydd = MyDD()
    
    print "Simplifying failure-inducing input..."
    c = mydd.ddmin(deltas)              # Invoke DDMIN
    print "The 1-minimal failure-inducing input is", c
    print "Removing any element will make the failure go away."
    print
    
    print "Isolating the failure-inducing difference..."
    (c, c1, c2) = mydd.dd(deltas)	# Invoke DD
    print "The 1-minimal failure-inducing difference is", c
    print c1, "passes,", c2, "fails"



# Local Variables:
# mode: python
# End:
