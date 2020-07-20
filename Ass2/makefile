all: ; $(error Must define either "threads" or "processes"!)

threads: searchtest.c randomGenerator.o multitest_thread.o
	gcc searchtest.c randomGenerator.o multitest_thread.o -pthread -lm

processes: searchtest.c randomGenerator.o multitest_proc.o
	gcc searchtest.c randomGenerator.o multitest_proc.o -pthread -lm
	
randomGenerator.o: randomGenerator.c
	gcc -c randomGenerator.c

threadSearch.o: multitest_thread.c
	gcc -c multitest_thread.c

processSearch.o: multitest_proc.c
	gcc -c multitest_proc.c

clean:
	rm a.out; rm *.o
