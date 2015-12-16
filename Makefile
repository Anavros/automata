TARGET:= main
TESTER:= DO_BUTT
C_SRCS:= $(wildcard *.c)
C_OBJS:= ${C_SRCS:.c=.o}
CFLAGS:= -Wall -Wextra -g -fdiagnostics-color=auto -ftrapv $(shell sdl2-config --cflags --libs) -lm
.PHONY: all clean run check test grind

all: $(C_OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_OBJS)

clean:
	@- $(RM) $(TARGET)
	@- $(RM) $(C_OBJS)

remake: clean all

run: all
	./$(TARGET)

test: all
	./$(TARGET) $(TESTER)

check: all
	valgrind -q --suppressions=grind.sup ./$(TARGET)

grind: all
	valgrind --suppressions=grind.sup --leak-check=full ./$(TARGET)

grind-tests: all
	valgrind --suppressions=grind.sup --leak-check=full ./$(TARGET) $(TESTER)
