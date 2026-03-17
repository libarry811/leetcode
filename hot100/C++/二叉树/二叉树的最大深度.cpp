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
    int getdepth(TreeNode* cur)//后续遍历得到根节点的高度就是二叉树的深度
    {
        if(!cur)
        {
            return 0;//确定递归终止条件
        }
        int leftdep = getdepth(cur->left);
        int rightdep = getdepth(cur->right);
        int maxdep = 1+max(leftdep,rightdep);//遍历完左右后遍历父节点高度加一
        return maxdep;
    }
    int maxDepth(TreeNode* root) 
    {
        return getdepth(root);
    }
};
