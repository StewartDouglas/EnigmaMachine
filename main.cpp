#include "enigmamachine.h"

/* =============== STEWART DOUGLAS'S CODE (SD3112) ============= */
/* Most documentation is contained within the .h and .cpp files. */

int main(int argc, const char * argv[])
{
    // Create an enigma machine, then run it.
    try
    {  
      EnigmaMachine testMachine(argc, argv);
      testMachine.runEnigmaMachine();
    }
    // If there is an error, handle it with error_description()
    // and return the error code to main()
    catch(int error_code)
    {
      error_description(error_code);
      return error_code;
    }

    // If there are no errors, return 0 to main()
    return NO_ERROR;

}
