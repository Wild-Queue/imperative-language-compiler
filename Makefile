all:
	bison -d Analyser.y
	lex Analyser.lex
	c++ lex.yy.c NodeDecl.cpp Visitor.cpp TypeClass.cpp main.cpp -o Analyser
	./Analyser
