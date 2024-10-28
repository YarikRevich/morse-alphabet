#pragma once

#include "systemc"

using namespace sc_core;

/**
 * 
 */
class CUSTOMIZED_TYPE {
  int x, y; // member variables
  CUSTOMIZED_TYPE(int x = 0, int y = 0) : x(x), y(y) {} // constructor

  CUSTOMIZED_TYPE& operator=(const CUSTOMIZED_TYPE& rhs) { // assignment operator, needed for read() write()
    x = rhs.x;
    y = rhs.y;
    return *this;
  }
  bool operator==(const CUSTOMIZED_TYPE& rhs) { // equality operator, needed for value_changed_event()
    return x == rhs.x && y == rhs.y;
  }
};