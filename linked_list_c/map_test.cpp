#include <iostream>
#include <map>
using namespace std;


int main(void)
{
	map <int,int> mymap;
	mymap[1]=2;
	mymap[2]=3;
	mymap[3]=4;
	cout<<mymap.count(2)<<endl;
	return 1;
}