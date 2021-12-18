#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"a" < "in" > "out"
    ./"bt" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
