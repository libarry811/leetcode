class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> mapt;//统计t中字符出现次数
        unordered_map<char,int> mapw;//统计字串字符出现次数
        int left=0;
        int right=0;
        int have=0;//字串每包含t中一个字符，have+1
        int resstart = 0;
        int reslen = INT_MAX;
        if(s.size()<t.size()||s.size()==0||t.size()==0) return "";
        for(int i=0;i<t.size();i++)
        {
            mapt[t[i]]++;//统计t中字符出现次数
        }   
        int count=mapt.size();
        while(right<s.size())
        {
            if(mapt.count(s[right]))//如果该字符存在于t中
            {
                mapw[s[right]]++;
                if(mapt[s[right]] == mapw[s[right]])//有一个字符出现频率相等，确保不统计重复字符
                {
                    have++;
                }
            }
            while(have==count)
            {
                if(right-left+1<reslen)//如果当前窗口小于结果长度
                {
                    reslen = right-left+1;//更新结果长度
                    resstart = left;// 记录起点
                }
                if(mapt.count(s[left]))
                {
                    mapw[s[left]]--;
                    if(mapt[s[left]] > mapw[s[left]])
                    {
                        have--;
                    }
                }
                left++;
            }
            right++;
        }
        if(reslen == INT_MAX) return "";
        return s.substr(resstart,reslen);
    }
};
