#include<iostream>
#include<set>

using namespace std;

// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.

class Solution {
public:
	int countPairs(vector<int>& nums, int k) {
        int pairs = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
        	for(int j = i + 1; j < nums.size(); j++) {
        		if(nums[i] == nums[j] && ((i * j) % k == 0)) pairs++;
        	}
        }
        return pairs;
    }
};

void solve() {
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int k; cin >> k;

	Solution *soln = new Solution();
	cout << soln->countPairs(nums, k);

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