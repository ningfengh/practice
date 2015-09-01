#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

int main(void)
{
	string str1;
	str1 = to_string(10);
	cout<<str1<<endl;
	return 1;
}