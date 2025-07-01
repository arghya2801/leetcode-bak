/*
 * Create new vector, make the sum of each entry to find new height, get the max element of that vector
 *
 * [[array]]
 * [[prefix sum]]
 * */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes;
        int new_height = 0;

        altitudes.push_back(new_height);
        for (int i = 0; i < gain.size(); i++) {
            new_height += gain[i];
            altitudes.push_back(new_height);
        }

        sort(altitudes.begin(), altitudes.end());
        int max_height = altitudes.back();

        return max_height;
    }
};
