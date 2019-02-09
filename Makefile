testme.o: testme.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 testme.c -o testme -lm -g
	./testme
run:
	./testme &> testme.out
    
test:
	gcov testme.c &> results.out
	cat testme.c.gcov >> results.out

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.out testme


