/*
So this was an easy question, with the main problem being the large number of conditions to handle. It looked bad, and the amount of nested if else in my first approach made it difficult to even debug in the first place.

The editorial solution was really good though, making the conditions into boolean variables and just using them instead.

[[Array]]
[[Greedy]]
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max_plants {0};
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                if (((i == 0) ||  flowerbed[i - 1] == 0) && //empty left
                    ((i == flowerbed.size() - 1) || flowerbed[i + 1] == 0)) // empty right
                {
                    flowerbed[i] = 1;
                    max_plants++;
                }
            }
        }

        if (max_plants >= n) return true;
        return false;  
    }
};


/*
// Editorial Solution
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
        // Check if the current plot is empty.
        if (flowerbed[i] == 0) {
            // Check if the left and right plots are empty.
            bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
            
            // If both plots are empty, we can plant a flower here.
            if (emptyLeftPlot && emptyRightPlot) {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
}
*/
