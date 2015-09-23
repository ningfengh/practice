#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string str1 = "hello";
	string str2;
	str2+=str1[2];
	str2+=str1[4];
	cout<<str2<<endl;

}