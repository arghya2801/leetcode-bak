/*
 * Here we are given adjacency matrix of cities that are connected. So the DFS function is going to be very similar in these graph questions. The logic here was a visited array, and if something is not visited, we increment the 'connected' variable by 1. This will be 1 province. Now when we call the dfs function here, we mark that node as visited and iterate thorugh all the elements in that node. If that node is true/1 and that node hasn't been visited, we DFS into it.
 *
 * So here the dfs function is called N times, but the dfs in the findCircleNum is called only that many times that the provinces are.
 *
 *
 * #referback
 * [[graph]]
 * [[bfs]]
 * [[dfs]]
 * */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int connected = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connected++;
                dfs(i, isConnected, visited);
            }
        }

        return connected;
    }

    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visited[i]) dfs (i, isConnected, visited);
        }
    }
};
