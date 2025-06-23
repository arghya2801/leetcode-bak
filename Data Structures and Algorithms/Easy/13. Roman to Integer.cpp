/*

This was a good question. The main logic is to check if the current character of the roman string is greater than the next or not. If not (like IV), then we subtract the value. When we reach the next value, we add it by again doing the comparison. This way, IV ends up being 0-1+5 = 4 which is correct.

A simple hash table made it easy. Though I guess this was more of a dictionary situation than hash. But the dictionary logic lingers from python.

[[hash table]]
[[math]]
[[string]]
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int result = 0;

        for (int i = 0; i < s.length(); i++){
            if (map[s[i]]  < map[s[i + 1]]) result -= map[s[i]];
            else result += map[s[i]];
        }

        return result;
    }

};
