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
    bool recur(TreeNode* root, long long minVal, long long maxVal)
    {
        if(root == NULL) return true;
        if(root->val > minVal && root->val < maxVal)
        {
            return recur(root->left, minVal, min((long long)root->val,maxVal)) & recur(root->right, max((long long)root->val,minVal), maxVal);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return recur(root, LLONG_MIN, LLONG_MAX);
    }
};