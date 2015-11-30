class Solution {
public:
    int trap(vector<int>& height) {
		int left,right,sum;
		if (height.size()<=2) return 0;
		else 
		{
			left = 0;
			right = 1;
			sum = 0;
			while (right<height.size()-1)
			{
				if (height[right]>=height[left])
				{
					left = right;
					right++;
				}
				else
				{
					sum += height[left]-height[right];
					right++;
				}
			}
			if (height[right]<height[left])
				while (height[right]<height[right-1])
				{
					right--;
					sum-= height[left]-height[right];
				}
				for (int i=right-1;i>left;i--)
				{
					if (height[i]>height[right]) right = i;
					sum-= height[left]-height[right];
					sum+=max(0,height[i]-height[right]);
				}
			return sum;
		}
		
    }
};