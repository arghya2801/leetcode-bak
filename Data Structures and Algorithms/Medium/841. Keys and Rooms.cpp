/*
 * This was a graph question. Here I created a boolean vector the size of the rooms, so I can mark and track visited and unvisited rooms. After the dfs, all I need to do is check this vector to get the answer.
 * As for the dfs, the current node will be marked as visited. Then we'll iterate through the keys in each of the rooms. (the `int room : rooms[node]`, room is the key to the room, bad naming). If the rooms corresponding to the keys there are not visited, we visit them and do the dfs call to that room.
 *
 * #referback
 *
 * [[graphs]]
 * [[bfs]]
 * [[dfs]]*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(visited, 0, rooms);

        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }

    void dfs(vector<bool>& visited, int node, vector<vector<int>>& rooms) {
        visited[node] = true;

        for (int room : rooms[node]) {
            if (!visited[room]) dfs(visited, room, rooms);
        }
    }
};
