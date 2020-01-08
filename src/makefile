prefixe=blaster
# all: $(prefixe).y $(prefixe).l
# 	yacc -d $(prefixe).y
# 	lex $(prefixe).l
# 	gcc y.tab.c lex.yy.c -ll -o $(prefixe)

# clean:
# 	rm -f *.o y.tab.c y.tab.h lex.yy.c a.out $(prefixe)

# lex: $(prefixe).l
# 	lex $(prefixe).l
# 	gcc lex.yy.c -o $(prefixe) -ll

all: ast.o y.tab.o lex.yy.o
	gcc ast.o y.tab.o lex.yy.o -lfl -o $(prefixe)

ast.o:
	gcc -c ast.c 

y.tab.o: $(prefixe).y
	yacc -d $(prefixe).y
	gcc -c y.tab.c

lex.yy.o: $(prefixe).l y.tab.h
	lex $(prefixe).l
	gcc -c lex.yy.c 

clean:
	rm -f *.o y.tab.c y.tab.h lex.yy.c y.output a.out $(prefixe) ast.o