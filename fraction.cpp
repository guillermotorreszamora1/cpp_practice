#include<cmath>
#include<iostream>
#include"fraction.h"
using namespace std;
int gcd(int a,int b){
        a = abs(a);
        b = abs(b);
        if(a<b){
                int c;
                c = a;
                a = b;
                b = c;
        }
        if(b==0){
                return a;
        }
        return gcd(b,a%b);
}
void fraction::simplify(){
        int factor;
        factor = gcd((*this).den,(*this).num);
        (*this).den = (*this).den/factor;
        (*this).num = (*this).num/factor;
        if((*this).den<0){
                (*this).den = -(*this).den;
                (*this).num = -(*this).num;
        }
}
fraction fraction::operator+(fraction y){
        fraction result;
        //Compute minimum comun denominator.
        int gcd_ = gcd((*this).den,y.den);
        int mcd = (*this).den/gcd_*(y.den);
        result.den = mcd;
        result.num = y.den/gcd_*(*this).num+(*this).den/gcd_*y.num;
        result.simplify();
        return result;
}

fraction fraction::operator-(fraction y){
        fraction result;
        //Compute minimum comun denominator.
        int gcd_ = gcd((*this).den,y.den);
        int mcd = (*this).den/gcd_*(y.den);
        result.den = mcd;
        result.num = y.den/gcd_*(*this).num-(*this).den/gcd_*y.num;
        result.simplify();
        return result;
}
fraction fraction::operator-(){
        fraction result;
        result.den =(*this).den;
        result.num = -(*this).num;
        return result;
}
fraction fraction::operator*(fraction y){
        fraction result;
        result.den = (*this).den*y.den;
        result.num = (*this).num*y.num;
        result.simplify();
        return result;
}
fraction::fraction(){
        (*this).num=0;
        (*this).den=1;
}
fraction::fraction(int i){
        (*this).num=1;
        (*this).den=1;
}
namespace std{
        string to_string(fraction f){
                return f.num + "/" +f.den;

        }
}
