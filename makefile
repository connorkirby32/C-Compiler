YFLAGS = -dv -t
CFLAGS = -g
a.out: grammar.o lex.o
	gcc -o a.out grammar.o lex.o -lfl
	rm -f *.o *~ y.tab.h y.output

grammar.o: grammar.y
lex.o: lex.l


