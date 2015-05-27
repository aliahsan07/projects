#!/bin/bash
for i in {1..5..1}
do
    ./testdominion $i >> gameResults_mine_$i.out
    ./testdominion_their $i >> gameResults_their_$i.out
    # supress output form diff
    diff gameResults_mine_$i.out gameResults_their_$i.out &>/dev/null
    # grab the result of the last ran command
    result="$?"
    if [ $result -eq 1 ]
    then
        echo "For seed $i implementation differs see .out files"
    elif [ $result -eq 0 ]
    then
        echo "For seed $i no difference"
        rm mine_$i.out their_$i.out
    else
        echo "ERROR on seed $i diff"
    fi
done
