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
	gcc ast.o y.tab.o lex.yy.o -lfl -o $(prefixe) -g

ast.o: ast.c ../include/ast.h
	gcc -c ast.c -g

y.tab.o: $(prefixe).y
	yacc -d $(prefixe).y
	gcc -c y.tab.c -I../include/ -g

lex.yy.o: $(prefixe).l
	lex $(prefixe).l
	gcc -c lex.yy.c -g


# test target
test: launch_test.o ast.o lex.yy.o
	gcc launch_test.o ast.o y.tab.o lex.yy.o -lfl -o test -I./ -I../include/

# spec parser
spec: specParser.o ast.o lex.yy.o 
	gcc specParser.o ast.o lex.yy.o -lfl -o spec -I./ -I../include/

specParser.o: specParser.y
	yacc -d specParser.y
	gcc -c y.tab.c -I../include/ -o specParser.o

yyparse: $(prefixe).y
	yacc -d $(prefixe).y
	gcc -c y.tab.c -I../include/ -DTESTING

launch_test.o: yyparse
	gcc -c ../tests/grammar/launch_test.c -I./ -I../include/

clean:
	rm -f *.o y.tab.c y.tab.h lex.yy.c y.output a.out $(prefixe) ast.o test