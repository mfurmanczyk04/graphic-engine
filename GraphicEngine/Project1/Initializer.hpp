#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

#include "BitmapHandler.hpp"

class ObjectManager;
class Initializer { 
public:
  virtual BitmapHandler *getBitmapHandler() = 0;
  virtual ObjectManager *getObjectManager() = 0;
};


#endif
