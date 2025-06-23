/*

Okay this was a pretty easy question which I wasn't able to solve. My logic was sound, and it failed at one of the submission test cases. I did an inorder traversal while adding the values to an array. Then comparing the arrays to check if they are the same.

A much easier approach was to directly compare thre trees. If p and q are equal, recurse with both their lefts and rights. The line I wrote for this is basically returning an equation for which both left and right are true.

[[tree]]
[[depth first search]]
[[breadth first search]]
[[binary tree]]
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;

        // vector<int> p_values;
        // dfs(p, p_values);

        // vector<int> q_values;
        // dfs(q, q_values);

        // if (p_values.size() != q_values.size()) return false;

        // for (int i = 0; i < p_values.size(); i++){
        //     if (p_values[i] != q_values[i]) return false;
        // }

        // return true;
    }

    // void dfs(TreeNode* r, vector<int> &r_values){
    //     if (r == NULL) {
    //         r_values.push_back(NULL);
    //         return;
    //     }

    //     r_values.push_back(r->val);
    //     dfs(r->left, r_values);
    //     dfs(r->right, r_values);
    // }
};
