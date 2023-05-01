all: Analyser

Analyser: lex.yy.c NodeDecl.cpp Visitor.cpp TypeClass.cpp main.cpp Analyser.tab.cpp Analyser.tab.h CodeGeneration/CodeGenerator.h CodeGeneration/CodeGenerator.cpp
	c++ lex.yy.c NodeDecl.cpp Visitor.cpp CodeGeneration/CodeGenerator.cpp TypeClass.cpp main.cpp -o Analyser

lex.yy.c: Analyser.lex
	lex Analyser.lex

Analyser.tab.cpp Analyser.tab.h: Analyser.y
	bison -d Analyser.y

clean:
	rm -f *.o

test: Analyser
	@for file in tests/*.txt; do \
		echo "Running test case $$file..."; \
		output=$$(./Analyser $$file); \
		exit_code=$$?; \
		last_line=$$(echo "$$output" | tail -n 1); \
		if [ $$exit_code -eq 0 ]; then \
			echo "$$file: OK ($$last_line)"; \
		else \
			echo "$$file: ERROR_CODE=($$exit_code) ($$last_line)"; \
		fi \
	done

run: Analyser
ifeq ($(file),)
	./Analyser
else
	./Analyser $(file)
endif
