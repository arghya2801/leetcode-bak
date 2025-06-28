/*
[[String]]
[[Two pointer]]
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        
        // pointers
        int p1 = 0;
        int p2 = 0;

        while (true) {
            if (p1 < word1.size()) {
                result += word1[p1];
                p1++;
            }
            
            if (p2 < word2.size()) {
                result += word2[p2];
                p2++;
            }

            if (p1 == word1.size() && p2 == word2.size()) break;
        }

        return result;
    }
};