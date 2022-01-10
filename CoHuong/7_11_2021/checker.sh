#!/usr/bin/bash
while (true); do
    ./"gen_ex" > "in"
    ./"ex" < "in" > "out"
    ./"bt_ex" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
