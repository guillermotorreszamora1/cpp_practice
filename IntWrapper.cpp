#include<iostream>
using namespace std;
class IntWrapper{
	public:
	int integer;
	IntWrapper(){

	}
	//IntWrapper(IntWrapper& y);
	//IntWrapper& operator=(IntWrapper&& y);
	//IntWrapper(IntWrapper&&);
	//IntWrapper& operator=(const IntWrapper&);
	IntWrapper(int inte) :integer{inte}{}
	IntWrapper operator+(IntWrapper y){
		IntWrapper result;
		result.integer = (*this).integer+y.integer;
		return result;
	}
	IntWrapper operator+(IntWrapper y){
		IntWrapper result;
		result.integer = (*this).integer+y.integer;
		return result;
	}
	IntWrapper operator-(IntWrapper y){
		IntWrapper result;
		result.integer = (*this).integer+y.integer;
		return result;
	}
	IntWrapper operator-(){
		IntWrapper result;
		result.integer = - (*this).integer;
		return result;
	}
	IntWrapper operator*(IntWrapper y){
		IntWrapper result;
		result.integer = (*this).integer*y.integer;
		return result;
	}
};
int main(){
	IntWrapper x(1);
	IntWrapper y(2);
	IntWrapper z(3);
	IntWrapper a;
	a = x+y*z;
	a = x+y;
	a = x+y+z;
}
