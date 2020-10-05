#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Complex
{
    double real, imag;
    public:
        Complex(double r=0, double i=0):real(r), imag(i){};
        ostream& operator <<(ostream& os, const Complex &c);
}
