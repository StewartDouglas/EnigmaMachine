#ifndef __COMPONENT_H_INCLUDED__
#define __COMPONENT_H_INCLUDED__

#include "enigma.h"

/* Component is an abstract class and is the superclass of the classes
   'Plugboard', 'Reflector' and 'Rotor'. 

   ** Attributes ** 
   
   - component_array: records how the component maps the alphabet onto itself.
   - connection_tracker: is used when configuring the components, to make sure 
             that a user-supplied configuration is valid (e.g. a Rotor cannot map two
	     letters onto one letter. connection_tracker works by having a bit raised 
	     if a letter is used for the first time. Each subsequent letterwhich is 
	     used is checked against this array to make sure it has not already been used.
  
   ** Methods **

   - Component: maps each letter of the alphabet onto itself within component_array.
   - query_forwards: used when the signal within the engima machine is traveling from the 
             user's key-press towards (and through) the reflector.
   - query_backwards: used when it is moving from the reflector back towards the output.            */

using namespace std;

class Component {
protected:
    int component_array[26];
    bool connection_tracker[26];
public:
    Component();
    int query_forwards(int n);
    int query_backwards(int n);
};

#endif
