/*

[[tree]]
[[binary tree]]
[[depth first search]]
[[breadth first search]]

#referback  (solve with bfs next time)
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
    int maxDepth(TreeNode* root) {
        int res {0};
        depth(root, res);

        return res;

    }

    int depth(TreeNode* current, int& res){
        if (current == NULL) return 0;

        int left = depth(current->left, res);
        int right = depth(current->right, res);

        res = 1 + max(left, right);

        return res;
    }
};
