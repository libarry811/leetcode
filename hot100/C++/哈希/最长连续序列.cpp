class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int maxlen=0;
        unordered_set<long long> myset;
        for(int i=0;i<nums.size();i++)//将nums中的所有数字插入集合
        {
            myset.insert(nums[i]);
        }
        //for(const int&num:myset)该操作没有去重，会有大量无效计算导致超时
        for(const int&num:myset)
        {
            if(myset.find(num-1)==myset.end())//未找到前一个数字，确定起始数字
            {
                int len=0;//从起始数字开始判断
                while(myset.find(num+len)!=myset.end())//找到下一个数字
                {
                    len++;
                    maxlen=max(len,maxlen);
                }
            }
        }
        return maxlen;
    }
};
