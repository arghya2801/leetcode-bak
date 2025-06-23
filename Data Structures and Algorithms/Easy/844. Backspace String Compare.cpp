/*

This was an easy question using stacks. The harder method uses two pointers, on both strings and moves backwards to compare.

[[stack]]
[[string]]
[[two pointer]]
[[simulation]]
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;

        for (char c : s){
            if (c == '#'){
                if (!s1.empty()) s1.pop();
            }
            else s1.push(c);
        }

        for (char c : t){
            if (c == '#'){
                if (!t1.empty()) t1.pop();
            }
            else t1.push(c);
        }

        while (!s1.empty() && !t1.empty()){
            if (s1.top() != t1.top()) return false;
            s1.pop();
            t1.pop();
        }

        return s1.empty() && t1.empty();
    }
};
