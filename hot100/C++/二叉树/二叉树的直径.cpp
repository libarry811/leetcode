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
    // 递归函数：返回当前节点的最大深度，同时更新全局最大直径res
    int maxDepth(TreeNode* root, int &res)
    {
        if(!root) return 0; // 空节点深度为0
        
        // 递归求左右子树的最大深度
        int left = maxDepth(root->left, res);
        int right = maxDepth(root->right, res);
        
        // 关键：以当前节点为中间点的路径长度 = 左深度 + 右深度
        // 如果这个路径比当前res大，更新res
        res = max(res, left + right);
        
        // 返回当前节点的最大深度（用于父节点计算）
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res = 0; // 全局最大直径
        maxDepth(root, res); // 递归遍历所有节点，更新res
        return res;
    }
};
