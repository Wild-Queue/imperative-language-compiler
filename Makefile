all:
	bison -r all Analyser.y
	lex Analyser.l
	gcc lex.yy.c y.tab.c -o Analyser
