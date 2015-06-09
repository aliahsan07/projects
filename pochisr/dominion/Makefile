MAKEFLAGS += --no-builtin-rules

.SUFFIXES:
.SECONDEXPANSION:


EXE_SRC := cardtest1.c cardtest2.c cardtest3.c cardtest4.c fdiff.c playdom.c \
	playdom2.c player.c randomtestadventurer.c randomtestcard.c \
	testdominion.c unittest1.c unittest2.c unittest3.c unittest4.c
SRC := card.c dominion.c dominion_alt.c dominion_oatmanm.c interface.c rngs.c \
	more_dominion_helpers.c $(EXE_SRC)
EXTRA_EXE := cardtest1_oatmanm cardtest2_oatmanm cardtest3_oatmanm \
	cardtest4_oatmanm testdominion_alt testdominion_oatmanm unittest1_oatmanm \
	unittest2_oatmanm unittest3_oatmanm unittest4_oatmanm

OBJ := $(SRC:%.c=%.o)
GCNO := $(SRC:%.c=%.gcno)
GCDA := $(SRC:%.c=%.gcda)
GCOV := $(SRC:%=%.gcov)
EXE := $(EXE_SRC:%.c=%)

CC := gcc
CFLAGS := -std=c99 -fpic -coverage -g -Wall -Wextra \
	-Werror=implicit-function-declaration
LDFLAGS := -lm -coverage


all: $(EXE) $(EXTRA_EXE)

$(OBJ): $$(patsubst %.o,%.c,$$@)
	rm -f $<.gcov
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE) $(EXTRA_EXE):
	rm -f $<.gcda
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXE): $$@.o

clean: cleancov
	rm -f $(OBJ) $(GCNO) $(EXE) $(EXTRA_EXE) unittestresults.out \
		randomtestadventurer.out randomtestcard.out testdominion.out

cleancov:
	rm -f $(GCDA) $(GCOV)


# hacks to work around how stupid the make language is

card.h dominion_helpers.h interface.h: dominion.h
	touch $@

randomtestadventurer.sh: randomtestadventurer
	touch $@

randomtestcard.sh: randomtestcard
	touch $@

testdominion.sh: fdiff testdominion testdominion_alt
	touch $@


card.o: card.h dominion.h more_dominion_helpers.h
cardtest1.o cardtest2.o cardtest3.o cardtest4.o: dominion.h
dominion.o: dominion.h dominion_helpers.h rngs.h
dominion_alt.o: dominion.h dominion_helpers.h rngs.h
dominion_oatmanm.o: dominion.h dominion_helpers.h rngs.h
interface.o: card.h interface.h dominion.h rngs.h
more_dominion_helpers.o: more_dominion_helpers.h
playdom.o playdom2.o: dominion.h rngs.h
player.o: dominion.h interface.h rngs.h
randomtestadventurer.o: dominion.h dominion_helpers.h more_dominion_helpers.h \
	rngs.h
randomtestcard.o: dominion.h dominion_helpers.h more_dominion_helpers.h rngs.h
rngs.o: rngs.h
testdominion.o: dominion_helpers.h more_dominion_helpers.h
unittest1.o unittest2.o: dominion.h
unittest3.o unittest4.o: dominion_helpers.h

cardtest1 cardtest2 cardtest3 cardtest4: card.o dominion.o \
	more_dominion_helpers.o rngs.o
cardtest1_oatmanm cardtest2_oatmanm cardtest3_oatmanm cardtest4_oatmanm: \
	card.o dominion_oatmanm.o more_dominion_helpers.o rngs.o
cardtest1_oatmanm: cardtest1.o
cardtest2_oatmanm: cardtest2.o
cardtest3_oatmanm: cardtest3.o
cardtest4_oatmanm: cardtest4.o
interface_oatmanm: card.o dominion_oatmanm.o more_dominion_helpers.o rngs.o
playdom playdom2: card.o dominion.o more_dominion_helpers.o rngs.o
player: card.o dominion.o interface.o more_dominion_helpers.o rngs.o
randomtestadventurer randomtestcard: card.o dominion.o \
	more_dominion_helpers.o rngs.o
testdominion: card.o dominion.o more_dominion_helpers.o rngs.o
testdominion_alt: testdominion.o dominion_alt.o more_dominion_helpers.o rngs.o
testdominion_oatmanm: testdominion.o dominion_oatmanm.o \
	more_dominion_helpers.o rngs.o
unittest1 unittest2 unittest3 unittest4: card.o dominion.o \
	more_dominion_helpers.o rngs.o
unittest1_oatmanm unittest2_oatmanm unittest3_oatmanm unittest4_oatmanm: \
	card.o dominion_oatmanm.o more_dominion_helpers.o rngs.o
unittest1_oatmanm: unittest1.o
unittest2_oatmanm: unittest2.o
unittest3_oatmanm: unittest3.o
unittest4_oatmanm: unittest4.o

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
	stdbuf -o0 bash $< 2>&1 | tee $@

randomtestcard.out: randomtestcard.sh
	stdbuf -o0 bash $< 2>&1 | tee $@

testdominion.out: testdominion.sh
	bash $< >$@


.DEFAULT_GOAL := all
.PRECIOUS: randomtestadventurer.out randomtestcard.out testdominion.out
.PHONY: all clean cleancov randomtestadventurer.out randomtestcard.out \
	testdominion.out
