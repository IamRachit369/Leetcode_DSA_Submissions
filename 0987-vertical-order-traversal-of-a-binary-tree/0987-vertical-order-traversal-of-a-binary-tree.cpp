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
    map<int,vector<pair<int,int>>>mp;
    void recur(TreeNode* root, int curr, int level)
    {
        if(root == NULL) return;
        mp[curr].push_back({level,root->val});
        recur(root->left, curr - 1, level + 1);
        recur(root->right, curr + 1, level + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        recur(root, 0, 0);
        for(auto &x : mp)
        {
            sort(x.second.begin(), x.second.end());
        }
        for(auto &x : mp)
        {
            vector<int>temp;
            for(auto &y : x.second)
            {
                temp.push_back(y.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};