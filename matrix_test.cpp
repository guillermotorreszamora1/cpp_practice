#include<iostream>
#include<exception>
#include"matrix.h"
using namespace std;
int main(){
        matrix<int> m(3);
        m[1][2]=2;
        cout << m[1][2] << endl;
        int k=1;
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        m[i][j]=k;
                        k++;
                }
        }
        cout << (string)m << endl;
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        cout << "("<<i<<","<<j<<")" << endl;
                        cout << static_cast<string>(m.get_submatrix(i,j)) << endl;
                }
        }
        matrix<int> x(4);
        matrix<int> z(3);
        try{
                z = m+x;
        }catch(exception& e){
                cout << "Excepcion" << endl;
        }
        x = matrix<int>(3);
        matrix<int> y(3);
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        x[i][j]=1;
                        y[i][j]=i+j;
                }
        }
        z = x+y;
        cout << (string)x << endl;
        cout << (string)y << endl;
        cout << (string)z << endl;
        z = x-y;
        cout << "resta" << (string)z << endl;
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        x[i][j]=i+(i+1)*(j+1);
                        y[i][j]=(i+1)*(j+1)*10;
                }
        }
        z = x*y;
        cout << (string)x << endl;
        cout << (string)y << endl;
        cout << "multiplicacion" << endl << (string)z << endl;
        for(auto number: z){
                cout << number << endl;
        }
        cout << m.det() << endl;
        cout << x.det() << endl;
        matrix<fraction> a(3);
        matrix<fraction> b(3);
        matrix<fraction> c(3);
        c = a+b;
        c = a-b;
        c = a*b;
}
