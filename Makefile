CC = clang
FLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
NAME = snake
SOURCE = ./srcs/
LIB = ./lib/libraylib.a
CFILES = main.c\

${NAME}:
	${CC} ${FLAGS} ${LIB} ${addprefix ${SOURCE}, ${CFILES}} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean

.PHONY: ${NAME} clean fclean
