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
    int solve(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh = leftHt(root);
        int rh = rightHt(root);
        
        if(lh==rh) return (1<<lh) - 1;
        
        return 1 + solve(root->left) + solve(root->right);
    }
    int leftHt(TreeNode* node) {
        int count = 0;
        while(node) {
            count++;
            node = node->left;
        }
        return count;
    }
    int rightHt(TreeNode* node) {
        int count = 0;
        while(node) {
            count++;
            node = node->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};