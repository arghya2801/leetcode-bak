/*

We create a set to track the substring without duplicates. So when we iterate through the string, we call the iterator 'right' since it will be the right end of the substring with 'left' being the left end.

When we iterate, we check if the current element of the string is present in the set or not. If not we insert it in. Now, we compare this new length with `right - left + 1` ( #citation_needed ) and whichever is the greater one, we assign it to the result.

If the element is in the set, we clear the set entirely while moving the left pointer to the end of the previous substring so we can start checking the new substring.

[[hash table]]
[[string]]
[[sliding window]]

#referback
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0;
        int result = 0;

        set<char> char_set;

        for (int right = 0; right < s.length(); right++) {
            if (char_set.count(s[right]) == 0) {
                char_set.insert(s[right]);
                result = max(result, right - left + 1);
            } else {
                while (char_set.count(s[right])) {
                    char_set.erase(s[left]);
                    left++;
                }
            }
            char_set.insert(s[right]);
        }
        return result;
    }
};
