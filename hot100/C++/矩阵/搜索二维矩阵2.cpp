class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int line = matrix.size();
        int row = matrix[0].size();
        int left = 0,right = row-1;
        int i=0;
        for(i=0;i<line;i++)
        {
            left = 0,right = row-1;
            if(target<=matrix[i][row-1])//比每行最后遥感元素小，才看这一行
            {
                while(left<=right)
                {
                    int middle = (left+right)/2;
                    int num = matrix[i][middle];
                    if(target<num)
                    {
                        right = middle-1;
                    }
                    else if(target>num)
                    {
                        left = left + 1;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
