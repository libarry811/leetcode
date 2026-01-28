class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        if(intervals.size()==0) return res;
        // 排序的参数使用了lambda表达式
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b) {return a[0]<b[0];});//a左端点小于b左端点，返回true，a排b前面
        // 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(res.back()[1]>=intervals[i][0])// 发现重叠区间.前一个区间右边界》后一个区间左边界
            {
                // 合并区间，只更新右边界就好，因为result.back()的左边界一定是最小值，
                //因为我们按照左边界排序的
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);// 区间不重叠 
            }
        }
        return res;
    }
};
