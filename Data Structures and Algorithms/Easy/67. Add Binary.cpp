/*

For this question, I had to have a loop that lasts till the longer string's length.

The main concept was that we had to calculate the sum and carry separately and add them. `sum += a[i--] -'0'` did was get the ascii and subtracted ascii of 0, which made it so we were operating on the actual numbers itself. It is a way of converting string to int.

Then we add it to a string using the `to_string()` method to convert. If a carry exists, we need to add that to the string too.

At the end, we find that the result is in reverse order because we added things left to right instead of the other way round. So we use a reverse function to reverse the string, then return it.

[[math]]
[[string]]
[[bit manipulation]]
[[simulation]]


#referback
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j>= 0){
            int sum = carry;
            if (i >= 0) sum += a[i--] -'0';
            if (j >= 0) sum += b[j--] -'0';

            result += to_string(sum % 2);
            carry = sum / 2;
        }

        if (carry) result += to_string(carry);
        reverse(result.begin(), result.end());

        return result;
    }
};
