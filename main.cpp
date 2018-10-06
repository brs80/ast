#include "type.hpp"
#include "expr.hpp"
#include <iostream>

int main() {
    
  Bool_type b;
  Int_type i;
  Float_type f;
  
  Ref_type rf(&f); // ref float
  Ref_type rb(&b); // ref bool
  Ref_type ri(&i); // ref int
  Ref_type rri(&ri); // ref ref int
        
  std::cout << b << '\n';
  std::cout << i << '\n';
  std::cout << f << '\n';
  std::cout << rb << '\n';
  std::cout << rf << '\n';
  std::cout << ri << '\n';
  std::cout << rri << '\n';
  std::cout << '\n';
  
  std::cout << b << " == " << b << " -> " << equal(&b, &b) << '\n';
  std::cout << b << " == " << i << " -> " << equal(&b, &i) << '\n';
  std::cout << b << " == " << rb << " -> " << equal(&b, &rb) << '\n';
  std::cout << b << " == " << ri << " -> " << equal(&b, &ri) << '\n';
  std::cout << '\n';

  std::cout << i << " == " << b << " -> " << equal(&i, &b) << '\n';
  std::cout << i << " == " << i << " -> " << equal(&i, &i) << '\n';
  std::cout << i << " == " << rb << " -> " << equal(&i, &rb) << '\n';
  std::cout << i << " == " << ri << " -> " << equal(&i, &ri) << '\n';
  std::cout << '\n';

  std::cout << f << " == " << i << " -> " << equal(&f, &i) << '\n';
  std::cout << f << " == " << b << " -> " << equal(&f, &b) << '\n';
  std::cout << f << " == " << ri << " -> " << equal(&f, &ri) << '\n';
  std::cout << f << " == " << f << " -> " << equal(&f, &f) << '\n';
  std::cout << '\n';

  std::cout << rb << " == " << b << " -> " << equal(&rb, &b) << '\n';
  std::cout << rb << " == " << i << " -> " << equal(&rb, &i) << '\n';
  std::cout << rb << " == " << rb << " -> " << equal(&rb, &rb) << '\n';
  std::cout << rb << " == " << ri << " -> " << equal(&rb, &ri) << '\n';
  std::cout << '\n';

  std::cout << ri << " == " << b << " -> " << equal(&ri, &b) << '\n';
  std::cout << ri << " == " << i << " -> " << equal(&ri, &i) << '\n';
  std::cout << ri << " == " << rb << " -> " << equal(&ri, &rb) << '\n';
  std::cout << ri << " == " << ri << " -> " << equal(&ri, &ri) << '\n';
  std::cout << '\n';

}