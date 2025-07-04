/*

My first approach is pseudo correct. I iterate with dfs on the left side and right side while putting a counter. By the time it reaches the last node, we get the depth of the subtree.

But that is wrong, since it doesn't recursively check for the sub trees of each node. This leaves it problematic, since the left most part can just end while there could be more nodes beside it deeper. So we need recursion.

The GetHeight function calculates the depth of the subtree. We give it the first left node which calculates the left height and do the same for the right. What it does it calculates recursively each left and right nodes of the node, and returns the maximum of it (thus the `max(GetHeight(node->left), GetHeight(node->right))` part) which ensures greatest depth. After that the logic is the same. There is just one more recursion in the final return.

What this part - `return isBalanced(root->left) && isBalanced(root->right);` - does is that it recursively checks the balancing for each subtree of every subtree to ensure that the entire graph is balanced.

[[binary tree]]
[[depth first search]]
[[recursion]]

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
    // bool isBalanced(TreeNode* root) {
    //     int count_left {0};
    //     TraverseLeft(root, count_left);

    //     int count_right {0};
    //     TraverseRight(root, count_right);

    //     int diff = abs(count_left - count_right);
    //     if (diff == 0 || diff ==1){
    //         return true;
    //     } else {
    //         return false;
    //     }

    // }

    // void TraverseLeft(TreeNode* node, int& count) {
    //     if (node == NULL) return;
    //     count++;
    //     TraverseLeft(node->left, count);
    // }

    // void TraverseRight(TreeNode* node, int& count) {
    //     if (node == NULL) return;
    //     count++;
    //     TraverseRight(node->right, count);
    // }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int left_height = GetHeight(root->left);
        int right_height = GetHeight(root->right);
        if (abs(left_height - right_height) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int GetHeight(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + max(GetHeight(node->left), GetHeight(node->right));
    }
};
