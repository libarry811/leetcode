class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> uset;
        int res=0;//最终窗口长度
        int cur=0;//现窗口长度
        int left=0;
        int right=0;
        for(right=0;right<s.size();right++)
        {
            while(left<right&&uset.count(s[right])==1)//先判断是否再集合，再决定是否插入集合
            {
                uset.erase(s[left]);//出现已有元素时，窗口缩短左边至没有重复元素
                cur--;
                left++;
            }
            uset.insert(s[right]);
            cur++;
            res=max(res,cur);
        }
        return res;
    }
};
