#include<iostream>
#include<stack>
using namespace std;
class IntWrapper{
	public:
	int integer;
	IntWrapper(int inte) :integer{inte}{}
};
ostream& operator<<(ostream& os,const IntWrapper& p){
	return os << p.integer;
}
int main(){
	stack<IntWrapper> a;
	a.push({2});
	a.push({3});
	a.push({4});
	cout << a.top();
	a.pop();
	cout << a.top();
}
