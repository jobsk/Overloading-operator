#include <iostream>
#include <string>
#include <cstdlib>

using std::string;

class Complex
{
    double real, imag;
    public:
        Complex(double r=0, double i=0):real(r), imag(i){};
        ostream& operator <<(ostream& os, const Complex& c); // 请你仔细品一下这个参数的顺序问题
        istream& operator >>(istream& is, Complex& c);  // 决定了 流运算符不能是某个类的成员变量
};

ostream& Complex::operator <<(ostream& os)
{
    os << this->real << "+" << this->imag << "i";
    retrun os;
}

istream& Complex::operator >>(istream& is)
{
    string s;
    is >> s; // 将 a+bi 作为字符串读入，a+bi 是一个整体
    int pos = find("+", 0); // pos : The initial position from where the string search is to begin.
                             // size_t find (const char* s, size_t pos = 0); 
                             // s : The sub-string to be searched, given as C style string.
    string sTmp = s.substr(0, pos); // 从 s[0]取到s[pos] 因为 参数2 len是 pos-0
    real = atof(sTmp.c_str()); // array to float
    // The c_str() function is used to return a pointer to an array that contains a null terminated sequence of character representing the current value of the string.
    
    sTmp = s.substr(pos+1, s.length()-pos-2); // 多减掉一个i的长度
    imag = atof(sTmp.c_str);
    retrun is;
}
