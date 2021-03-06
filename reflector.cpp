#ifndef __REFLECTOR_CPP_INCLUDED__
#define __REFLECTOR_CPP_INCLUDED__

#include "reflector.h"

/* Mutator method. Updates the instance of reflector with
   the content of reflector_file, performing the necessary 
   error-checking along the way.                          */

void Reflector::feed(const char* reflector_file){
  
  ifstream in_stream(reflector_file);
  // There was an error opening the file. Perhaps it does not exist.
  if(in_stream.fail()) throw ERROR_OPENING_CONFIGURATION_FILE;

  // For the reflector file, numbers come in pairs. To handle this
  // even_odd_counter increments by one for each iteration of the while loop
  // and we use the % operator to determine whether we are dealing 
  // with the first or second number in the pair. The first number is always 
  // entered into a, the second always entered into b.
  int a = 0, b = 0, even_odd_counter = 0; 

  // Ignore whitespace. If the file has only whitespace then 
  // we will move to the eof() flag, and we will not enter
  // the while loop.
  in_stream >> ws;

  // NOTE: >26 integers in the file is assumed to be an error.
  // If this is the case we throw INVALID_REFLECTOR_MAPPING.
  // An alternative would be to ignore the 27th integer and above, but
  // this is not what was agreed in class.
  while(!in_stream.eof()){

    if(!(even_odd_counter%2))
      in_stream >> a;
    else
      in_stream >> b;

    //============================= ERROR CHECKING =====================================

    // Tried to connect a contact with itself, or with >1 other contact. 
    if(!(even_odd_counter%2) && connection_tracker[a]) throw INVALID_REFLECTOR_MAPPING; 
    if(even_odd_counter%2 && connection_tracker[b]) throw INVALID_REFLECTOR_MAPPING;

    // Supplied a number < 0 or > ALPHABET_SIZE-1.
    if(invalid_index(a) || invalid_index(b)) throw INVALID_INDEX;

    // Supplied non-numeric character into the integers a or b. in_stream's fail-bit raised
    if(in_stream.fail()) throw NON_NUMERIC_CHARACTER;

    //==================================================================================

    // Track which contacts have been used (to check for impossible configurations)
    if(!(even_odd_counter%2)) connection_tracker[a] = true; 
    if(even_odd_counter%2) connection_tracker[b] = true; 

    // After every valid pair of numbers, record their values.
    if(even_odd_counter%2){
      component_array[a] = b;
      component_array[b] = a;
    }
    in_stream >> ws;

    even_odd_counter++;
  }

  // If we don't have ALPHABET_SIZE number of  integers throw an exception
  if(even_odd_counter != ALPHABET_SIZE) throw INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;

  in_stream.close();
}


#endif
