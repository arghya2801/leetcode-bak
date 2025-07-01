/*
An interesting question, good to refresh memory of how DFS works. Basically a dfs(root->left) and dfs(root->right) along with any other parameter like a 'pass by reference' vector in this case which we were to modify.

Basically find the leaf node by checking if the children are NULL, and then add it to the vector. Compare the vectors for the two trees and there is the answer.
 */

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_value_sequence_1;
        vector<int> leaf_value_sequence_2;

        dfs(root1, leaf_value_sequence_1);
        dfs(root2, leaf_value_sequence_2);

        return (leaf_value_sequence_1 == leaf_value_sequence_2);
        
    }

    void dfs(TreeNode* root, vector<int> &leaf_value_sequence ) {

        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            leaf_value_sequence.push_back(root->val);
        }

        dfs(root->left, leaf_value_sequence);
        dfs(root->right, leaf_value_sequence);
    }
};
