all: run

run_test: test
	./test

run_main: main
	./main

test: chained_ht.o sort.o read_print_helper.o chained_ht_test.c
	gcc -g chained_ht.c sort.c read_print_helper.c chained_ht_test.c -o test

main: chained_ht.o sort.o read_print_helper.o main.c
	gcc -g chained_ht.c sort.c read_print_helper.c main.c -o main

chained_ht.o: chained_ht.h chained_ht.c 
	gcc -c chained_ht.c

sort.o: sort.h sort.c
	gcc -c sort.c

read_print_helper.o: read_print_helper.h read_print_helper.c
	gcc -c read_print_helper.c 

clean: 
	rm *.o
	rm main
	rm test
