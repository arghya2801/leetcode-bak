/*

[[string]]
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        string str_x_inv = str_x;
        reverse(str_x_inv.begin(), str_x_inv.end());
        return str_x == str_x_inv;
    }
};
