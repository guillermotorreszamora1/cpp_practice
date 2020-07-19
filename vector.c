#include<vector>
#include<iostream>
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
	vector<IntWrapper> a;
	a.insert(a.begin()+0,IntWrapper(1));
	a.insert(a.begin()+1,IntWrapper(2));
	a.push_back(IntWrapper(3));

	cout << "a" << endl;
	for(auto x : a){
		cout << x << endl;
	}

	a.pop_back();
	a.erase(a.begin());
	cout << "b" << endl;
	for(auto x : a){
		cout << x << endl;
	}

	IntWrapper b = IntWrapper(4);
	a.push_back(b);
	b.integer = 5;
	cout << "c" << endl;
	for(auto x : a){
		cout << x << endl;
	}

	a.clear();

	vector<IntWrapper*> c;
	c.push_back(&b);
	b.integer = 6;
	cout << "d" << endl;
	for(auto x : c){
		cout << *x << endl;
	}
	c[0]->integer = 7;
	cout << *(c[0]) << endl;
	
}
