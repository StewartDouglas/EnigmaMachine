#ifndef __ROTOR_H_INCLUDED__
#define __ROTOR_H_INCLUDED__

#include "component.h"

/* Rotor is a subclass of Component.
   
   ** Attributes **
   
   - offset: records the extent to which a rotor is offset from the 'default' position,
            which is when 'A' is at the top / is at the 12 o'clock position.
   - notch_waiting: serves as a flag that a notch from one rotor has clicked into place
            and is 'waiting' to cause the next rotor to rotate. 
   - notch_array: a record of where each rotor has notches.
     
   ** Methods **
   
   - query_forwards: replaces the simpler query_forwards method of Component, to take account
            of the fact that a rotor can rotate.
   - query_backwards: again, needed because rotors can rotate.
     NOTE:  we have modeled the wiring as a single integer array => we need two query functions
   - increment: rotate the rotor 'increment_number' times.
   - notch_used: updates the notch_waiting flag to false, to inform the enigma machine
            that the notch has been utilised.
   - notch_value: returns true if there is a notch in 'position' and it is waiting to be used
   - feed: supply the rotor with the user's configuration

*/

class Rotor : public Component {
private:
  int offset;
  bool notch_waiting;
  bool notch_array[26];
public:
  Rotor();
  int query_forwards(int n);
  int query_backwards(int n);
  void increment(int increment_number);
  void notch_used();
  bool notch_value(int position);
  void feed(const char* rotor_file);
};

#endif 
