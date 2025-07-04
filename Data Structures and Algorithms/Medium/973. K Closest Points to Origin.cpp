/*

My approach was basically correct. We first calculate the distance of all the points from the origin. But we need to return the coordinates,  not the distances which makes it a little harder.

The concept to use here is heap, which makes the question really easy. Create a priority queue which store the distance and the coordinates `(distance, [x,y])`.  By default, priority queue acts as a max heap. If it was a min heap, we could have printed the first k elements and be done with it.

But in a max heap, we can just pop the elements if the size is more than k. And since the greatest elements will be on the top, they will get out leaving only the closest distances.

[[array]]
[[math]]
[[divide and conquer]]
[[geometry]]
[[sorting]]
[[heap]]
[[priority queue]]
[[quickselect]]
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> distance;

        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist, {points[i][0], points[i][1]}});

            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            pair<int, int> p = pq.top().second;
            distance.push_back(vector<int>{p.first, p.second});
            pq.pop();
        }

        return distance;
    }
};
