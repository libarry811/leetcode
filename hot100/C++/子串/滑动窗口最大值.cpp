class Solution {
private:
    class MyQueue{
    public:
        deque<int> que;// 使用deque来实现单调队列,双向队列，前后均可进出
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 不相等：比出口小排后面，大的将出口在push函数被弹出
        // 同时pop之前判断队列当前是否为空。
        void pop(int value)
        {
            if(!que.empty()&&value==que.front())
            {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，
        // 直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value)
        {
            while(!que.empty()&&value>que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front()
        {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {   //使用单调队列
        MyQueue que;
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            que.push(nums[i]);// 先将前k的元素放进队列
        }
        res.push_back(que.front());// result 记录前k的元素的最大值
        for(int i=k;i<nums.size();i++)
        {
            que.pop(nums[i-k]);// 滑动窗口移除最前面元素
            que.push(nums[i]);// 滑动窗口前加入最后面的元素
            res.push_back(que.front());// 记录对应的最大值
        }
        return res;
    }
};
