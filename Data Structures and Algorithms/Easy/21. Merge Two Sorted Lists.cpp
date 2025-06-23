/*

I took those two linked lists and put both of them in a vector. Then I used the default sort available in C++ to sort the array and then converted it into a linked list.
Note - This is an inefficient method, ideally it should be done by using linked lists directly without an intermediatory array/vector.


[[linked list]]
[[recursion]]

#referback
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> array;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL){
            array.push_back(temp1->val);
            temp1 = temp1->next;
        }

        while (temp2 != NULL){
            array.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(array.begin(), array.end());

        ListNode* temp_head = new ListNode(-1);  // Act as head of linked list
        ListNode* list = temp_head;

        for (int i=0; i<array.size(); i++){
            list->next = new ListNode(array[i]);
            list = list->next;
        }

        return temp_head->next;

    }
};
