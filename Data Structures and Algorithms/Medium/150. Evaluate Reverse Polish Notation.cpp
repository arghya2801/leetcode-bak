/*

This was an easy problem. And interesting one though about that infix method.

Just push the values in the stack, and when there is an operator, pop the two most recent ones and apply the operations. After that, push the result back into the stack and continue. Just remember to convert the numbers from string to integer.

[[array]]
[[math]]
[[stack]]
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result;
        stack<int> stack;

        for (int i = 0; i < tokens.size(); i++){
            string s = tokens[i];

            if (s == "+") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(a + b);
            } else if (s == "-"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            } else if (s == "*"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(a * b);
            } else if (s == "/"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(s));
            }
        }

        return stack.top();

    }
};
