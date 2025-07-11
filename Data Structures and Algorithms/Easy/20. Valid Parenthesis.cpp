/*

Approach 1 (failure)- I tried to make an if statement with 3 conditions separated with AND. First was bracket stack is empty, second was that the top element of the stack was first element of the bracket arrays, and final was that the string array's index was the second element in the bracket arrays. I made three of these statements for each type of bracket.
I made this approach thinking that this would satisfy the condition of one bracket opening and closing to be paired up will cause it to get popped.



[[stack]]
[[string]]
*/

#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                bracket_stack.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if (bracket_stack.empty()){
                    return false;
                }

                if (bracket_stack.top() == '(' && s[i] == ')' ||
                    bracket_stack.top() == '{' && s[i] == '}' ||
                    bracket_stack.top() == '[' && s[i] == ']'){
                    bracket_stack.pop();
                } else {
                    return false;
                }
            }
        }
        return bracket_stack.empty();
    }
};
