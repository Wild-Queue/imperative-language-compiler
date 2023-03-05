all:
	bison -y Analyser.y
	bison -v Analyser.y
	bison -d Analyser.y
	lex Analyser.lex
	c++ lex.yy.c main.cpp -o Analyser
	./Analyser
