for i in $(seq 1 19); do
rm 5-3;
gcc -x assembler-with-cpp -D TEST=$i 5-3.s -no-pie -o 5-3;
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./5-3;
done
