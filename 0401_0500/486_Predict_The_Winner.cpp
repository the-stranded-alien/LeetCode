// You are given an integer array nums.
// Two players are playing a game with this array: player 1 and player 2.
// Player 1 and player 2 take turns, with player 1 starting first.
// Both players start the game with a score of 0. At each turn,
// the player takes one of the numbers from either end of the array
// (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1.
// The player adds the chosen number to their score. The game ends when there are no more elements in the array.
// Return true if Player 1 can win the game. If the scores of both players are equal,
// then player 1 is still the winner, and you should also return true. You may assume that
// both players are playing optimally.

// We’re not directly computing Player 1’s total score,
// we’re computing the score difference between the current player and the opponent —
// that’s what the recurrence f(i, j) represents.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int maxScore(vector<int>& nums, int s, int e) {
        if(s == e) return nums[s];
        int pickLeft = nums[s] - maxScore(nums, s + 1, e);
        int pickRight = nums[e] - maxScore(nums, s, e - 1);
        return max(pickLeft, pickRight);
    }    
public:
    bool predictTheWinner(vector<int>& nums) {
        return maxScore(nums, 0, nums.size() - 1) >= 0;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    Solution *s = new Solution();
    cout << s->predictTheWinner(nums) << endl;
    return 0;
}