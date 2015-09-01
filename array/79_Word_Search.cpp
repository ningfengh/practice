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
    bool exist(vector<vector<char> >& board, string word) {
        return false;
    }
};


int main(void)
{
	char board_char[3][4]={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	vector<vector<char> > board;
	Solution mysolution;
	string word = "ABCC";
	int i;
	for (i=0;i<3;i++)
	{
		vector<char> tmp(board_char[i],board_char[i]+4);
		board.push_back(tmp);
	}
	cout<<mysolution.exist(board,word)<<endl;	
	
}