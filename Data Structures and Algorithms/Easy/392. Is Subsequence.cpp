/*
 * A tricky question. Had to rely on two pointers. Compare the pointers of both strings, if same increment both otherwise increment t string's pointer only. If s string's pointer reaches the end of string s, we have our answer.
 *
 * [[Two Pointers}}
 * [[String}}
 * [[Dynamic Programming]]
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }
};
