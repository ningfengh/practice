class Solution {
public:
	int findMin(vector<int>& nums,int begin,int end, int& length) {
		//cout<<begin<<" "<<end<<endl;
		if (end-begin==1)
			if (nums[end]>nums[begin]) return nums[begin];
		    else return nums[end];
		int mid = (end+begin)/2;
		
		if (nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1]) return nums[mid];
		else return min(findMin(nums,mid,end,length),findMin(nums,begin,mid,length));
			
	}
    int findMin(vector<int>& nums) {
        int length = nums.size();
		if (length==1) return nums[0];
		return findMin(nums,0,length-1,length);

    }
};