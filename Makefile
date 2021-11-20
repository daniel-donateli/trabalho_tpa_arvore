CFLAGS = -Wall -Wextra -pedantic -O2
CC = clang
INCLUDE = ./include
SRC = ./src
OBJS=main.o menu.o file_reader.o arvore.o

.PHONY: all main.o menu.o file_reader.o arvore.o

all: $(OBJS)
	${CC} ${CFLAGS} -I${INCLUDE} -o main.exe ${OBJS}

debug: CFLAGS = -DDEBUG -g

debug: CC = gcc

debug: all

clean:
	-rm -f *.o 

arvore.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/arvore.c -o arvore.o

file_reader.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/file_reader.c -o file_reader.o

menu.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/menu.c -o menu.o

main.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/main.c -o main.o