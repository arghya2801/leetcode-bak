/*

Reference - https://www.youtube.com/watch?v=A8NUOmlwOlM

[[array]]

#referback
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        vector<int> res;

        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                result.push_back(newInterval);
                newInterval = intervals[i];
            } else if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
