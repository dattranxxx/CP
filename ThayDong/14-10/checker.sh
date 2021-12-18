#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"lcbs" < "in" > "out"
    ./"lcs2x" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
