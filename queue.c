#include<iostream>
#include<queue>
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
	queue<IntWrapper> a;
	a.push({2});
	a.push({3});
	a.push({4});
	cout << a.front();
	a.pop();
	cout << a.front();
}
