YFLAGS = -dv -t
CFLAGS = -g
a.out: grammar.o lex.o
	gcc -o a.out grammar.o lex.o -lfl


grammar.o: grammar.y
lex.o: lex.l

clean:
	rm -f *.o a.out y.tab.h y.output
