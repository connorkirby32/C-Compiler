YFLAGS = -dv -t
CFLAGS = -g
a.out: grammar.o lex.o
	gcc -o a.out grammar.o lex.o -lfl


grammar.o: grammar.y
lex.o: lex.l


