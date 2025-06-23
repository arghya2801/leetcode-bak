/*

[[string]]
[[trie]]

The approach I tried here was -
- If the array is empty return
- The prefix isn't going to be bigger than any word, so we take the whole first string as the prefix and take its length
- Now we loop from the 2nd element, and compare each word with our prefix
- If the prefix length is bigger than the string, or if it is smaller but not a prefix, we reduce the prefix length by 1
	- We are comparing the strings using the `substr` function for strings
- If prefix length becomes 0, then no common prefix
- Otherwise, we use `substr` to update the prefix and return it
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];
        int prefix_length = prefix.length();

        for (int i = 1; i < strs.size(); i++) {
            string s = strs[i];
            while (prefix_length > s.length()
                || prefix != s.substr(0, prefix_length)) {
                    prefix_length--;
                    if (prefix_length == 0) return "";
                    prefix = prefix.substr(0, prefix_length);
            }
        }

        return prefix;

        // for (int i = 0; i < strs[0].size(); i++) { //character
        //     for (int j = 1; i < strs.size(); j++) { //string
        //         if (strs[j].size() <= i ||
        //             strs[j][i] != strs[0][i]) {
        //             return strs[0].substr(0, i);
        //         }
        //     }
        // }

        // return strs[0];
    }
};
