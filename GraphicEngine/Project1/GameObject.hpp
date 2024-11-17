#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Initializer.hpp"

class GameObject {
public:
  virtual bool init(Initializer* initializer) {return true;};
};
#endif

