#ifndef __ENIGMA_H_INCLUDE__
#define __ENIGMA_H_INCLUDE__

/* ================== Error Codes ===================  */

#define INSUFFICIENT_NUMBER_OF_PARAMETERS		1
#define INVALID_INPUT_CHARACTER				2
#define INVALID_INDEX					3
#define NON_NUMERIC_CHARACTER				4
#define IMPOSSIBLE_PLUGBOARD_CONFIGURATION		5
#define INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS	6
#define INVALID_ROTOR_MAPPING				7
#define NO_ROTOR_STARTING_POSITION			8
#define INVALID_REFLECTOR_MAPPING			9
#define INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS	10
#define ERROR_OPENING_CONFIGURATION_FILE		11

#define NO_ERROR					0

/* =================================================== */


/* ================== Helper defintions =============  */

/* ALPHABET_SIZE specifies the number of distinct characters 
   available. The user must also modify the body of the 
   invalid_input() function if they with to modify.    */

#define ALPHABET_SIZE                                   26

/* =================================================== */

/* ================== Libraries =====================  */

#include <iostream>
#include <fstream>
using namespace std;

/* =================================================== */

/* ============== Function prototypes ===============  */

// If 'ch' is not between 'A' and 'Z' inclusive, then return true (meaning invalid)
bool invalid_input(char ch);

// If _int is not between 0 and 25 inclusive, then return true (meaning invalid)
bool invalid_index(int _int);

// For a given 'code', send the appropriate message to cerr.
void error_description(int code);

/* =================================================== */

#endif

