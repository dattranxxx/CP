#!/usr/bin/bash
while (true); do
    ./"gen_a" > "in"
    ./"a" < "in" > "out"
    ./"bt_a" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
