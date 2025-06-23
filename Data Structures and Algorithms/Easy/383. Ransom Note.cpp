/*

[[hash table]]
[[string]]
[[counting]]
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;

        int char_count_ransomNote[26] = {0};
        int char_count_magazine[26] = {0};

        for (int i = 0; i < ransomNote.length(); i++) {
            char_count_ransomNote[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            char_count_magazine[magazine[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (char_count_ransomNote[i] > char_count_magazine[i]) {
                return false;
            }
        }

        return true;
    }
};
