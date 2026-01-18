class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int l=0;//左指针
        int r=height.size()-1;//右指针
        int maxarea=0;
        int area=0;
        while(l<r)
        {
            area=(r-l)*min(height[l],height[r]);//求容器的容量
            maxarea=max(area,maxarea);
            if(height[l]<height[r])//确保每次移动只移动短边
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxarea;
    }
};
