enigma: main.o enigmamachine.o component.o plugboard.o reflector.o rotor.o enigma.o
	g++ -Wall -g main.o enigma.o enigmamachine.o component.o plugboard.o reflector.o rotor.o  -o enigma

main.o: main.cpp enigma.h enigmamachine.h plugboard.h reflector.h rotor.h
	g++ -Wall -g -c main.cpp

enigma.o: enigma.cpp enigma.h 
	g++ -Wall -g -c enigma.cpp

enigmamachine.o: enigmamachine.cpp plugboard.h reflector.h rotor.h enigma.h
	g++ -Wall -g -c enigmamachine.cpp 

component.o: component.cpp component.h enigma.h
	g++ -Wall -g -c component.cpp

plugboard.o: plugboard.cpp plugboard.h component.h
	g++ -Wall -g -c plugboard.cpp

reflector.o: reflector.cpp reflector.h component.h
	g++ -Wall -g -c reflector.cpp

rotor.o: rotor.cpp rotor.h component.h
	g++ -Wall -g -c rotor.cpp

clean:
	rm -f enigma *.o