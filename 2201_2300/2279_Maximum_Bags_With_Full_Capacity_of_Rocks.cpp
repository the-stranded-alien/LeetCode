#include<iostream>
#include<vector>

using namespace std;

// You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith
// bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
// Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.

class Solution {
public:
	static bool customCompare(const pair<int, int> &a, const pair<int, int> &b) {
		return (a.second - a.first) < (b.second - b.first);
	}

	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		vector<pair<int, int> > bagsWithoutFullCapacity;
		int n = rocks.size();
		int maximumFullBags = 0;
		for(int i = 0; i < n; i++) {
			if(rocks[i] == capacity[i]) maximumFullBags++;
			else {
				bagsWithoutFullCapacity.push_back(make_pair(rocks[i], capacity[i]));
			}
		}
		sort(bagsWithoutFullCapacity.begin(), bagsWithoutFullCapacity.end(), customCompare);
    	for(auto pr : bagsWithoutFullCapacity) {
    		if (pr.second - pr.first <= additionalRocks) {
    			maximumFullBags++;
    			additionalRocks = additionalRocks - (pr.second - pr.first);
    		} else break;
    	}
    	return maximumFullBags;
    }
};

void solve() {
	// Main Code Goes Here !!
	Solution *soln = new Solution();
	int n; cin >> n;
	vector<int> capacity(n);
	for(int i = 0; i < n; i++) cin >> capacity[i];
	vector<int> rocks(n);
	for(int i = 0; i < n; i++) cin >> rocks[i];
	int additionalRocks; cin >> additionalRocks;
	cout << soln->maximumBags(capacity, rocks, additionalRocks);
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