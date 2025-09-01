/383. 赎金信
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int str[26]={0};
        for(int i=0;i<ransomNote.size();i++)
        {
            str[ransomNote[i]-'a']--;
        }
        for(int i=0;i<magazine.size();i++)
        {
            str[magazine[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(str[i]<0)
            {
                return false;
            }
        }
        return true;
    }
};
