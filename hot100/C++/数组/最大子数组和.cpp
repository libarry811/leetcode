class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxsum=nums[0];
        int cursum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cursum<0)
            {
                cursum=nums[i];
            }
            else
            {
                cursum+=nums[i];
            }
            maxsum = max(maxsum,cursum);
        }
        return maxsum;
    }
};
