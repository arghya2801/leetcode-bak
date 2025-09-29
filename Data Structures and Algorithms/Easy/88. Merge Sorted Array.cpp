/*
 * I utilized the logic of comparing the elements of both arrays and incrementing the counter after pushing the new data onto a temp array. I overwrote the nums1 array with this temp array afterwards. This technically only takes O(m+n) but that's it - I didn't solve it properly in spirit of the merge directly in nums1. It solves the question so that's good.
 *
 * To do the merge, I should use the same logic, just from behind. Using 3 pointers - one for the end of each array and one for the end of the extended length of nums1 which is there for the merge. From there, compare the last elements of each array and add the greater one to the extended end of nums1.
 *
 * [[array]]
 * [[two pointers]]
 * [[sorting]]
 * */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = 0;
        int b = 0;

        vector<int> temp;

        while (a < m && b < n) {
            if (nums1[a] < nums2[b]) {
                temp.push_back(nums1[a]);
                a++;
            } else if (nums1[a] > nums2[b]) {
                temp.push_back(nums2[b]);
                b++;
            } else {
                temp.push_back(nums1[a]);
                temp.push_back(nums2[b]);
                a++;
                b++;
            }
        }

        if (a < m) {
            for (int i = a; i < m; i++) {
                temp.push_back(nums1[i]);
            }
        }

        if (b < n) {
            for (int i = b; i < n; i++) {
                temp.push_back(nums2[i]);
            }
        }

        nums1 = temp;
        
    }
};
