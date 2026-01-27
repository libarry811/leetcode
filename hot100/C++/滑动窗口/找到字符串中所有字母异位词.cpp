class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> res;
        vector<int> count(26);//记录p每个字母出现的次数
        vector<int> curcount(26);//记录窗口每个字母出现的次数
        if(s.size()<p.size()) return res;
        for(int i=0;i<p.size();i++)
        {
            count[p[i]-'a']++;
        }
        for(int i=0;i<p.size()-1;i++)//让当前窗口比p小1，在下一步直接构建成功窗口
        {
            curcount[s[i]-'a']++;
        }
        int left=0;
        int right=0;
        for(left=0,right=p.size()-1;right<s.size();left++,right++)
        {
            curcount[s[right]-'a']++;
            if(count==curcount)
            {
                res.push_back(left);
            }
            curcount[s[left]-'a']--;
        }
        return res;
    }
};
