#ifndef __PLUGBOARD_H_INCLUDED__
#define __PLUGBOARD_H_INCLUDED__

#include "component.h"

/* A subclass of Component. Like the Reflector class the only 
   additional method is called 'feed', which allows the user to 
   update the plugboard with a wiring specified in plugboard_file.  */

class Plugboard : public Component {
public:
  void feed(const char* plugboard_file);
};

#endif 
