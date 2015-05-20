.SECONDEXPANSION:


EXE_SRC := cardtest1.c cardtest2.c cardtest3.c cardtest4.c playdom.c \
	playdom2.c player.c randomtestadventurer.c randomtestcard.c unittest1.c \
	unittest2.c unittest3.c unittest4.c
SRC := card.c dominion.c interface.c rngs.c more_dominion_helpers.c $(EXE_SRC)

OBJ := $(SRC:%.c=%.o)
GCNO := $(SRC:%.c=%.gcno)
EXE := $(EXE_SRC:%.c=%)

CC := gcc
CFLAGS := -std=c99 -fpic -coverage -g -Wall -Wextra
LDFLAGS := -lm -coverage


all: $(EXE)

$(OBJ): $$(patsubst %.o,%.c,$$@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $$@.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(GCNO) $(EXE) unittestresults.out randomtestadventurer.out

cleancov:
	rm -f *.gcda *.c.gcov


# hacks to work around how stupid the make language is

card.h dominion_helpers.h interface.h: dominion.h
	touch $@

randomtestadventurer.sh: randomtestadventurer
	touch $@

randomtestcard.sh: randomtestcard
	touch $@


card.o: card.h dominion.h
cardtest1.c: dominion.h
cardtest2.c: dominion.h
cardtest3.c: dominion.h
cardtest4.c: dominion.h
dominion.o: dominion.h dominion_helpers.h rngs.h
interface.o: card.h interface.h dominion.h rngs.h
more_dominion_helpers.o: more_dominion_helpers.h
playdom.o: dominion.h rngs.h
playdom2.o: dominion.h rngs.h
player.o: dominion.h interface.h rngs.h
randomtestadventurer.o: dominion.h dominion_helpers.h more_dominion_helpers.h \
	rngs.h
randomtestcard.o: dominion.h dominion_helpers.h more_dominion_helpers.h rngs.h
rngs.o: rngs.h
testDrawCard.o: dominion.h dominion_helpers.h rngs.h
unittest1.o: dominion.h
unittest2.o: dominion.h
unittest3.o: dominion_helpers.h
unittest4.o: dominion_helpers.h

cardtest1: card.o dominion.o rngs.o
cardtest2: card.o dominion.o rngs.o
cardtest3: card.o dominion.o rngs.o
cardtest4: card.o dominion.o rngs.o
dominion: rngs.o card.o
interface: card.o dominion.o rngs.o
playdom: card.o dominion.o rngs.o
playdom2: card.o dominion.o rngs.o
player: card.o dominion.o interface.o rngs.o
randomtestadventurer: card.o dominion.o more_dominion_helpers.o rngs.o
randomtestcard: card.o dominion.o more_dominion_helpers.o rngs.o
testDrawCard: card.o dominion.o rngs.o
unittest1: card.o dominion.o rngs.o
unittest2: card.o dominion.o rngs.o
unittest3: card.o dominion.o rngs.o
unittest4: card.o dominion.o rngs.o

unittestresults.out: cardtest1 cardtest2 cardtest3 cardtest4 unittest1 \
		unittest2 unittest3 unittest4
	rm -f $@
	echo '\n>>> TEST OUTPUT <<<\n' >>$@
	for prog in $^; do { ./$$prog >>$@ 2>&1; }; done
	echo '\n>>> GCOV OUTPUT <<<\n' >>$@
	gcov dominion.c card.c >>$@
	echo '\n>>> COVERAGE <<<\n' >>$@
	cat dominion.c.gcov card.c.gcov >>$@

randomtestadventurer.out: randomtestadventurer.sh
	rm -f $@
	stdbuf -o0 bash $< 2>&1 | tee -a $@

randomtestcard.out: randomtestcard.sh
	rm -f $@
	stdbuf -o0 bash $< 2>&1 | tee -a $@


.DEFAULT_GOAL := all
.PRECIOUS: randomtestadventurer.out randomtestcard.out
.PHONY: all clean randomtestadventurer.out randomtestcard.out
