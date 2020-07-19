#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<iostream>
#include<string.h>
#include"fraction.h"
template<typename T> class matrix;
template<typename T> class matrix_iterator;
template<typename T>
class matrix{
public:
        matrix<T>(){}
        matrix<T>(int size);
        std::vector<T>& operator[] (int i);

        T det(); // Warning this operation is O(N!).
        int get_size() const ;
        T get(int i,int j) const;
        matrix<T> get_submatrix(int i,int j);
        matrix<T> operator+(matrix<T> y);
        matrix<T> operator-(matrix<T> y);
        matrix<T> operator*(matrix<T> y);
        matrix_iterator<T> begin();
        matrix_iterator<T> end();
        operator std::string() const {
                std::string result;
                for(int i=0;i<(*this).size;i++){
                        result += "|";
                        for(int j=0;j<(*this).size;j++){
                                result += std::to_string((*this).get(i,j)) + " ";
                        }
                        result +=" \n";
                }
                return result;
        }
protected:
        int size;
        std::vector<std::vector<T> > data;

};
template<typename T>
class matrix_iterator{
        public :
        matrix_iterator<T>(int i,matrix<T>& data){
                (*this).i=i;
                (*this).data=data;
        }
        bool operator!=(matrix_iterator<T> f){
                return (*this).i!=f.i;
        }
        matrix_iterator<T>& operator++(){
                i++;
                return *this;
        }
        T operator*(){
                return data[i/data.get_size()][i%data.get_size()];
        }
protected:
        int i;
        matrix<T> data;
};
template class matrix<int>;
template class matrix<float>;
template class matrix<double>;
template class matrix<fraction>;
//std::ostream& operator<<(std::ostream& os,const matrix& p);
#endif //matrix.h MATRIX_H define-once preprocessor pattern.
