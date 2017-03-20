compile: clean
	gcc main.c inc/*.c -o main
clean:
	rm -rf main main.dSYM
debug:
	gcc main.c inc/*.c -g -o main
