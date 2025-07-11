/*

This was an interesting problem. It uses the 'runner' technique where one pointer runs fast and one runs slow, i.e. fast one moves two nodes when slow moves one. This way, if there is a loop, then these two will meet eventually thus we will find the loop. Otherwise, we reach nullptr and the while loop ends, therefore no loop in the linked list.

[[linked list]]
[[two pointer]]
[[hash table]] (I don't understand why is hash table listed as one of the topics)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }

        return false;
    }
};
