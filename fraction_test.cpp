#include<iostream>
#include"fraction.h"
using namespace std;
int main(){
        fraction a;
        fraction b;
        fraction c;
        a.num=1;
        a.den=2;
        b.num=7;
        b.den=3;// 3/6+ 14/6 == 17/6
        c = a + b;
        cout << c.num << "/" << c.den << endl;
        // 2 3 5 7 11
        a.num=3;
        a.den=35;
        b.num=2;
        b.den=-77;
        c = a + b;//3/35+2/77 == 33/385 + 10/385 = 43
        cout << c.num << "/" << c.den << endl;
        c = a -b;
        cout << c.num << "/" << c.den << endl;
        c = -c;
}
