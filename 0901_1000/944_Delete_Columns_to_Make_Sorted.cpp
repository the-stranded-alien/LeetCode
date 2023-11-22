#include<iostream>
#include<set>

using namespace std;

// You are given an array of n strings strs, all of the same length.
// The strings can be arranged such that there is one on each line, making a grid.
// For example, strs = ["abc", "bce", "cae"] can be arranged as follows:
// abc
// bce
// cae
// You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
// Return the number of columns that you will delete.

class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int deletionSize = 0;
        int len = strs[0].length();
        int count = strs.size();
        for(int i = 0; i < len; i++) {
        	char cur = strs[0][i];
        	for(int j = 1; j < count; j++) {
        		if(cur <= strs[j][i]) cur = strs[j][i];
        		else {
        			deletionSize++;
        			break;
        		}
        	}
        }
        return deletionSize;
    }
};

void solve() {
	int n; cin >> n;
	vector<string> strs(n);
	for(int i = 0; i < n; i++) cin >> strs[i];

	Solution *soln = new Solution();
	cout << soln->minDeletionSize(strs);

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