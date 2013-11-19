#ifndef __REFLECTOR_H_INCLUDED__
#define __REFLECTOR_H_INCLUDED__

#include "component.h"

/* A subclass of Component. Like the Plugboard class, the only 
   additional method is called 'feed', which allows the user to
   update the plugboard with a wiring specified in reflector_file. */

class Reflector : public Component {
public:
  void feed(const char* reflector_file);
};

#endif 
