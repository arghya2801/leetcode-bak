/*

This was a very tricky question which I wasn't able to do on my own. The recursion was basic, and the logic wasn't hard, but it required quite a bit of intuition. Here is the approach.

I first check if the row and column index are not out of bound of the matrix, which will happen if we don't stop it while recursing. I also add a check for seeing if the element we reach is the same as the starting element; given that we are not supposed to color it.

Now we apply the color to the pixel. Then write the recursion statements, for all four directions by changing the row and column by incrementing and decrementing them once.

In the main function, we define the starting pixel as a variable to make things easier. We add an if loop to check if the new color is the same as the starting pixel, in which case we don't require to do anything, hence we return. Then we call the dfs function.

The main thing to note here is keeping all the required parameters and using them properly. I couldn't figure out which parameters to use which led to me not being able to


[[array]]
[[depth first search]]
[[breadth first search]]
[[matrix]] / [[graph]]
[[recursion]]

#referbackpro
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int starting_pixel = image[sr][sc];

        if (image[sr][sc] == color){
            return image;
        }

        dfs(image, sr, sc, starting_pixel, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int starting_pixel, int color){
        if (sr < 0 ||
            sr >= image.size()||
            sc < 0 ||
            sc >= image[0].size() ||
            image[sr][sc] != starting_pixel) {return;}

        image[sr][sc] = color;

        dfs(image, sr+1, sc, starting_pixel, color);
        dfs(image, sr-1, sc, starting_pixel, color);
        dfs(image, sr, sc+1, starting_pixel, color);
        dfs(image, sr, sc-1, starting_pixel, color);
    }
};
