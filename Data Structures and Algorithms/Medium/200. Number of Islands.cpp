/*

This was similar to a previous question (probably [[733. Flood Fill]]). But this is an easier question than that monstrosity for sure.

Basically, we use dfs (or bfs) to traverse the graph. While traversing, whenever we encounter an 1, we increment the number of islands and call the dfs fucntion.

This function, what it does is returns nothing if the traversal goes beyond the range of the graph or is not  1. If it is 1, it turns it into a 0, thus marking it as visited. A bad practice, but well it works. After that, the dfs is done recursively in all 4 directions thus covering the entire graph.

[[array]]
[[depth first search]]
[[breadth first search]]
[[union find]]
[[matrix]]

#referback
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int islands = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>> &grid, int i, int j){
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1'){
                return;
            }

        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
