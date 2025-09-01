//1 两数之和
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		/*暴力解法
        int i, j;
		int size = nums.size();
		for (i = 0; i < size; i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return { i,j };
				}
			}
		}
		return {};
        */
        //哈希表解法
        unordered_map <int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            int neednum=target-nums[i];
            auto iter=map.find(neednum);
            if(iter!=map.end())
            {
                return {iter->second,i};
            }
            map.insert(pair<int,int>(nums[i],i));
        }
        return {};
	}
};
