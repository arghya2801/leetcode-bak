/*
 * A simple node deletion in linkedlist problem. Only problem was figuring out the middle node and handling the edge cases.
 *
 * There is a two pointer approach which is far more efficient.
 *
 * [[linked list]]
 * [[two pointers]]
 * */


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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* current = head;
        int size = 1;

        while (current->next) {
            size++;
            current = current->next;
        }

        int middle = size / 2;

        int size2 = 0;
        ListNode* current2 = head;
        while (current2) {
            if (!head || !head->next) {
                return nullptr;
            }
            if (size2 == middle - 1) {
                current2->next = current2->next->next;
                break;
            } else {
                current2 = current2->next;
            }
            size2++;
        }
        
        return head;

    }
};
