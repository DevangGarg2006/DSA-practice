/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* root, int k, bool &flag,unordered_set<int> &mp) {
        if (!root|| flag) {
            return ;
        }
        check(root->left,k,flag,mp);
        if(mp.count(k-root->val)){
            flag=true;
            return;
        }
        mp.insert(root->val);
        check(root->right,k,flag,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        bool flag = false;
        unordered_set<int> mp;
        check(root, k, flag,mp);
        return flag;
    }
};