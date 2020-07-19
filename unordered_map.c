#include<iostream>
#include<unordered_map>
using namespace std;
class IntWrapper{
	public:
	int integer;
	IntWrapper(int inte) :integer{inte}{}
	
};
ostream& operator<<(ostream& os,const IntWrapper& p){
	return os << p.integer;
}
//auto IntWrapper_hash(const IntWrapper& r){
//	return hash<int>()(r.integer);
//}
auto IntWrapper_hash = [](const IntWrapper& r){return hash<int>()(r.integer);};
//auto IntWrapper_equal(const IntWrapper& l,const IntWrapper& r){
//	return l.integer==r.integer;
//}
auto IntWrapper_equal = [](const IntWrapper& l,const IntWrapper& r){return l.integer==r.integer;};
int main(){
	unordered_map<IntWrapper,IntWrapper,decltype(IntWrapper_hash),decltype(IntWrapper_equal)> my_map(0,IntWrapper_hash,IntWrapper_equal);
	//my_map[IntWrapper(2)]=IntWrapper(3);
	my_map.insert({IntWrapper(2),IntWrapper(3)});
	cout << my_map.at({2});
	for(auto x: my_map){
		cout << x.first << x.second << endl;
	}
	my_map.at({2})={4};
	//my_map.at({3})={5}; error out of range
	cout << my_map.count({3});
	for(auto x: my_map){
		cout << x.first << x.second << endl;
	}
}
