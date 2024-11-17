#ifndef OBJECTMANAGER_HPP
#define OBJECTMANAGER_HPP
#include "GameObject.hpp"
class ObjectManager  {
public:
  virtual void addObject(GameObject *obj) = 0;
  virtual void removeObject(GameObject *obj) = 0;
};
#endif
