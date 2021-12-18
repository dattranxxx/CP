#!/usr/bin/bash
while (true); do
    ./"gen" > "in"
    ./"bt_sp" < "in" > "out"
    ./"spath" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
