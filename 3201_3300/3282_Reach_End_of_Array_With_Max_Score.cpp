#include<iostream>
using namespace std;

// You are given an integer array nums of length n.
// Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
// The score for a jump from index i to index j is calculated as (j - i) * nums[i].
// Return the maximum possible total score by the time you reach the last index.

// It can be proven that from each index i, the optimal solution is to jump to the nearest index j > i such that nums[j] > nums[i].

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int sz = nums.size();
        long long score = 0;
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        int currIndex = 0;
        int nextIndex = 1;
        while(currIndex < sz && nextIndex < sz) {
            if(nums[nextIndex] > nums[currIndex]) {
                score += 1LL * (nextIndex - currIndex) * nums[currIndex];
                currIndex = nextIndex;
            }
            nextIndex++;
        }
        if(currIndex != (sz - 1)) score += 1LL * ((sz - 1) - currIndex) * nums[currIndex];
        return score;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    Solution *soln = new Solution();
    cout << soln->findMaximumScore(nums) << endl;
    return 0;
}