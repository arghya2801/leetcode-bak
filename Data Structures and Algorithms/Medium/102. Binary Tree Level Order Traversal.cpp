/*

This was an easy question, but a good one to practice queues.

First we add the root to the queue. This will be level one. Then we create a vector called 'level'. This will basically create the arrays of each level as asked in the question. To make sure this doesn't print the entire queue directly, we iterate from 0 to the size of the queue. This way, we by the time we are done with a given level, the elements of the queue will have been popped out, hence giving us an array with only elements of that particular level.

[[tree]]
[[binary tree]]
[[breadth first search]]
[[queue]]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL){
            return result;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()){
            vector<int> level;
            int level_size = queue.size();

            for (int i = 0; i < level_size; i++){
                TreeNode* current = queue.front();
                queue.pop();
                level.push_back(current->val);

                if (current->left != NULL) queue.push(current->left);
                if (current->right != NULL) queue.push(current->right);
            }

            result.push_back(level);
        }

        return result;
    }
};
