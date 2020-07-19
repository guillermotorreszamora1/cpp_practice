#include<vector>
#include<cassert>
#include<exception>
#include"matrix.h"
using namespace std;
template<typename T>
vector<T>& matrix<T>::operator[](int i){
	return data[i];
}
template<typename T>
matrix<T>::matrix(int size){
	this->size = size;
	for(int i=0;i<size;i++){
		vector<T> temp;
		for(int j=0;j<size;j++){
			temp.push_back({});
		}
		data.push_back(temp);
	}
}
template<typename T>
matrix<T> matrix<T>::get_submatrix(int x,int y){
	matrix<T> submatrix = matrix<T>(this->size-1);
	int i,j,k,l;
	for(i=0,k=0;i<this->size;i++){
		if(i==x){
			continue;
		}
		for(j=0,l=0;j<this->size;j++){
			if(j==y){
				continue;
			}
			submatrix[k][l]=(*this)[i][j];
			l++;
		}
		k++;
	}
	return submatrix;
}
template<typename T>
int matrix<T>::get_size() const{
	return this->size;
}
template<typename T>
T matrix<T>::get(int i,int j) const{
	return (*this).data[i][j];
}
template<typename T>
matrix<T> matrix<T>::operator+(matrix<T> y){
	matrix<T> result((*this).size);
	if(!((*this).size==y.size)){
		throw exception();
	}
	for(int i=0;i<(*this).size;i++){
		for(int j=0;j<(*this).size;j++){
			result[i][j] = (*this)[i][j]+y[i][j];
		}
	}
	return result;
}
template<typename T>
matrix<T> matrix<T>::operator-(matrix<T> y){
	matrix result((*this).size);
	if(!((*this).size==y.size)){
		throw exception();
	}
	for(int i=0;i<(*this).size;i++){
		for(int j=0;j<(*this).size;j++){
			result[i][j] = (*this)[i][j]-y[i][j];
		}
	}
	return result;
}
template<typename T>

matrix<T> matrix<T>::operator*(matrix<T> y){
	matrix<T> result((*this).size);//Initializes to default.0 for int.
	if(!((*this).size==y.size)){
		throw exception();
	}
	for(int i=0;i<(*this).size;i++){
		for(int j=0;j<(*this).size;j++){
			for(int k=0;k<(*this).size;k++){
				result[i][j] = result[i][j] + (*this)[i][k]*y[k][j];
			}
		}
	}
	return result;
}
template<typename T>
matrix_iterator<T> matrix<T>::begin(){
	return matrix_iterator<T>(0,*this);
}
template<typename T>
matrix_iterator<T> matrix<T>::end(){
	return matrix_iterator<T>((*this).size*(*this).size,*this);
}
/*ostream& operator<<(ostream& os,const matrix& p){
	for(int i=0;i<p.get_size();i++){
		os << "|";
		for(int j=0;j<p.get_size();j++){
			os << p.get(i,j) << " ";
		}
		os << "|" << endl;;
	}
	return os;
}*/
template<typename T>
T matrix<T>::det(){
	T sign={1};
	T det;
	if(size==1){
		return (*this)[0][0];
	}
	det = {};
	for(int i=0;i<size;i++){
		det = det+sign*(*this)[i][0]* (*this).get_submatrix(i,0).det();
		//cout << "sub" << sign*(*this)[i][0]*(*this).get_submatrix(i,0).det() << endl;
		sign = -sign;
	}
	return det;
}
