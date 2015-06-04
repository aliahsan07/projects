#!/bin/bash
for i in {1..100..1}
do
    ./testdominion_their $i >> gameResults_their_$i.out
done
