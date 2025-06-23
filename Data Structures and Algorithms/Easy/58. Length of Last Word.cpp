/*

[[string]]

This was a little bit tricky and I started approaching this the wrong way. First lesson - while loops also exists and have a purpose.
Basically, I initialized my iterator outside the loop, and decremented it till all the trialing spaces were passed. Then I did another loop till I encountered a space, while incrementing length.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
