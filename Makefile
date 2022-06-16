#fullcompile
fc:
	### compile compiler 
	gcc -o compiler.out main.cpp func/test/* func/compile/* -I. -lstdc++ 
	### run compiler
	./compiler.out