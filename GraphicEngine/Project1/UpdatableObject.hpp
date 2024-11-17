#ifndef UPDATABLEOBJECT_HPP
#define UPDATABLEOBJECT_HPP
#include "GameObject.hpp"
#include "InputState.hpp"
#include "ObjectManager.hpp"

class UpdatableObject : public virtual GameObject {
public:
  virtual void update(const InputState &input, ObjectManager* manager) = 0;
};
#endif
