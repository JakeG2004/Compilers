make:
	flex calculator.l
	bison -d calculator.y
	gcc calculator.tab.c lex.yy.c -o calculator