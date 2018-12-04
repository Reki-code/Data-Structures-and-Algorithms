tour.out: main.o login.o choice.o graph.o
	clang main.o login.o choice.o graph.o -o tour.out
main.o: main.c
	clang -c main.c
login.o: login.c
	clang -c login.c
choice.o: choice.c
	clang -c choice.c
graph.o: graph.c
	clang -c graph.c
