/*

My first approach was to first check the lengths of the two strings. Then sort the two strings and check if they are the same or not. This was a pretty bad method, even if it worked.

Next method was a pseudo hash using an array. Basically, I made this `char_count[26]` array. Here, I had two approaches. First was making two such arrays for both strings. Then, iterate through the strings while incrementing the alphabet's count by 1 every time it was in the string. This way, each index represented an alphabet, and the value of that index represented the count of each alphabet. After this, either create a new string for both and compare them as in my first approach, or simply compare the hash tables.

The other approach is far better and far more elegant which I found elsewhere. I only maintain one hash table. First I iterate through the first string and count the alphabets in it through the hash table. Then, I do the same for the second string using the same hash table, but instead of incrementing, I decrement. This way, if the two strings are anagrams, it doesn't matter since the same alphabets will get reduced to zero while leaving the rest unaffected. Thus, we end up with the array being completely zero. We check this and return the boolean.

[[hash table]]
[[string]]
[[sorting]]

#referback
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.length() != t.length()) return false;

        // int char_count_s[26] = {0};

        // string s_sorted[s.length()];
        // for (int i=0; i<s.length(); i++){
        //     char_count_s[s[i] - 'a']++;
        // }

        // int sorted_index_s = 0;
        // for (int i=0; i<26; i++){
        //     for (int j=0; j<char_count_s[i], j++){
        //         s_sorted[sorted_index_s++] = (char)('a' + i);
        //     }
        // }

        // string t_sorted[t.length()];
        // int char_count_t[26] = {0};
        // for (int i=0; i<t.length(); i++){
        //     char_count_t[t[i] - 'a']++;
        // }

        // int sorted_index_t = 0;
        // for (int i=0; i<26; i++){
        //     for (int j=0; j<char_count_t[i], j++){
        //         t_sorted[sorted_index_t++] = (char)('a' + i);
        //     }
        // }

        // if (s_sorted == t_sorted){
        //     return true
        // } else {
        //     return false;
        // }

        if (s.length() != t.length()) return false;

        int char_count[26] = {0};

        for (int i = 0; i < s.length(); i++) {char_count[s[i] - 'a']++;}
        for (int i = 0; i < t.length(); i++) {char_count[t[i] - 'a']--;}

        for (int i = 0; i < 26; i++) {
            if (char_count[i] != 0) {
                return false;
            }
        }

        return true;
    }

};
