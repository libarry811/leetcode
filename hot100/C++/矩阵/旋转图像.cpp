class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int left = 0,right = matrix.size()-1;
        while(left<right)//循环条件
        {
            int top = left,down = right;
            for(int i=0;i<right-left;i++)//每次旋转right-left次
            {
                int temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[down - i][left];
                matrix[down - i][left] = matrix[down][right - i];
                matrix[down][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }
            left++;
            right--;
        }
        
    }
};
