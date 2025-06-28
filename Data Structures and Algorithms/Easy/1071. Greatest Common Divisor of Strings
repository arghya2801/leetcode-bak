/*

So the first approach was the brute force check every string from the first character, specifically prefix.

But the optimum approach was insane. Since we need GCD of two strings, str1 + str2 = str2 + str1 since they will be identical. Second main thing about it was that the difference between the strings should be the gcd. This was an insane approach I couldn't have thought of at all.

[[math]]
[[string]]
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // string gcd = "";

        if (str1 + str2 != str2 + str1) return "";

        int gcd_length = gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_length);
    }
};