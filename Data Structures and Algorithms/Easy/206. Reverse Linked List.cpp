/*

I had two approaches to this question. First was the stack method, where I added all the elements in a stack, then created a new linked list by popping the elements of the stack. This was a simple and straight forward method.

The other approach was directly using the linked list itself. Concept was to reverse the pointers.

Here I create a node `next` which is equal to `current->next`. The I changed `current->next` to be the previous node, which I initialized to NULL. Then I changed the `prev` node as current and the current one as next. This kept looping till we reach the end of the list, thus changing the direction of all the pointers.


[[linked list]]
[[recursion]]
[[stack]]
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return NULL;
        }

        if (head->next == NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        return head;


    // Stack method
        // ListNode* reversed = nullptr;
        // stack<ListNode*> list_stack;

        // ListNode* current = head;
        // while (current != NULL){
        //     list_stack.push(current);
        //     current = current->next;
        // }


        // while (!list_stack.empty()){
        //     reversed = list_stack.top();
        //     list_stack.pop();
        //     reversed = reversed->next;
        // }

        // return reversed;
    }
};
