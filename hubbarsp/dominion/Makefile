# Name: Spencer Hubbard
# Date: 4/14/15
# CS 362

# compiler driver
CC = /usr/local/common/gcc-4.9.0/bin/gcc

RM = /bin/rm -f

# compiler flags
CFLAGS = -Wall -Wpedantic -g -fprofile-arcs -ftest-coverage

# linker flags
LDFLAGS = -lm -lgcov -coverage

#PROG = 

# common header files
HDRS = dominion.h dominion_helpers.h rngs.h CS362.h ll.h

# common source and object files
SRCS = dominion.c rngs.c CS362.c ll.c
OBJS = $(SRCS:.c=.o)

#TESTPROG = 
#TESTHDRS = 
#TESTSRCS = 
#TESTOBJS = 

# first (default) rule
all: playdom unittests cardtests randomtests testdominion FORCE

# rule for playdom
playdom: playdom.o $(OBJS) FORCE
	$(CC) playdom.o $(OBJS) $(LDFLAGS) -o playdom

# rules for unit tests
unittests: unittest1 unittest2 unittest3 unittest4 FORCE

unittest1: unittest1.o $(OBJS) FORCE
	$(CC) unittest1.o $(OBJS) $(LDFLAGS) -o unittest1

unittest2: unittest2.o $(OBJS) FORCE
	$(CC) unittest2.o $(OBJS) $(LDFLAGS) -o unittest2

unittest3: unittest3.o $(OBJS) FORCE
	$(CC) unittest3.o $(OBJS) $(LDFLAGS) -o unittest3

unittest4: unittest4.o $(OBJS) FORCE
	$(CC) unittest4.o $(OBJS) $(LDFLAGS) -o unittest4
	
# rules for card effect tests
cardtests: cardtest1 cardtest2 cardtest3 cardtest4 FORCE

cardtest1: cardtest1.o $(OBJS) FORCE
	$(CC) cardtest1.o $(OBJS) $(LDFLAGS) -o cardtest1

cardtest2: cardtest2.o $(OBJS) FORCE
	$(CC) cardtest2.o $(OBJS) $(LDFLAGS) -o cardtest2

cardtest3: cardtest3.o $(OBJS) FORCE
	$(CC) cardtest3.o $(OBJS) $(LDFLAGS) -o cardtest3

cardtest4: cardtest4.o $(OBJS) FORCE
	$(CC) cardtest4.o $(OBJS) $(LDFLAGS) -o cardtest4

# rule to compile and execute unit tests and record results
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

# rules for random tests
randomtests: randomtestadventurer randomtestcard

randomtestadventurer: randomtestadventurer.o $(OBJS) FORCE
	$(CC) randomtestadventurer.o $(OBJS) $(LDFLAGS) -o randomtestadventurer

randomtestcard: randomtestcard.o $(OBJS) FORCE
	$(CC) randomtestcard.o $(OBJS) $(LDFLAGS) -o randomtestcard

# rule to compile and execute random tests and record results
randomtestresults.out: clean randomtests FORCE
	-./randomtestadventurer &> randomtestresults.out
	-./randomtestcard >> randomtestresults.out 2>&1
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

# rules for testdominion
testdominion: testdominion.o $(OBJS) FORCE
	$(CC) testdominion.o $(OBJS) $(LDFLAGS) -o testdominion

# rules for object files
%.o: %.c $(HDRS) FORCE
	$(CC) $(CFLAGS) -c -std=c11 $<

clean: FORCE
	$(RM) *.o *~ *.gcno *.gcda *.gcov *.so
	$(RM) playdom
	$(RM) unittest1 unittest2 unittest3 unittest4
	$(RM) cardtest1 cardtest2 cardtest3 cardtest4
	$(RM) unittestresults.out
	$(RM) randomtestadventurer randomtestcard
	$(RM) randomtestresults.out
	$(RM) testdominion
	$(RM) gameResults.txt

FORCE:
