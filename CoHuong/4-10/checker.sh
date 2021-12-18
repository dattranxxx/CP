#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"cake" < "in" > "out"
    ./"bt2" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
