class Solution {
public:
void swap(vector<int>& nums,int a,int b)
    {
        int temp;
        temp= nums[a];
        nums[a]=nums[b];
        nums[b]= temp;
    }
    int firstMissingPositive(vector<int>& nums) 
    {//将数组视为哈希表，哈希映射规则：把i放在下标i-1上
        for(int i=0;i<nums.size();i++)
        {
            //交换后i位置元素不知道，持续交换直至nums[i]-1位置上的元素=nums[i]
 /*比如 nums = [3,1,2]，len=3，i=0 时：
初始 nums[0]=3，满足 1<=3<=3，且 nums[3-1]=nums[2]=2 !=3 → 进入 swap，交换nums[0]和nums[2]，数组变成 [2,1,3]；
交换后还在 while 循环中，重新判断：nums[0]=2，满足1<=2<=3，且nums[2-1]=nums[1]=1 !=2 → 继续 swap，交换nums[0]和nums[1]，数组变成 [1,2,3]；
交换后再判断：nums[0]=1，满足1<=1<=3，但nums[1-1]=nums[0]=1 ==1 → 第三个条件不满足，退出 while 循环；
后续 i=1、i=2 时，数都在正确位置，无需交换，最终遍历检查返回3+1=4，结果正确。*/
            while(nums[i]>=1&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i])
            {
                swap(nums,i,nums[i]-1);
            }
        } 
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=i+1)
                {
                    return i+1;
                }

            }
        return nums.size()+1;
    } 
};
