all:
	bison -d Analyser.y
	lex Analyser.lex
	c++ lex.yy.c NodeDecl.cpp main.cpp -o Analyser
	./Analyser
