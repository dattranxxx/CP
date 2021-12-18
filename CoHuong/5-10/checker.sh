#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"experience" < "in" > "out"
    ./"bt" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
