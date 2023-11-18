#include<iostream>
#include<vector>

using namespace std;

// You are given a 0-indexed array nums of integers.
// A triplet of indices (i, j, k) is a mountain if:
// i < j < k
// nums[i] < nums[j] and nums[k] < nums[j]
// Return the minimum possible sum of a mountain triplet of nums. If no such triplet exists, return -1.

class Solution {
public:
	int minimumSum(vector<int>& nums) {
        int minSum = INT_MAX;
        for(int i = 0; i < nums.size() - 2; i++) {
        	int n1 = nums[i];
        	for(int j = i; j < nums.size() - 1; j++) {
        		int n2 = nums[j];
        		for(int k = j; k < nums.size(); k++) {
        			int n3 = nums[k];
        			if((n2 > n1) && (n2 > n3)) {
        				minSum = min(minSum, (n1 + n2 + n3));
        			}
        		}
        	}
        }
        return minSum == INT_MAX ? -1 : minSum;
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}	
	
	Solution *soln = new Solution();
	cout << soln->minimumSum(nums);

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