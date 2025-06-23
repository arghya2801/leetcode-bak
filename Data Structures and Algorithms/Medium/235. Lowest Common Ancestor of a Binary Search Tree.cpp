/*

This was an interesting question with a simple solution. I traverse through the tree using dfs, and then add the nodes to a vector array for both targets in separate vectors. This was the tricky part. This makes the path arrays.

For this, I also checked if  `node->left` and `node->right` existed or not, otherwise the dfs will count them as well which would cause issues. This was the note worthy part for this question.

Once done with the path arrays, I put them in a basic for loop and compare each element. If the elements are same, I update a variable with it. This is the current LCA. Once the paths split(1-2-4-3 and 1-2-4-5) I break the loop, thus the LCA being the previous common node in the path.

I am still not good with recursion at this point.

[[binary tree]]
[[binary search]]
[[tree]]
[[depth first search]]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        Traverse(root, p, path_p);
        Traverse(root, q, path_q);

        int min_size = min(path_p.size(), path_q.size());

        TreeNode* LCA = NULL;

        for (int i=0; i<min_size; i++){
            if (path_p[i] == path_q[i]){
                LCA = path_p[i];
            } else {
                break;
            }
        }

        return LCA;
    }

    bool Traverse(TreeNode* node, TreeNode* target, vector<TreeNode*>& path) {
	    if (node == NULL) return false;
	    path.push_back(node);
	    if (node == target) return true;
	    if (Traverse(node->left, target, path) || Traverse(node->right, target, path)) return true;
	    path.pop_back();
	    return false;
    }
};
