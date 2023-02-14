bison -d Analyser.y
bison -y Analyser.y
bison Analyser.y -o BisonAnalyser
lex Analyser.l
gcc lex.yy.c y.tab.c -o Analyser
