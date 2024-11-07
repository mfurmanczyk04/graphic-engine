#ifndef UPDATABLEOBJECT_HPP
#define UPDATABLEOBJECT_HPP
#include "InputState.hpp"
class UpdatableObject {
public:
  virtual void update(const InputState &input) = 0;
};
#endif
