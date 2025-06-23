/*

This was an easy question. The only problem was getting the minimum value of the stack, which was solved by making the stack using an integer pair vector. In the pair, the first part will be the normal stack value, while the second will be the minimum value added so far.

The other thing to note is that to access the last element of a vector, the back() method is used.

[[stack]]
[[design]]
*/

class MinStack {
public:
    vector<pair<int, int>> stack;
    MinStack() {

    }

    void push(int val) {
        if (stack.empty()){
            pair<int, int> p;
            p.first = val;
            p.second = val;
            stack.push_back(p);
        } else {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, stack.back().second);
            stack.push_back(p);
        }
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back().first;
    }

    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
