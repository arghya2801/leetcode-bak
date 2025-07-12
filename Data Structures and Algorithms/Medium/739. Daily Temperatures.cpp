/*
 * My first brute force approach was to basically do 2 nested loops and check the warmer day. I added an unnecessary condition, though it didn't matter much.
 *
 * But it ended with the TLE. The better approach was to use a stack. If the temperature of a day is warmer, push the index to the stack. Keep popping everytime before you push to make it a monotonic stack. At the end, update the vector with the index after the iteration is done.
 *
 * #referback
 *
 * [[array]]
 * [[stack]]
 * [[monotonic stack]]
 * */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Stack method
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int index = s.top(); 
                s.pop();
                answer[index] = i - index;
            }
            s.push(i);
        }
        return answer;

        // First approach
        // vector<int> answer(temperatures.size(), 0);

        // for (int i = 0; i < temperatures.size(); i++) {
        //     int days = 0;
        //     for (int j = i + 1; j < temperatures.size(); j++) {
        //         if (temperatures[j] > temperatures[i]) {
        //             days = j - i;
        //             answer[i] = days;
        //             break;
        //         }
        //         if (temperatures[j] > temperatures[i]) {
        //             days++;
        //         }
        //     }
        // }

        // return answer;
    }
};
