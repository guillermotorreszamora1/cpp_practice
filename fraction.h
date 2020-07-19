#ifndef FRACTION_H
#define FRACTION_H
#include<string.h>
class fraction{
public:
        fraction();
        fraction(int i);
        fraction operator+(fraction y);
        fraction operator-(fraction y);
        fraction operator-();
        fraction operator*(fraction y);
        void simplify();
        int den;
        int num;
};
namespace std{
        string to_string(fraction f);
}
#endif
