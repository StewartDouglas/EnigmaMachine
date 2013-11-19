#ifndef __ENIGMA_CPP_INCLUDE__
#define __ENIGMA_CPP_INCLUDE__

#include "enigma.h"

// If _int is not between 0 and 25 inclusive, then return true (meaning invalid)
bool invalid_index(int _int){
  return(_int > 25 || _int < 0);
}

// If ch is not between 'A' and 'Z' inclusive, then return true (meaning invalid)  
bool invalid_input(char ch){
  return(ch < 'A' || ch > 'Z');
}

// For a given 'code', send the appropriate message to cerr. 
void error_description(int code) {
  switch(code) {
  case INSUFFICIENT_NUMBER_OF_PARAMETERS: 
    cerr << "Error: There are an insufficient number of parameters."; break;
  case INVALID_INPUT_CHARACTER:
    cerr << "Error: Invalid input character."; break;
  case INVALID_INDEX:
    cerr << "Error: Invalid index."; break;
  case NON_NUMERIC_CHARACTER:
    cerr <<  "Error: Non-numeric character supplied."; break;
  case IMPOSSIBLE_PLUGBOARD_CONFIGURATION:
    cerr << "Error: Impossible plugboard configuration."; break;
  case INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS:
    cerr << "Error: Incorrect number of plugboard parameters."; break;
  case INVALID_ROTOR_MAPPING:
    cerr << "Error: Invalid rotor mapping."; break;
  case NO_ROTOR_STARTING_POSITION:
    cerr << "Error: No rotor starting position."; break;
  case INVALID_REFLECTOR_MAPPING:
    cerr << "Error: Invalid reflector mapping."; break;
  case INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS:
    cerr << "Error: Incorrect number of reflector parameters."; break;
  case ERROR_OPENING_CONFIGURATION_FILE:
    cerr << "Error: Unable to open configuration file."; break;
  default:
    cerr << "Unknown error";
  }
}

#endif

