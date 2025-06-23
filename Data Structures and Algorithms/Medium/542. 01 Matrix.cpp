/*

This was a really tough question.

The approach to solve this is to use a queue. First we make a visited matrix and a distance matrix. Whenever we visit the matrix, and find that there are zeros, we update that and push its coordinates to the queue. The queue is (coordinate, distance). Since they are all zeros, we make the distance zero. So we only update the matrix for the 1's.

Then we perform BFS. We visit all directions frmo each cell of the matrix. We select this frmo the queue.

Reference - https://www.youtube.com/watch?v=edXdVwkYHF8

[[array]]
[[dynamic programming]]
[[breadth first search]]
[[matrix]]

#referbackpro
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> distance(n, vector<int>(m,0));
        queue<pair<pair<int, int>, int>> q;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                } else {
                    visited[i][j] = 0;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;

            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == 0){
                        visited[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, steps+1});
                    }
            }
        }

        return distance;
    }
};
