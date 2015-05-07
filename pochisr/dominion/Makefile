.SECONDEXPANSION:

SHELL := bash


# Game code
SRC := card.c dominion.c interface.c rngs.c
# Test code
SRC += badTestDrawCard.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
SRC += playdom.c playdom2.c player.c randomtestadventurer.c randomtestcard.c
SRC += testDrawCard.c unittest1.c unittest2.c unittest3.c unittest4.c

OBJ := $(SRC:%.c=%.o)

EXE := badTestDrawCard cardtest1 cardtest2 cardtest3 cardtest4 playdom playdom2
EXE += player randomtestadventurer randomtestcard testDrawCard unittest1
EXE += unittest2 unittest3 unittest4

CC := gcc

CFLAGS := -std=c99 -fpic -coverage -g
CFLAGS += -Wall -Wextra

LDFLAGS := -lm -coverage


all: $(EXE)

$(OBJ): $$(patsubst %.o,%.c,$$@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $$@.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(EXE) unittestresults.out


# hack to work around how stupid the make language is
card.h dominion_helpers.h interface.h: dominion.h
	touch $@


badTestDrawCard.o: dominion.h dominion_helpers.h rngs.h
card.o: card.h dominion.h
cardtest1.c: dominion.h
cardtest2.c: dominion.h
cardtest3.c: dominion.h
cardtest4.c: dominion.h
dominion.o: dominion.h dominion_helpers.h rngs.h
interface.o: card.h interface.h dominion.h rngs.h
playdom.o: dominion.h rngs.h
playdom2.o: dominion.h rngs.h
player.o: dominion.h interface.h rngs.h
randomtestadventurer.o: dominion.h dominion_helpers.h rngs.h
randomtestcard.o: dominion.h rngs.h
rngs.o: rngs.h
testDrawCard.o: dominion.h dominion_helpers.h rngs.h
unittest1.o: dominion.h
unittest2.o: dominion.h
unittest3.o: dominion_helpers.h
unittest4.o: dominion_helpers.h

badTestDrawCard: card.o dominion.o rngs.o
cardtest1: card.o dominion.o rngs.o
cardtest2: card.o dominion.o rngs.o
cardtest3: card.o dominion.o rngs.o
cardtest4: card.o dominion.o rngs.o
dominion: rngs.o card.o
interface: card.o dominion.o rngs.o
playdom: card.o dominion.o rngs.o
playdom2: card.o dominion.o rngs.o
player: card.o dominion.o interface.o rngs.o
randomtestadventurer: card.o dominion.o rngs.o
randomtestcard: card.o dominion.o rngs.o
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

randomtestadventurer.out: randomtestadventurer
	rm -f $@
	stdbuf -o0 bash randomtestadventurer.sh $< | tee -a $@

.DEFAULT_GOAL := all
.PHONY: all clean randomtestadventurer.out
