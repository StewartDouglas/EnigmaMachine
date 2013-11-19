#ifndef __ROTOR_CPP_INCLUDED__
#define __ROTOR_CPP_INCLUDED__

#include "rotor.h"

// Rotor constructor
Rotor::Rotor() : Component(), offset(0), notch_waiting(true), notch_array(){}

/* qyery_forwards & query_backwards replace the simpler methods
   of Component, to take account of the fact that a rotor can rotate.*/

/* We need +ALPHABET_SIZE on outputing since % does not 
   behave likfe the modulus functio in maths. An alternative
   would be to define our our mod() function.                        */
int Rotor::query_forwards(int n){
  n = (n + offset)%ALPHABET_SIZE;
  n = component_array[n];
  n = ((n - offset)+ALPHABET_SIZE)%ALPHABET_SIZE;
  return n;
}

/* Because we model a rotors wiring as an array of 26 integers, 
   the logic we use to 'query' a rotor one-way will not be the same
   when querying it the other way.                                   */
int Rotor::query_backwards(int n){
    n = (n + offset)%ALPHABET_SIZE;
    for(int i = 0; i < 26; i++)
      if(component_array[i] ==  n){ 
	n = i; break; }
    n = ((n + (ALPHABET_SIZE - offset))%ALPHABET_SIZE);
    return n;
}

// Increment the rotor by 'increment_number'. Offset can only be between 0 and 25.
void Rotor::increment(int increment_number){
  offset = ((offset + increment_number)%ALPHABET_SIZE);
  notch_waiting = true;
}

// Call this function if a notch has 'done its job' and turned the rotor to its left.
void Rotor::notch_used(){
  notch_waiting = false;
}

// Returns whether or not a notch should turn the rotor to its left (it must be
// in the correct position and must be 'waiting' to be used.)
bool Rotor::notch_value(int position){
  return (notch_array[(position + offset)%ALPHABET_SIZE] && notch_waiting);
}



/* Mutator method. Updates the instance of rotor with
   the content of plugboard_file, performing the necessary 
   error-checking along the way.                         */

void Rotor::feed(const char* rotor_file){
  
  ifstream in_stream(rotor_file);
  //There was an error opening the file. Perhaps it does not exist.
  if(in_stream.fail()) throw ERROR_OPENING_CONFIGURATION_FILE;

  // 'input' holds each of the input integers in turn. 'count' is used
  // to determine whether input represents a wiring configuration or a notch.
  int input, count = 0;

  // Ignore whitespace.
  in_stream >> ws;

  // Note: our file can contain an arbitrarily large number of integers. The 27th 
  // integer and above we treat as notchs, with duplicates being ignored.
  while(!in_stream.eof())
    {      
      in_stream >> input;
 
    //============================= ERROR CHECKING =====================================

      // Tried to connect a contact with >1 other contact.
      if(connection_tracker[input] && count < ALPHABET_SIZE) throw INVALID_ROTOR_MAPPING;
 
      // Supplied a number < 0 or > ALPHABET_SIZE-1.
      if(invalid_index(input)) throw INVALID_INDEX;

      // Supplied non-numeric character into the integers a or b. in_stream's fail-bit raised
      if(in_stream.fail()) throw NON_NUMERIC_CHARACTER;

    //==================================================================================
      
      // If count > ALPHABET_SIZE-1 then the numbers we are reading represent notchs.
      if(count > 25)
	notch_array[input] = true;
      else {
	component_array[count] = input;
	connection_tracker[input] = true;
      } 
      
     count++;

      // There may be whitespace at the end of the file
      in_stream >> ws;  
    }

  // User not supplied a sufficient number of inputs to make a valid rotor mapping 
  if(count < 25)
    throw INVALID_ROTOR_MAPPING;

  in_stream.close();

}

#endif
