#include<iostream>

using namespace std;

// You are given two integers, num and t.
// An integer x is called achievable if it can become equal to num after applying the following operation no more than t times:
// Increase or decrease x by 1, and simultaneously increase or decrease num by 1.
// Return the maximum possible achievable number. It can be proven that there exists at least one achievable number.

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (t * 2);
    }
};

void solve() {
	// Main Code Goes Here !!
	
	
	Solution *soln = new Solution();


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