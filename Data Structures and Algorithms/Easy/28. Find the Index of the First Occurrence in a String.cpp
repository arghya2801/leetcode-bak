/*

[[Two Pointers]]
[[String]]
[[String Matching]]

I basically compared like this - "hello", "ll" ->
- he ll
- el ll
- ll ll
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_length = haystack.size();
        int needle_length = needle.size();

        for (int i = 0; i < haystack_length; i++) {
            string s = haystack.substr(i, needle_length);
            cout << s << " " << needle << endl;
            if (s == needle) return i;
        }

        return -1;
    }
};
