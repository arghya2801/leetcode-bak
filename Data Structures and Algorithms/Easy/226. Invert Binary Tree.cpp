/*

I basically did a recursion over here. The recursive process reaches till the end of the tree at the leaf nodes. Then, the root over there swaps the leaves, which there aren't any. Recursively, it keeps going up backward till it reaches the original root swapping the nodes.

Note that the topic section of leetcode did not mention [[recursion]], which has me slightly worried that my solution isn't the correct one, but it works so it should be correct regardless.

[[depth first search]]
[[breadth first search]]
[[tree]]
[[binary tree]]

#referback
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL){
            return NULL;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};
