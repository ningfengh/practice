#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string a = "hello world!";
	string b ="ab";
	string c = "aa";
	sort(a.begin(),a.end());
	cout<<a<<endl;
	cout<<(b>c)<<endl;
}