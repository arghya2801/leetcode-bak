/*
 * An easy two pointer problem. The volume of water would be the product of height and weight, height will be the smaller number of the pointer indices, and width will be the difference of the indices of the pointers.
 *
 * [[array]]
 * [[two pointers]]
 * [[greedy]]
 * */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_water = 0;

        while (left < right) {
            int curr_height = min(height[left], height[right]);
            int curr_width = right - left;
            int volume = curr_height * curr_width;
            max_water = max(max_water, volume);

            if (height[left] < height[right]) left++;
            else right--;
        }

        return max_water;
    }
};
