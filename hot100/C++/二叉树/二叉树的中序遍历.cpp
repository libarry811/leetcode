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
    void traversal(TreeNode* cur, vector<int>& vec)//这里取地址直接操作容器
    {
        if(!cur)
        {
            return;
        }
        traversal(cur->left,vec);//左
        vec.push_back(cur->val);//中
        traversal(cur->right,vec);//右
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
