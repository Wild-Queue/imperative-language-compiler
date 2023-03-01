all:
	bison -d Analyser.y
	lex Analyser.lex
	c++ lex.yy.c Analyser.tab.c -o Analyser
