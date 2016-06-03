INCLUDES = -I src/
dirs = ./bin ./obj
main_obj = ./obj/main.o ./obj/lib.o ./obj/compress.o ./obj/decompress.o

all: ./bin/main

./bin/main: $(dirs) $(main_obj)
	gcc $(main_obj) -Wall -o ./bin/main

$(dirs):
	mkdir obj
	mkdir bin

./obj/main.o: ./src/main.c
	gcc -c ./src/main.c -Wall -o ./obj/main.o $(INCLUDES)

./obj/lib.o: ./src/lib.c
	gcc -c ./src/lib.c -Wall -o ./obj/lib.o $(INCLUDES)

./obj/compress.o: ./src/compress.c
	gcc -c ./src/compress.c -Wall -o ./obj/compress.o $(INCLUDES)

./obj/decompress.o: ./src/decompress.c
	gcc -c ./src/decompress.c -Wall -o ./obj/decompress.o $(INCLUDES)

.PHONY: clean
clean:
	rm -f -r bin/ obj/