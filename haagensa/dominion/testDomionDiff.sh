rm -rf testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 4 4 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 4 4 > gameResults.out
cp gameResults.out gameResults.other.out
echo 'for 4 players with randseed 4:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 3 4 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 3 4 > gameResults.out
cp gameResults.out gameResults.other.out
echo '' >> testDominion.out
echo 'for 3 players with randseed 4:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 2 4 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 2 4 > gameResults.out
cp gameResults.out gameResults.other.out
echo '' >> testDominion.out
echo 'for 2 players with randseed 4:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 1 4 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 1 4 > gameResults.out
cp gameResults.out gameResults.other.out
echo '' >> testDominion.out
echo 'for 1 players with randseed 4:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 3 12 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 3 12 > gameResults.out
cp gameResults.out gameResults.other.out
echo '' >> testDominion.out
echo 'for 3 players with randseed 12:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 4 12 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 4 12 > gameResults.out
cp gameResults.out gameResults.other.out
echo '' >> testDominion.out
echo 'for 4 players with randseed 12:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 2 12 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 2 12 > gameResults.out
cp gameResults.out gameResults.other.out
echo '' >> testDominion.out
echo 'for 2 players with randseed 12:' >> testDominion.out
diff --brief gameResults.my.out gameResults.other.out >> testDominion.out
echo '' >> testDominion.out
echo 'TESTING COMPLETED testDominion.out should exist!'
return 0
