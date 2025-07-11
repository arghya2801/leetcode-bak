/*

This was an interesting problem. But not the most difficult out there. It is basically checking if a graph has loops or not, and doing it recursively with dfs. Which ended up being a bit complicated to be honest.

I should rewrite this code sometime in the future.

[[depth first search]]
[[breadth first search]]
[[graph]]
[[topological sort]]

#referback
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prerequisites_map;
        for (int i = 0; i < prerequisites.size(); i++){
            prerequisites_map[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> parent(numCourses, 0);
        bool result = true;

        for (int i = 0; i < numCourses; i++){
            if (visited[i] == 0) dfs(i, prerequisites_map, result, visited, parent);
        }

        return result;
    }

    void dfs(int node, unordered_map<int, vector<int>> &prerequisites_map, bool &result, vector<int> &visited, vector<int> &parent){
        if (visited[node] == 1 && parent[node] == 0) return;

        visited[node] = 1;

        if (visited[node] == 1 && parent[node] == 1){
            result = false;
            return;
        }

        parent[node] = 1;

        for (int i = 0; i < prerequisites_map[node].size(); i++){
            if (!visited[prerequisites_map[node][i]]){
                dfs(prerequisites_map[node][i], prerequisites_map, result, visited, parent);
            }
            else if (parent[prerequisites_map[node][i]] == 1) {
                result = false;
                return;
            }
        }

        parent[node] = 0;
    }
};
