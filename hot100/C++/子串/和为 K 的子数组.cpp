class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        /*
        y1=x1
        y2=x1+x2
        ...
        ym=x1+x2+...+xm
        ...
        yn=x1+x2+...+xm+...+xn
        yn-ym=k <=> xm+1 + xm+2 + ... xn = k,即数组中和为 k 的子数组
        寻找yn-k的值是否为ym
        */
        unordered_map<int,int> umap;//key为前缀和，value为出现次数
        int res=0;
        int pre=0;
        umap[pre]=1;//初始化前缀和为0的次数为1，判断前缀和=k的情况
        for(int i=0;i<nums.size();i++)
        {
            pre=pre+nums[i];
            auto iter=umap.find(pre-k);
            if(iter!=umap.end())//在map里找到已存入前缀和
            {
                res+=umap[pre-k];//加上前缀和出现的次数
            }
            umap[pre]+=1;//插入本次遍历的前缀和及次数
        }
        return res;
    }
};
