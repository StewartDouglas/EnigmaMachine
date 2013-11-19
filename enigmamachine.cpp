#ifndef __ENIGMAMACHINE_CPP_INCLUDED__
#define __ENIGMAMACHINE_CPP_INCLUDED__

#include "enigmamachine.h"

// Constructor metod. 

EnigmaMachine::EnigmaMachine(int argc, const char * argv[]){

  if(argc < 3) throw INSUFFICIENT_NUMBER_OF_PARAMETERS;

  // 'pos_stream' supplies the position data from the last file in argv
  ifstream pos_stream(argv[argc-1]);
  if(pos_stream.fail()) throw ERROR_OPENING_CONFIGURATION_FILE;
  
  // 'input' takes the input supplied by the user
  int input;
  // 'rotor_num' is used to iterate over the rotors
  int rotor_num = 0;
  // Calculate the number of rotors files (note if no rotor files 
  // are supplied this number will be 0 or -1.)
  numberRotors = argc - 4;

  // ==================== FEED THE PLUGBOARD & REFLECTOR ===========================

  plugboard.feed(argv[1]);
  reflector.feed(argv[2]);  

  // ==================== CREATE & FEED ANY ROTOR FILES =============================
  
  if(numberRotors > 0){
    rotor_array = new Rotor[numberRotors];
    // Supply the rotors which the data in each file in turn
    for(int i = 3; i < (argc-1); i++)
      rotor_array[i-3].feed(argv[i]);

    pos_stream >> ws;
   // Iterate through the position file, updating rotors accordingly
   // If there are n rotors, then the (n+1)th integers in this file will be ignored
    while(!pos_stream.eof() && rotor_num <= numberRotors){
  
      pos_stream >> input; 

      // If user tries to supply an index < 0 or > ALPHABET_SIZE-1 throw an exception.
      if(invalid_index(input)) throw INVALID_INDEX;

      // Attempted to input a non-numeric character into the integers a or b.
      // in_stream's fail-bit will be raised. Throw an exception.
      if(pos_stream.fail()) throw NON_NUMERIC_CHARACTER;
        
      // Increment the rotor by input%ALPHABET_SIZE
      rotor_array[rotor_num].increment(input%ALPHABET_SIZE);

      rotor_num++;

      pos_stream >> ws;

    }

    // If the position file has fewer integers than rotors throw an error
    if(rotor_num < numberRotors) throw NO_ROTOR_STARTING_POSITION;

  // =================== ROTOR FILES CREATED & FED ==================================

  }
}

// Deallocate the storage space used by rotor_array
EnigmaMachine::~EnigmaMachine(){
  if(numberRotors > 0)
    delete [] rotor_array;
}

// ====================== RUN THE ENIGMA MACHINE ====================================

void EnigmaMachine::runEnigmaMachine(){

    while(!cin.eof())
    {
      char ch;
      char output;
      int message;
      cin >> ws;

      cin.get(ch);
 
      // The user has attempted to input an invalid character. Throw an execption.
      if(invalid_input(ch)) throw INVALID_INPUT_CHARACTER;
     
      // Convert out input character into an integers, with 'A' corresponding to 0.
      message = ch - 'A';
 
      // Pass the message through the plugboard.
      message = plugboard.query_forwards(message);

      // Pass the message through the rotors, if there are any.
      if(numberRotors > 0){
	// The right-most rotor is rotated after every input.
	rotor_array[numberRotors-1].increment(1);
	// Iterate through all the rotors.
	for(int i = (numberRotors-1); i >= 0 ; i--)
	  {
	    // If a rotor is not the right-most, and the rotor to its right is in its
	    // notch position (and is waiting to be used), then increment the rotor.
	    if(i < (numberRotors-1) && rotor_array[i+1].notch_value(0)){
	      rotor_array[i].increment(1);
	      rotor_array[i+1].notch_used();
	    }
	    // The rotors have been incremented. Pass the signal thorugh.
	    message = rotor_array[i].query_forwards(message);
	  }
        }
      
      // Pass the message through the relfector.
      message = reflector.query_forwards(message);

      // Pass the message through the rotors, backwards.	  
      if(numberRotors>0){
	for(int i = 0; i < (numberRotors); i++)
	  message = rotor_array[i].query_backwards(message);
      }
      
      // Pass the message through the plugboard, backwards.
      message = plugboard.query_backwards(message);

      // Convert the integer message into a character, where 0 is converted to 'A'.
      output = message + 'A';
      // Pass output to the standard output.
      cout << output;
      // Take account of the fact that there may be whitespace at the end of the file.
      cin >> ws;
    }
 
}

// ======================== FINISHED RUNNING THE ENIGMA MACHINE =======================

#endif
