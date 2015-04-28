# compiler driver
CC = gcc

RM = /bin/rm -f

# compiler flags
CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage

# linker flags
LDFLAGS = -lm -lgcov -coverage

#PROG = 

# common header files
HDRS = dominion.h rngs.h Verify362.h

# common source and object files
SRCS = dominion.c rngs.c Verify362.c
OBJS = $(SRCS:.c=.o)

#TESTPROG = 
#TESTHDRS = 
#TESTSRCS = 
#TESTOBJS = 

# first (default) rule
all: playdom unittests cardtests FORCE

# rule for playdom
playdom: playdom.o $(OBJS) $(HDRS) FORCE
	$(CC) playdom.o $(OBJS) $(LDFLAGS) -o playdom

# rules for unit tests
unittests: unittest1 unittest2 unittest3 unittest4 FORCE

unittest1: unittest1.o $(OBJS) $(HDRS) FORCE
	$(CC) unittest1.o $(OBJS) $(LDFLAGS) -o unittest1

unittest2: unittest2.o $(OBJS) $(HDRS) FORCE
	$(CC) unittest2.o $(OBJS) $(LDFLAGS) -o unittest2

unittest3: unittest3.o $(OBJS) $(HDRS) FORCE
	$(CC) unittest3.o $(OBJS) $(LDFLAGS) -o unittest3

unittest4: unittest4.o $(OBJS) $(HDRS) FORCE
	$(CC) unittest4.o $(OBJS) $(LDFLAGS) -o unittest4
	
# rules for card effect tests
cardtests: cardtest1 cardtest2 cardtest3 cardtest4 FORCE

cardtest1: cardtest1.o $(OBJS) $(HDRS) FORCE
	$(CC) cardtest1.o $(OBJS) $(LDFLAGS) -o cardtest1

cardtest2: cardtest2.o $(OBJS) $(HDRS) FORCE
	$(CC) cardtest2.o $(OBJS) $(LDFLAGS) -o cardtest2

cardtest3: cardtest3.o $(OBJS) $(HDRS) FORCE
	$(CC) cardtest3.o $(OBJS) $(LDFLAGS) -o cardtest3

cardtest4: cardtest4.o $(OBJS) $(HDRS) FORCE
	$(CC) cardtest4.o $(OBJS) $(LDFLAGS) -o cardtest4

# rule to compile and execute tests and record results
unittestresults.out: clean unittests cardtests FORCE
	-./unittest1 &> unittestresults.out
	-./unittest2 >> unittestresults.out 2>&1
	-./unittest3 >> unittestresults.out 2>&1
	-./unittest4 >> unittestresults.out 2>&1
	-./cardtest1 >> unittestresults.out 2>&1
	-./cardtest2 >> unittestresults.out 2>&1
	-./cardtest3 >> unittestresults.out 2>&1
	-./cardtest4 >> unittestresults.out 2>&1
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

%.o: %.c $(HDRS) FORCE
	$(CC) $(CFLAGS) -c -std=c99 $<

clean: FORCE
	$(RM) *.o *~ *.gcno *.gcda *.gcov *.so
	$(RM) playdom
	$(RM) unittest1 unittest2 unittest3 unittest4
	$(RM) cardtest1 cardtest2 cardtest3 cardtest4
	$(RM) unittestresults.out

FORCE:
