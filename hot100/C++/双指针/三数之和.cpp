class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以
            if(nums[i]>0)
            {
                //break;
                return result;
            }
            // 正确去重a方法
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(right>left)
            {
                if(nums[left]+nums[right]+nums[i]>0)
                {
                    right--;
                }
                else if(nums[left]+nums[right]+nums[i]<0)
                {
                    left++;
                }
                else
                {
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while(nums[right]==nums[right-1]&&right!=left)
                    {
                        right--;
                    }
                    while(nums[left]==nums[left+1]&&right!=left)
                    {
                        left++;
                    }
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};
