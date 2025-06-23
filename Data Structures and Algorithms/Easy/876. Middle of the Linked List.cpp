/*

I could have used two pointers somehow, but couldn't get the intuition for that/

I calculated the length of the linked list, and then iterated to the half point by using another pointer. Then returned it.

[[linked list]]
[[two pointer]]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        ListNode* temp = head;

        int count {0};
        int half {0};
        int len {0};

        while (current != NULL){
            current = current->next;
            count++;
        }

        half = count/2;

        while (len != half){
            temp = temp->next;
            len++;
        }

        return temp;
    }
};
