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
    bool compare(TreeNode* Tleft,TreeNode*Tright)
    {
        if(!Tleft&&!Tright)
        {
            return true;//如果两个都为空，对称
        }
        else if(!Tleft||!Tright)
        {
            return false;//如果只有一个为空，不对称
        }
        else if(Tleft->val!=Tright->val)
        {
            return false;//两棵子树根节点值不同，不对称
        }
        bool inside = compare(Tleft->right,Tright->left);//比较内部
        bool outside = compare(Tleft->left,Tright->right);//比较外部
        bool issame = outside&&inside;
        return issame;
    }
    bool isSymmetric(TreeNode* root) //比较左右两颗二叉树
    {
        return compare(root->left,root->right);
    }
};
