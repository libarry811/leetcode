class Solution {
public:
    void setZeroesline(vector<vector<int>>& matrix,int line)
    {
        int num=matrix[line].size();
        vector<int> v(num,0);
        matrix[line]=v;
    }
    void setZeroesrow(vector<vector<int>>& matrix,int row)
    {
        for(int i=0 ;i<matrix.size();i++)
        {
            matrix[i][row]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int i,j;
        int flag=1;
        int line=matrix.size();//记录行数
        int row=matrix[0].size();//记录列数
        vector<int> m(line,0);//行数组
        vector<int> n(row,0);//列数组
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    m[i] = flag;
                    n[j] = flag;
                }
            }
        }
        for(int s=0;s<line;s++)
        {
            if(m[s]==flag)
            {
                setZeroesline(matrix,s);
            }
        }
        for(int s=0;s<row;s++)
        {
            if(n[s]==flag)
            {
                setZeroesrow(matrix,s);
            }
        }
    }
};
