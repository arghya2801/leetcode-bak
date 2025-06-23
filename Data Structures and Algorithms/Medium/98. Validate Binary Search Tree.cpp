/*

For this question, the approach is inorder traversal. When we do inorder traversal on a BST, we get the result in ascending order. Once this concept clicks, the question is easy. Just add the elements of the inorder traversal to an array, and check if it is ascending or not by comparing every element with its previous one.

[[tree]]
[[binary tree]]
[[depth first search]]
[[breadth first search]]

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
    vector<int> bst_copy;
    bool isValidBST(TreeNode* root) {
        copyBST(root, bst_copy);

        for (int i = 1; i < bst_copy.size(); i++){
            if (bst_copy[i] <= bst_copy[i - 1]) return false;
        }

        return true;
    }

    void copyBST(TreeNode* root, vector<int> &bst_copy){
        if (root == NULL) return;
        if (root != NULL){
            copyBST(root->left, bst_copy);
            bst_copy.push_back(root->val);
            copyBST(root->right, bst_copy);
        }
    }
};
