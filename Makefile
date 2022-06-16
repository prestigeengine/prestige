#fullcompile on linux for linux
fc-linux:
	### compile compiler 
	gcc -o compiler.out main.cpp func/test/* func/compile/* -I. -lstdc++ 
	### run compiler
	./compiler.out

#fullcompile on linux for windows
fc-win:
	### requires mingw-w64 
	x86_64-w64-mingw32-g++ -o compiler.exe main.cpp func/test/* func/compile/* -I. -lstdc++ 