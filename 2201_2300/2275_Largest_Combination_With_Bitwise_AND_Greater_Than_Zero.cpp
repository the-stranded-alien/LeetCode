#include<iostream>
#include<vector>

using namespace std;

// The bitwise AND of an array nums is the bitwise AND of all integers in nums.

// For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for nums = [7], the bitwise AND is 7.
// You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

// Return the size of the largest combination of candidates with a bitwise AND greater than 0.

class Solution {
public:
	int largestCombination(vector<int>& candidates) {
		if(candidates.size() == 1) return 1;
        vector<int> candidate_bits(32, 0);
        for (auto candidate : candidates) {
        	for (int i = 0; i < 32; ++i) {
        		if ((candidate >> i) & 1) {
        			candidate_bits[i]++;
        		}
        	}
        }
        int max_comb_size = 1;
        for(int i = 0; i < 32; i++) {
        	if(candidate_bits[i] >= 2) {
        		max_comb_size = max(max_comb_size, candidate_bits[i]);
        	}
        }
        return max_comb_size;
    }
};

void solve() {
	Solution *soln = new Solution();
	int c; cin >> c;
	vector<int> candidates(c);
	for(int i = 0; i < c; i++) cin >> candidates[i];
	cout << soln->largestCombination(candidates);

	return;
}

int32_t main() {
	// Fast Input-Output
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// Input-Output Files
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	freopen("../error.txt", "w", stderr);
#endif	

	clock_t startTime = clock();

	int testCases = 1;
	// cin >> testCases;
	while(testCases--) solve();

	cerr << "\nRun Time : " << ((double)(clock() - startTime) / CLOCKS_PER_SEC);

	return 0;
}