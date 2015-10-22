YFLAGS = -dv -t
CFLAGS = -g -Wformat=0
a.out: grammar.o lex.o
	gcc -o a.out grammar.o lex.o driver.c -lfl
	rm -f *.o *~ y.output

grammar.o: grammar.y
lex.o: lex.l


