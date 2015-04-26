# define compiler driver
CC = gcc

RM = /bin/rm -f

# define flags for compiling and linking
CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage
LDFLAGS = -lm -lgcov -coverage

# define common dependencies
HEADERS = dominion.h rngs.h Verify362.h
OBJECTS = dominion.o rngs.o Verify362.o
#TESTOBJECTS = 
#TESTHEADERS = 

# compile everything
all: playdom unittests cardtests FORCE

# compile playdom
playdom: playdom.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) playdom.o $(OBJECTS) $(LDFLAGS) -o playdom

# compile unit tests
unittests: unittest1 unittest2 unittest3 unittest4 FORCE

unittest1: unittest1.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) unittest1.o $(OBJECTS) $(LDFLAGS) -o unittest1

unittest2: unittest2.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) unittest2.o $(OBJECTS) $(LDFLAGS) -o unittest2

unittest3: unittest3.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) unittest3.o $(OBJECTS) $(LDFLAGS) -o unittest3

unittest4: unittest4.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) unittest4.o $(OBJECTS) $(LDFLAGS) -o unittest4
	
# compile card effect tests
cardtests: cardtest1 cardtest2 cardtest3 cardtest4 FORCE

cardtest1: cardtest1.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) cardtest1.o $(OBJECTS) $(LDFLAGS) -o cardtest1

cardtest2: cardtest2.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) cardtest2.o $(OBJECTS) $(LDFLAGS) -o cardtest2

cardtest3: cardtest3.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) cardtest3.o $(OBJECTS) $(LDFLAGS) -o cardtest3

cardtest4: cardtest4.o $(OBJECTS) $(HEADERS) FORCE
	$(CC) cardtest4.o $(OBJECTS) $(LDFLAGS) -o cardtest4

# command to generate and execute tests and record test results
unittestresults.out: clean unittests cardtests FORCE
	-./unittest1 &> unittestresults.out
	-./unittest2 >> unittestresults.out 2>&1
	-./unittest3 >> unittestresults.out 2>&1
	-./unittest4 >> unittestresults.out 2>&1
	-./cardtest1 >> unittestresults.out 2>&1
	-./cardtest2 >> unittestresults.out 2>&1
	-./cardtest3 >> unittestresults.out 2>&1
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

%.o: %.c $(HEADERS) FORCE
	$(CC) $(CFLAGS) -c -std=c99 $<

clean: FORCE
	$(RM) *.o *~ *.gcno *.gcda *.gcov *.so
	$(RM) playdom
	$(RM) unittest1 unittest2 unittest3 unittest4
	$(RM) cardtest1 cardtest2 cardtest3 cardtest4
	$(RM) unittestresults.out

FORCE:
