#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"bt_bs" < "in" > "out"
    ./"boundseq" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
