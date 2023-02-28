all:
	bison -d Analyser.y
	lex Analyser.lex
	g++ lex.yy.c Analyser.tab.c -o Analyser
