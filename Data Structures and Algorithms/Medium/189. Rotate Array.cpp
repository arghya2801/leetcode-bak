/*
 * I remember solving this before in one of the tests in Python and it was pretty easy, had to rack my brain a bit in c++, and even then I only solved this in the O(n) space complexity manner by taking a temporary vector. I basically took the last elements, reversed it, and added the remaining ones. The difficult part was figuring out the indexes I needed to travese, which ideally I should have done on paper and solved.
 *
 * After that was the issue of k being large. This was why my full submission test cases weren't passing, as k > n. I had to take k = k % n to fix that problem and handle those cases.
 *
 * The ideal solution would be this - reverse(0, n - 1), reverse(0, k - 1), reverse(k, n - 1)*
 *
 * [[array]] [[two pointer]]
 * /


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();

        k = k % n;

        if (n > 1) {
            for (int i = n - 1; i > n - k - 1; i--) {
                temp.push_back(nums[i]);
            }

            reverse(temp.begin(), temp.end());

            for (int i = 0; i <= n - k - 1; i++) {
                temp.push_back(nums[i]);
            }


            nums = temp;

            // // The actual OP solution
            // reverse(nums.begin(), nums.end());
            // reverse(nums.begin(), nums.begin() + k);
            // reverse(nums.begin() + k, nums.end());
        }
    }
};
