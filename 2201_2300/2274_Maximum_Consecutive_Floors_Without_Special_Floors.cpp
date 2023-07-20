#include<iostream>
#include<vector>

using namespace std;

// Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.
// You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.
// Return the maximum number of consecutive floors without a special floor.


class Solution {
public:
	int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int maxCon = INT_MIN;
        int curFloor = bottom - 1;
        for(auto floor : special) {
        	maxCon = max(maxCon, (floor - 1 - curFloor));
        	curFloor = floor;
        }
        maxCon = max(maxCon, (top - curFloor));
        return maxCon;
    }
};

void solve() {
	// Main Code Goes Here !!
	Solution *soln = new Solution();
	int bottom, top, sn;
	cin >> bottom >> top >> sn;
	vector<int> special(sn);
	for(int i = 0; i < sn; i++) cin >> special[i];
	cout << soln->maxConsecutive(bottom, top, special);

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