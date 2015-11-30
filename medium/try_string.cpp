#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
	string a = "123456*12341+123+11-123";
	string b = "+-*/";
	int i;
	int aa;
	vector <int> nums;
	vector <char> op;
	while (1){
		i = strcspn(a.c_str(),b.c_str());
		if (i==a.size()) break;
		aa =stoi (a.substr(0,i),nullptr,10);
		op.push_back(a[i]);
		nums.push_back(aa);
		a = a.substr(i+1,a.size()-i-1);
	}
	aa =stoi (a.substr(0,i),nullptr,10);
	nums.push_back(aa);

}