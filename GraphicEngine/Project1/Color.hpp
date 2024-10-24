// Color.hpp
#ifndef COLOR_HPP
#define COLOR_HPP

class Color {
  typedef unsigned char byte;

public:
  Color(byte r, byte g, byte b, byte a);
  byte getR() { return r; } 
  byte getG() { return g; }
  byte getB() { return b; }
  byte getA() { return a; }
  void setR(byte r) { this->r = r; } 
  void setG(byte g) { this->g = g; }
  void setB(byte b) { this->b = b; }
  void setA(byte a) { this->a = a; }
  static const Color Black;       
  static const Color White;       
  static const Color Red;         
  static const Color Green;       
  static const Color Blue;        
  static const Color Yellow;      
  static const Color Magenta;     
  static const Color Cyan;        
  static const Color Transparent; 

private:
  byte r;
  byte g;
  byte b;
  byte a;
};
#endif
