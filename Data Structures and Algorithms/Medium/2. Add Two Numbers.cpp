/*

[[linked list]]
[[recursion]]
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* current = result;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;
            current->next = new ListNode(sum);
            current = current->next;
        }

        return result->next;
    }
};
