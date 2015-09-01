#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
    }
};


int main(void)
{


	
	

}