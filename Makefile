TARGET:= main
C_SRCS:= $(wildcard *.c)
C_OBJS:= ${C_SRCS:.c=.o}
CFLAGS:= -Wall -g $(shell sdl2-config --cflags --libs) -fdiagnostics-color=auto
.PHONY: all clean run check

all: $(C_OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_OBJS)

clean:
	@- $(RM) $(NAME)
	@- $(RM) $(C_OBJS)

run: all
	./$(TARGET)

check: all
	valgrind -q --suppressions=grind.sup ./main

grind: all
	valgrind --suppressions=grind.sup --leak-check=full ./main

# Suggestions:
# keep different file types in subfolders
