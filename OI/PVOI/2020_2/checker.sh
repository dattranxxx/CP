#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"toynano_t2" < "in" > "out"
    ./"toynano" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
