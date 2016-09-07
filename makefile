CC = g++
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -Wall -g
OBJ = main.o enigmamachine.o component.o plugboard.o reflector.o rotor.o enigma.o

# Link all object files to form target file.
# We use the following automatic variables:
# $@ is the name of the target of the rule (enigma)
# $^ is a list of all the dependencies
enigma: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile
%.o: %.c
	g++ $(CFLAGS) -c $*.c -o $*.o

clean:
	rm -f enigma *.o