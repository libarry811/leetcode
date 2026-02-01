class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res(nums.size(),1);//初始化为1
        int pro=1;//定义前缀积
        for(int i=0;i<nums.size();i++)
        {
            res[i] = pro;//对应位置记录前缀积
            pro = pro*nums[i];//计算下一个位置的前缀积
        }
        int post=1;//定义后缀积
        int temp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            temp = res[i];
            res[i] = post*res[i];
            post = post*nums[i];
        }
        return res;
    }
};
