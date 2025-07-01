/*
 * A nice question. Basically inserted the indexes of the Radiants and Dires in there respective queues. After that, if the index of the front was less of one side, we poped both fronts and add another number (n = senate.length(), n++) to the winner.
 * Once one queue is empty, the other group is considered victorious.
 *
 * [[string]]
 * [[greedy]]
 * [[queue]]
 * */

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;

        int n = senate.length();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front()) {
                radiant.push(n);
            } else {
                dire.push(n);
            }
            radiant.pop();
            dire.pop();
            n++;
        }

        bool radiant_empty = radiant.empty();
        bool dire_empty = dire.empty();

        if (radiant_empty) return "Dire";
        else return "Radiant";
    }
};
