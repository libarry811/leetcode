class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        int line=matrix.size();
        int row=matrix[0].size();
        int up=0,down=line-1,left=0,right=row-1;
        int i=0;
        int j=0;
        while(true)
        {
            for(i=left;i<=right;i++)
            {
                res.push_back(matrix[up][i]);
            }
            up++;
            if(up>down) break;
            for(i=up;i<=down;i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left>right) break;
            for(i=right;i>=left;i--)
            {
                res.push_back(matrix[down][i]);
            }
            down--;
            if(up>down) break;
            for(i=down;i>=up;i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            if(left>right) break;
        }
        
        return res;
    }
};
