/*
 * So this was a good refresher on how hash sets work. We basically interate through the given vectors and use the set.insert(n) command to insert the unique elements in the set.
 * After that we make vector and iterate over it while using n.find(n) in the other set to check if that element exists there and compare it to the entire list of the set using n.end() [important], if not we have the unique element and we push it to the vector.
 *
 * [[array]]
 * [[hash table]]
 * */

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        for (int num : nums1) {
            n1.insert(num);
        }
        
        unordered_set<int> n2;
        for (int num : nums2) {
            n2.insert(num);
        }

        vector<int> answer1;
        for (int n : n1) {
            if (n2.find(n) == n2.end()) answer1.push_back(n);
        }
        
        vector<int> answer2;
        for (int n : n2) {
            if (n1.find(n) == n1.end()) answer2.push_back(n);
        }

        vector<vector<int>> result;
        result.push_back(answer1);
        result.push_back(answer2);

        return result;
    }
};
