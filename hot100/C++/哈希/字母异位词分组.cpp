class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        //strs每一个元素都是一个完整的 string
        unordered_map<string,vector<string>> mp;//创建map
        vector<vector<string>> ans;
        for(const string& str : strs)//遍历strs
        {
            string key = str;
            //key = sort(key.begin(),key.end());//错误写法
            sort(key.begin(),key.end());//对每个字符串进行排序
            mp[key].push_back(str);//将str添加到value中
        }
        for(auto iter = mp.begin();iter!=mp.end();iter++)
        {
            ans.push_back(iter->second);
        }
        return ans;
    }
};
