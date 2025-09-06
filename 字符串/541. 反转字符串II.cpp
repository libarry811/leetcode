class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int i;
        int x,y;
        for(i=0;i<s.size();i+=2*k)
        {
            if(i+k<s.size())
            {
                //reverse(s.begin()+i,s.begin()+i+k);//左闭右开区间
                for(x=i,y=i+k-1;x<y;x++,y--)
                {
                    swap(s[x],s[y]);
                }
            }
            else
            {
                //reverse(s.begin()+i,s.end());
                for(x=i,y=s.size()-1;x<y;x++,y--)
                {
                    swap(s[x],s[y]);
                }
            }
        }
        return s;
    }
};
