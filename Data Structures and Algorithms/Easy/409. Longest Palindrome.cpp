/*

What a question!

My first approach was totally wrong. What I did there was find the palindrome which already existed. But it could have been in out of order.

My second approach was to use the array hash where I increment each character in that 52 hash map. Didn't work.

At the end, I end up having to do it in a completely different way. Rules of a palindrome. if every character appears an even number of times, we can have that as the palindrome. If there is one odd, we can add that to the palindrome while not breaking it. So every time a number appears, we increase it by 1 in the hashmap, and decrease it by 1 on their seocnd appearance and so on. This was all evens are zeros and all odds are ones.

[[string]]
[[hash table]]
[[greedy]]

#referback
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int odd {0};
        unordered_map<char,int> char_count;

        for (char ch : s){
            char_count[ch]++;
            if (char_count[ch] % 2 == 1) {
                odd++;
            } else {
                odd--;
            }
        }

        if (odd > 1){
            return s.length() - odd + 1;
        }

        return s.length();
    }
};

        // int result = 0;
        // int char_count[52] = {0};

        // for (int i = 0; i < s.length(); i++) {
        //     char_count[s[i] - 'a']++;
        // }

        // bool has_odd = false;

        // for (int i = 0; i < 52; i++) {
        //     if (char_count[i] % 2 == 0) {
        //         result += char_count[i];
        //     } else {
        //         result += char_count[i] - 1;
        //         has_odd = true;
        //     }
        // }

        // return result + has_odd;
// --------------------------------------------------------
        // if (s.length() == 1){
        //     return 1;
        // }

        // string longest_palindrome = "";

        // for (int i=1; i<s.length(); i++){

        //     // Odd palindrome

        //     int low_odd = i;
        //     int high_odd = i;

        //     while (s[low_odd] == s[high_odd]){
        //         low_odd--;
        //         high_odd++;
        //     }

        //     if (low_odd == -1 || high_odd == s.length() - 1){
        //         break;
        //     }


        //     string palindrome = s.substr(low_odd+1, high_odd);
        //     if (palindrome.length() > longest_palindrome.length()){
        //         longest_palindrome = palindrome;
        //     }


        //     // Even palindrome

        //     int low_even = i - 1;
        //     int high_even = i;

        //     while (s[low_even] == s[high_even]){
        //         low_even--;
        //         high_even++;
        //     }

        //     if (low_even == -1 || high_even == s.length() - 1){
        //         break;
        //     }


        //     palindrome = s.substr(low_even+1, high_even);
        //     if (palindrome.length() > longest_palindrome.length()){
        //         longest_palindrome = palindrome;
        //     }
        // }

        // return longest_palindrome.length();
