class Solution {
public:
    void reverse(string &s,int start,int end)
    {
        int i,j;
        for(i=start,j=end;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }

    void removeExtraSpaces(string& s) 
    {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int fast=0;
        int slow=0;
        for(fast=0;fast<s.size();fast++)
        {
             //遇到非空格就处理，即删除所有空格。
            if(s[fast]!=' ')
            {
                //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格
                if(slow!=0)
                {
                    s[slow]=' ';
                    slow++;
                }
                //补上该单词，遇到空格说明单词结束。
                while(fast<s.size()&&s[fast]!=' ')
                {
                    s[slow]=s[fast];
                    fast++;
                    slow++;
                }
            }
        }
        s.resize(slow);
    } 
    string reverseWords(string s) 
    {
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);
        int start=0;
        for(int i=0;i<=s.size();i++)
        {
            if(i==s.size()||s[i]==' ')
            {
                reverse(s,start,i-1);
                start=i+1;
            }
        }
        return s;
    }
};
