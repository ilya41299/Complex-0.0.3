#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

struct complex_t {
 public:
  complex_t() {
    real = 0.0f;
    imag = 0.0f;
  }
  complex_t add(complex_t other) const  // complex_t * const
  {
    complex_t result;
    result.real = this->real + other.real;  // this
    result.imag = this->imag + other.imag;
    return result;
  }

  complex_t sub(complex_t other) const {
    complex_t result;
    result.real = this->real - other.real;  // this
    result.imag = this->imag - other.imag;
    return result;
  }

  complex_t mul(complex_t other) const {
    complex_t result;
    result.real = this->real * other.real - this->imag * other.real;  // this
    result.imag = this->imag * other.real + this->real * other.imag;
    return result;
  }

  complex_t div(complex_t other) const {
    complex_t result;
    result.real = (this->real * other.real + this->imag * other.imag) /
                  (other.real * other.real + other.imag * other.imag);
    result.imag = (this->imag * other.real - this->real * other.imag) /
                  (other.real * other.real + other.imag * other.imag);
    return result;
  }

  ostream& output(std::ostream& stream) const {
    return stream << '(' << real << ", " << imag << ')';
  }

  istream& read(std::istream& stream) {
    char sk1, sk2, zpt;
    float value1, value2;
    if (stream >> sk1 && sk1 == '(' && stream >> value1 && stream >> zpt &&
        zpt == ',' && stream >> value2 && stream >> sk2 && sk2 == ')') {
      set_real(value1);
      set_imag(value2);
    }
    return stream;
  }

  ~complex_t() {}

  void set_real(float value) { real = value; }

  void set_imag(float value) { imag = value; }

 private:
  float imag;
  float real;
};

int main() {
  complex_t complex1;
  string stroka;
  getline(cin, stroka);
  istringstream stream(stroka);
  if (complex1.read(stream)) {
    complex_t complex2;
    char op;
    if (stream >> op) {
      if (complex2.read(stream)) {
        switch (op) {
          case '+': {
            complex_t result = complex1.add(complex2);
            result.output(cout);
            break;
          }
          case '-': {
            complex_t result = complex1.sub(complex2);
            result.output(cout);
            break;
          }
          case '*': {
            complex_t result = complex1.mul(complex2);
            result.output(cout);
            break;
          }
          case '/': {
            complex_t result = complex1.div(complex2);
            result.output(cout);
            break;
          }
          default:
            cout << "An error has occured while reading input data";
            break;
        }
      } else
        cout << "An error has occured while reading input data";

    } else
      cout << "An error has occured while reading input data";
  } else
    cout << "An error has occured while reading input data";
  return 0;
}
