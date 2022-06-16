#fullcompile
fc:
	> compile compiler 
	gcc -o compiler.out main.cpp func/* -I. -lstdc++ 
	> run compiler
	./compiler.out