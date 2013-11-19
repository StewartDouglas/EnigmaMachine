#ifndef __ENIGMAMACHINE_H_INCLUDED__
#define __ENIGMAMACHINE_H_INCLUDED__

#include "enigma.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

/* The EnigmaMachine class contains instances of all the necessary Components
   to create a functioning simulation of the original enigma machine. This 
   includes a plugboard, a reflector and an array of rotors. It  has a 
   constructor method, and runEnigmaMachine() encrypts the users input
   (for a valid character, runEnigmaMachine() serves as a bijective function.) */

class EnigmaMachine {
private:
  Plugboard plugboard;
  Reflector reflector;
  Rotor* rotor_array;
  int numberRotors;
public:
  EnigmaMachine(int argc, const char * argv[]);
  ~EnigmaMachine(); 
  void runEnigmaMachine();
};

#endif 
