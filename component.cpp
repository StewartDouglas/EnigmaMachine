#ifndef __COMPONENT_CPP_INCLUDED__
#define __COMPONENT_CPP_INCLUDED__

#include "component.h"

/* Constructor method. In the initialisation space, the default
   constructor for connection_tracker() is called. In C++, the 
   default constructor for a boolean array, like connection_tracker()
   initialises all the entries to false. In the body of the constructor
   each entry in component_array is set to its own index number. This
   models a component which maps each letter of the alphabet onto itself.*/
Component::Component(): connection_tracker() {
  for(int n = 0; n < 26; n++)
    component_array[n] = n;
}

/* Accessor method. Returns entry n in component_array */
int Component::query_forwards(int n){
  return component_array[n];
}

/* Accessor method. Finds the index in component_array
   containing the integer n.                           */
int Component::query_backwards(int n){
  for(int i = 0; i < 26; i++)
    {
      if(component_array[i] == n){
	n = i;
    	break;
      }
    }                                 
  return n;
}

#endif
