/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root)
        {
            que.push(root);
        }
        while(!que.empty())//队列不为空时，一直循环
        {
            int size = que.size();//记录队列的数量
            vector<int> num;
            for(int i=0;i<size;i++)
            {
                TreeNode* qnode = que.front();
                que.pop();//遍历后弹出节点
                num.push_back(qnode->val);
                if(qnode->left) que.push(qnode->left);
                if(qnode->right) que.push(qnode->right);
            }
            res.push_back(num);
        }
        return res;
    }
};
