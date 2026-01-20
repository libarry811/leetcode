class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector<int> maxrheight(height.size(),0);
        vector<int> maxlheight(height.size(),0);
        int size=height.size();
        int sum=0;
        int num=0;
        if(size<=2) return 0;//小于两国柱子，无法接到雨水
        for(int i=1;i<size;i++)//第一个位置已经初始化为0
        {
            maxlheight[i] = max(height[i-1],maxlheight[i-1]);
        }
        for(int i=size-2;i>=0;i--)
        {
            maxrheight[i] = max(height[i+1],maxrheight[i+1]);
        }
        for(int i=0;i<size;i++)
        {
            num=min(maxlheight[i],maxrheight[i])-height[i];
            if(num>0) sum=sum+num;
        }
        return sum;
    }
};
