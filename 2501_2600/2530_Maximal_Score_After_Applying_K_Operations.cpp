#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

// In one operation:

// choose an index i such that 0 <= i < nums.length,
// increase your score by nums[i], and
// replace nums[i] with ceil(nums[i] / 3).
// Return the maximum possible score you can attain after applying exactly k operations.

// The ceiling function ceil(val) is the least integer greater than or equal to val.

class Solution {
public:
	long long maxKelements(vector<int>& nums, int k) {
    	priority_queue<int> pq(nums.begin(), nums.end());
    	long long int maxVal = 0;
    	while(k--) {
    		int top = pq.top();
    		pq.pop();
    		maxVal += top;
    		pq.push(ceil((double) top / 3));
    	}
    	return maxVal;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int k; cin >> k;
	
	Solution *soln = new Solution();
	cout << soln->maxKelements(nums, k);

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