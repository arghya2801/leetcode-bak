/*

[[binary search]]
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 0;
        long long high = n;
        long long bad = 0;

        while (low <= high){
            long long mid = (low + high) / 2;
            if (isBadVersion(mid)){
                bad = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return bad;
    }
};
