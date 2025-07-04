/*

I basically recursed through the left and right subtrees, while comparing the current max depth of the current node with the sum of its respective left and right nodes. This way the entire tree gets searched and we end up with the max diameter since we are comapring by adding the left and right's lengths in this recursor - `res = max(res, left + right);`

[[tree]]
[[binary tree]]
[[depth first search]]

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root, res);

        return res;

    }

    int diameter(TreeNode* current, int& res) {
	    if (current == NULL) return 0;

        int left = diameter(current->left, res);
        int right = diameter(current->right, res);

        res = max(res, left + right);

        return max(left, right) + 1;
    }
};
