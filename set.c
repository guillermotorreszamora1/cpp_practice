#include<iostream>
#include<set>
using namespace std;
class IntWrapper{
	public:
	int integer;
	IntWrapper(int inte) :integer{inte}{}
	friend const bool operator<(const IntWrapper& l,const IntWrapper& r){
		return l.integer>r.integer;
	}
};
ostream& operator<<(ostream& os,const IntWrapper& p){
	return os << p.integer;
}
auto IntWrapper_less =[](const IntWrapper& l,const IntWrapper& r){return l<r;};
int main(){
	set<IntWrapper,decltype(IntWrapper_less)> f = set<IntWrapper,decltype(IntWrapper_less)>(IntWrapper_less);
	f.insert({3});
	f.insert({4});
	for(auto x: f){
		cout << x;
	}
}

