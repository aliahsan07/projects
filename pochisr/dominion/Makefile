.SECONDEXPANSION:


SRC := badTestDrawCard.c dominion.c interface.c playdom.c playdom2.c player.c
SRC += randomtestadventurer.c randomtestcard.c rngs.c testDrawCard.c

OBJ := $(SRC:%.c=%.o)

EXE := badTestDrawCard playdom playdom2 player randomtestadventurer
EXE += randomtestcard testDrawCard

CC := gcc

CFLAGS := -Wall -fpic -coverage

LDFLAGS := -lm -coverage


all: $(EXE)

$(OBJ): $$(patsubst %.o,%.c,$$@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $$@.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(EXE)


# hack to work around how stupid the make language is
dominion_helpers.h interface.h: dominion.h
	touch $@


badTestDrawCard.o: dominion.h dominion_helpers.h rngs.h
dominion.o: dominion.h dominion_helpers.h rngs.h
interface.o: interface.h dominion.h rngs.h
playdom.o: dominion.h rngs.h
playdom2.o: dominion.h rngs.h
player.o: dominion.h interface.h rngs.h
randomtestadventurer.o: dominion.h rngs.h
randomtestcard.o: dominion.h rngs.h
rngs.o: rngs.h
testDrawCard.o: dominion.h dominion_helpers.h rngs.h

badTestDrawCard: dominion.o rngs.o
dominion: rngs.o
interface: dominion.o rngs.o
playdom: dominion.o rngs.o
playdom2: dominion.o rngs.o
player: dominion.o interface.o rngs.o
randomtestadventurer: dominion.o rngs.o
randomtestcard: dominion.o rngs.o
testDrawCard: dominion.o rngs.o


.DEFAULT_GOAL := all
.PHONY: all clean
