#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

/*
based on 2sum, 

*/
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
  vector<vector<int> > fourSum(vector<int>& nums, int target)  {
		vector<vector<int> > result;
		int length = nums.size();
		if (length<4) return result;
		sort(nums.begin(),nums.end());
		
		int i_out = 0, i=1,j=length-2, j_out = length-1;
		int flag=0;
		int target_in;
		int i_out1,i_out_origin;
		while (i_out<j_out-2)
		{
			target_in = target-nums[i_out]-nums[j_out];
			/*
			while (nums[j_out-1]+nums[j_out-2]<target_in&&i_out<j_out-2)
			{
				i_out++;
				target_in = target-nums[i_out]-nums[j_out];
				//cout<<i_out<<" "<<i<<" "<<j<<" "<<j_out<<endl;
			}
			while (nums[i_out+1]+nums[i_out+2]>target_in&&i_out<j_out-2)
			{
				j_out--;
				target_in = target-nums[i_out]-nums[j_out];
				//cout<<i_out<<" "<<i<<" "<<j<<" "<<j_out<<endl;
			}
			*/
			i = i_out+1;
			j = j_out-1;
			while (i<j)
			{
				//cout<<i_out<<" "<<i<<" "<<j<<" "<<j_out<<endl;
				if (nums[i]+nums[j]==target_in)
				{
					vector<int> tmp;
					//cout<<i_out<<" "<<i<<" "<<j<<" "<<j_out<<endl;
					tmp.push_back(nums[i_out]);
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					tmp.push_back(nums[j_out]);
					result.push_back(tmp);
					//cout<<"check  "<<nums[i_out]<<" "<<nums[i]<<" "<<nums[j]<<" "<<nums[j_out]<<endl;

					while (nums[i+1]==nums[i]&&i<j) i++;
					while (nums[j-1]==nums[j]&&i<j) j--;
					i++;
					j--;
				}
				else if (nums[i]+nums[j]>target_in)
				{

					while (nums[j-1]==nums[j]&&i<j) j--;
					j--;
				}
				else 
				{

					while (nums[i+1]==nums[i]&&i<j) i++;
					i++;
				}	
			}
			//cout <<i_out<<" "<<j_out<<endl;
			if (flag==0)
			{
				i_out_origin = i_out;
				while (nums[i_out+1]==nums[i_out]&&i_out<j_out-2) i_out++;
				i_out++;
				flag = 1;
			}		
			else if(flag==1)
			{
				i_out1 = i_out;
				i_out = i_out_origin;
				while (nums[j_out-1]==nums[j_out]&&i_out<j_out-2) j_out--;
				j_out--;
				flag = 2;				
			}
			else 
			{
				i_out = i_out1;
				flag = 0;
			}
			//cout<<i_out<<" "<<j_out<<endl;
			
		}
		
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	//int in[]={-3,-1,0,2,4,5};
	//int in[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
	int in[]= 
	int i;
	int length = sizeof(in)/sizeof(*in);
	
	vector<int> input(in,in+length);
	vector<vector<int> > output;
	output= mysolution.fourSum(input,2);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}