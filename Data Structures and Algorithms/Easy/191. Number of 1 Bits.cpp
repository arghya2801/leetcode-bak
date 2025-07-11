/*

I solved this using the logic of converting decimal to binary. I add `n % 2` to count every iteration in the while loop which ends when n is 0. `n % 2` gives the remainder which is considered for the binary, which ends up as our greatest place of the binary. I directly add it to count since we don't require the binary and the zeros being added won't affect count. I divide n by 2 after that to proceed with the loop just like the on-paper conversion process.

I can also do it by bit manipulation, which I don't know. I will do this with that next time.

[[divide and conquer]]
[[bit manipulation]]
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n != 0){
            count += n % 2;
            n = n / 2;
        }

        return count;
    }
};
