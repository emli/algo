while true
do
    ./gen > input.txt
    ./ac < input.txt > out1.txt
    ./wa < input.txt > out2.txt

    ok=$(cmp --silent out1.txt out2.txt || echo "files are different")

    if [ "$ok" = "" ]
    then
        echo "Good"
    else
        echo "Bad"
        break
    fi
done

  

