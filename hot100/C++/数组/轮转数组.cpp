class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        //先将数组翻转，之后前k个元素为一组，剩下元素为一组，分别翻转即可得到结果（证明略）
        k = k%nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
    void reverse(vector<int>& nums, int left, int right)
    {
        while(left<right)
        {
            int temp=nums[right];
            nums[right]=nums[left];
            nums[left]=temp;
            right--;
            left++;
        }
    }
};
