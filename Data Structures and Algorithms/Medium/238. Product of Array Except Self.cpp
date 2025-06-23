/*

My first approach was to have two nested loops, skip over the part where the inside loop was equal to the iterator of the outside one and then just multiply the numbers to the products. This was correct, but time complexity was too high.

Then I used the two pointer technique, where the left pointer multiplied till 'i' and same with right pointer, just starting from the end. This also had a high time complexity.

The method which worked was to create two prefix sum arrays. Enter the values while multiplying the numbers of the array from the left and right respectively. E.g. [1,2,3,4] => [1,2,6,24] and [24,24,12,4]. Then multiply these two and you get the result.

[[array]]
[[prefix sum]]

#referback
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size, 1);
        vector<int> right(size, 1);
        vector<int> result(size);

        for (int i = 1; i < size; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        for (int i = size-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        for (int i = 0; i < size; i++) {
            result[i] = left[i] * right[i];
        }

        return result;



        // ----------
        // int size = nums.size();
        // vector<int> result;
        // for (int i = 0; i < size; i++){
        //     int left = 0;
        //     int right = size - 1;
        //     int product = 1;

        //     while (left < i){
        //         product *= nums[left];
        //         left++;
        //     }

        //     while (right > i){
        //         product *= nums[right];
        //         right--;
        //     }

        //     result.push_back(product);
        // }

        // ----
        // for (int i = 0; i < size; i++){
        //     int product = 1;
        //     for (int j = 0; j < size; j++){
        //         if (j == i) continue;
        //         product *= nums[j];
        //     }
        //     result.push_back(product);
        // }

        // return result;
    }
};
