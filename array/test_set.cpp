#include <iostream>
#include <set>
using namespace std;


int main(void)
{
	set <int> test;
	test.insert(1);
	test.insert(1);
	cout<<test.size();
	
	return 1;
}