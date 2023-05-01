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
	@echo "Running good tests..."
	@for file in tests/*.txt; do \
		output=$$(./Analyser $$file); \
		exit_code=$$?; \
		last_line=$$(echo "$$output" | tail -n 1); \
		if [ $$exit_code -eq 0 ]; then \
			echo "\033[0;32mOK\033[0m in $$file: \033[01;30m($$last_line)\033[0m"; \
		else \
			echo "\033[0;31mERROR_CODE=($$exit_code) in $$file: ($$last_line)\033[0m"; \
		fi; \
	done
	@echo "Running bad tests..."
	@for file in bad_tests/*.txt; do \
		output=$$(./Analyser $$file); \
		exit_code=$$?; \
		last_line=$$(echo "$$output" | tail -n 1); \
		if [ $$exit_code -eq 0 ]; then \
			echo "\033[0;31mERROR in $$file: because bad test is successful: \033[01;30m($$last_line)\033[0m"; \
		else \
			echo "\033[0;32mOK\033[0m in $$file: \033[01;30m($$last_line)\033[0m"; \
		fi; \
	done

run: Analyser
ifeq ($(file),)
	./Analyser
	cd Result/ && dotnet run
else
	./Analyser $(file)
	cd Result/ && dotnet run
endif
