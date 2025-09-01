/第454题.四数相加II
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
       unordered_map <int,int> map;
       int size=nums1.size();
       int result=0;
       int A,B,C,D;
       for(int a=0;a<size;a++)
       {
            A=nums1[a];
            for(int b=0;b<size;b++)
            {
                B=nums2[b];
                map[A+B]++;
            } 
       }
       for(int c=0;c<size;c++)
       {
            C=nums3[c];
            for(int d=0;d<size;d++)
            {
                D=nums4[d];
                int neednum=0-(C+D);
                auto iter=map.find(neednum);
                if(iter!=map.end())
                {
                    result=result+map[0-(C+D)];
                }
            }
       }
       return result;
    }
};
