#include "MyFloat.h"

MyFloat::MyFloat(){
  sign = 0;
  exponent = 0;
  mantissa = 0;
}

MyFloat::MyFloat(float f){
  unpackFloat(f);
}

MyFloat::MyFloat(const MyFloat & rhs){
	sign = rhs.sign;
	exponent = rhs.exponent;
	mantissa = rhs.mantissa;
}

ostream& operator<<(std::ostream &strm, const MyFloat &f){
	//this function is complete. No need to modify it.
	strm << f.packFloat();
	return strm;
}

MyFloat MyFloat::operator+(const MyFloat& rhs) const{
  MyFloat f;
  unsigned int lhsExponent = this->exponent-127;
  unsigned int rhsExponent = rhs.exponent-127;
  unsigned int maxExponent = rhsExponent;
  unsigned int lhsMantissa = this->mantissa;
  unsigned int rhsMantissa = rhs.mantissa;
  unsigned int lhsSign = this->sign;
  unsigned int rhsSign = rhs.sign;
  if (lhsSign != rhsSign && lhsMantissa == rhsMantissa && lhsExponent == rhsExponent) {
    return f;
  }
  lhsMantissa |= 1<<23;
  rhsMantissa |= 1<<23;
  unsigned int shiftAmount = maxExponent - lhsExponent;
  f.sign = rhsSign;
  if (lhsExponent > rhsExponent) {
    f.sign = lhsSign;
    maxExponent = lhsExponent;
    shiftAmount = maxExponent - rhsExponent;
    rhsMantissa = rhsMantissa >> shiftAmount;
  } else {
    lhsMantissa = lhsMantissa >> shiftAmount;
  }
  unsigned int addedMantissa;
  int carry = 0;
  if (lhsSign == 0 && rhsSign == 1) {
    unsigned int temp1 = lhsMantissa << 8;
    unsigned int temp2 = rhsMantissa << 8;
    unsigned int added = temp1+temp2;
    if ((added & (1<<31)) == 0) {
      carry = 1;
    }
  }
  if (f.sign == 0) {
    if (lhsSign == 0 && rhsSign == 0) {
      addedMantissa = rhsMantissa+lhsMantissa;
      if ((addedMantissa & (1<<24)) != 0) {
        maxExponent = maxExponent + 1;
        addedMantissa = addedMantissa >> 1;
        addedMantissa = addedMantissa & ~(1<<23);
      } else {
        addedMantissa = addedMantissa & ~(1<<23);
      }
    }
    if (lhsSign == 1 && rhsSign == 0) {
      addedMantissa = rhsMantissa-lhsMantissa;
      if ((addedMantissa & (1<<23)) == 0) {
        maxExponent = maxExponent - 1;
        addedMantissa = addedMantissa << 1;
        addedMantissa = addedMantissa & ~(1<<23);
      } else {
        addedMantissa = addedMantissa & ~(1<<23);
      }
    }
    if (lhsSign == 0 && rhsSign == 1) {
      addedMantissa = lhsMantissa-rhsMantissa;
      if ((addedMantissa & (1<<23)) == 0) {
        maxExponent = maxExponent - 1;
        addedMantissa = addedMantissa << 1;
        addedMantissa = addedMantissa & ~(1<<23);
      } else {
        addedMantissa = addedMantissa & ~(1<<23);
      }
    }
  } else if (f.sign == 1) {
    if (lhsSign == 1 && rhsSign == 1) {
      addedMantissa = rhsMantissa+lhsMantissa;
      if ((addedMantissa & (1<<24)) != 0) {
        maxExponent = maxExponent + 1;
        addedMantissa = addedMantissa >> 1;
        addedMantissa = addedMantissa & ~(1<<23);
      } else {
        addedMantissa = addedMantissa & ~(1<<23);
      }
    }
    if (lhsSign == 0 && rhsSign == 1) {
      addedMantissa = rhsMantissa-lhsMantissa;
      if ((addedMantissa & (1<<23)) == 0) {
        maxExponent = maxExponent - 1;
        addedMantissa = addedMantissa << 1;
        addedMantissa = addedMantissa & ~(1<<23);
      } else {
        addedMantissa = addedMantissa & ~(1<<23);
      }
    }
    if (lhsSign == 1 && rhsSign == 0) {
      addedMantissa = lhsMantissa-rhsMantissa;
      if ((addedMantissa & (1<<23)) == 0) {
        maxExponent = maxExponent - 1;
        addedMantissa = addedMantissa << 1;
        addedMantissa = addedMantissa & ~(1<<23);
      } else {
        addedMantissa = addedMantissa & ~(1<<23);
      }
    }
  }
  f.mantissa = addedMantissa - carry;
  f.exponent = maxExponent+127;
	return f;
}

MyFloat MyFloat::operator-(const MyFloat& rhs) const{
  MyFloat f;
  if (rhs.sign == 0) {
    MyFloat newRHS = rhs;
    newRHS.sign = 1;
    f = this->operator+(newRHS);
  } else {
    MyFloat newRHS = rhs;
    newRHS.sign = 0;
    f = this->operator+(newRHS);
  }
	return f;
}

bool MyFloat::operator==(const float rhs) const{
	return false; //this is just a stub so your code will compile
}

void MyFloat::unpackFloat(float f) {
  __asm__(
  "mov %[f], %[sign];"
  "shr $31, %[sign];"
  "mov %[f], %[exponent];"
  "shl $1, %[exponent];"
  "shr $24, %[exponent];"
  "mov %[f], %[mantissa];"
  "shl $9, %[mantissa];"
  "shr $9, %[mantissa]"
  ://output
  [sign] "=r" (sign),
  [exponent] "=r" (exponent),
  [mantissa] "=r" (mantissa)
  : // input
  [f] "r" (f)
  : //clobber
  "cc"
	);
}

float MyFloat::packFloat() const{
  float f = 0;
  __asm__(
  "shl $31, %[sign];"
  "shl $23, %[exponent];"
  "or %[sign], %[mantissa];"
  "or %[exponent], %[mantissa];"
  "mov %[mantissa], %[f]"
  ://output
  [f] "=r" (f)
  :
  [sign] "r" (sign),
  [exponent] "r" (exponent),
  [mantissa] "r" (mantissa)
  : //clobber
  "cc"
  );
  return f;
}
