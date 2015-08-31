#include <iostream>
#include <set>
using namespace std;


int main(void)
{
	set <int> myset;
	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	cout<<myset.count(4)<<endl;
	return 1;
}