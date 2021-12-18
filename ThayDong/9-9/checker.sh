
#!/usr/bin/bash
while (true); do
    ./"gen_gcdseq" > "in"
    ./"gcdseq" < "in" > "out"
    ./"bt_gcdseq" < "in" > "ans"
    diff "out" "ans"
    if [ "$?" == "1" ]; then
        break
    fi
done
