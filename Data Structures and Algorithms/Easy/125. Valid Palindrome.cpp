/*

[[string]]
[[two pointer]]
*/

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        remove_special(s);

        int length = s.length();

        int i = 0;
        int j = length - 1;
        bool check = true;

        while (i < j){
            if (s[i] == s[j]){
                check = true;
            } else {
                check = false;
                break;
            }

            i++;
            j--;
        }

        return check;
    }

    void remove_special(string &s){
        for (int i = 0; i < s.size(); i++) {

            if (!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
            }
        }
        cout << s;
    }
};
