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

all: ast.o symbolsTable.o y.tab.o lex.yy.o
	gcc ast.o symbolsTable.o y.tab.o lex.yy.o -lfl -o $(prefixe) -g

ast.o: ast.c ../include/ast.h
	gcc -c ast.c -g

symbolsTable.o: symbolsTable.c ../include/symbolsTable.h
	gcc -c symbolsTable.c -g

y.tab.o: $(prefixe).y
	yacc -d $(prefixe).y
	gcc -c y.tab.c -I../include/ -g

lex.yy.o: $(prefixe).l
	lex $(prefixe).l
	gcc -c lex.yy.c -g

# final target
final_target: ast.o symbolsTable.o blaster.o spec.o lex.yy.o lex.zz.o main.o
	gcc ast.o blaster.o symbolsTable.o spec.o lex.yy.o lex.zz.o main.o -lfl -o $(prefixe) -g -o blaster

main.o: main.c
	gcc -c main.c -g -I../include/ -g

lex.zz.o: spec.l blaster.y
	lex spec.l
	sed -i -e 's/zzwrap/yywrap/g' lex.zz.c
	gcc -c lex.zz.c -g

blaster.o: blaster.y
	yacc -d $(prefixe).y
	gcc -c y.tab.c -I../include/ -g -DTESTING -o blaster.o

spec.o: specParser.y
	yacc -d specParser.y --output specParser.c -p zz
	gcc -c specParser.c -g -I../include/ -o spec.o -DSPEC_PARSER

# test target
test: launch_test.o ast.o symbolsTable.o lex.yy.o
	gcc launch_test.o ast.o symbolsTable.o y.tab.o lex.yy.o -lfl -o test -I./ -I../include/

# spec parser
spec: specParser.o ast.o symbolsTable.o lex.yy.o 
	gcc specParser.o ast.o symbolsTable.o lex.yy.o -lfl -o spec -I./ -I../include/

specParser.o: specParser.y
	yacc -d specParser.y
	gcc -c y.tab.c -I../include/ -o specParser.o

yyparse: $(prefixe).y
	yacc -d $(prefixe).y
	gcc -c y.tab.c -I../include/ -DTESTING

launch_test.o: yyparse
	gcc -c ../tests/grammar/launch_test.c -I./ -I../include/

clean:
	rm -f *.o y.tab.c y.tab.h lex.yy.c lex.zz.c y.output a.out $(prefixe) ast.o symbolsTable.o test spec specParser.h specParser.c