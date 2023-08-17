#include<iostream>

using namespace std;

// You are given a string s representing an attendance record
// for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
// 'A': Absent.
// 'L': Late.
// 'P': Present.
// The student is eligible for an attendance award if they meet both of the following criteria:
// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Return true if the student is eligible for an attendance award, or false otherwise.

class Solution {
public:
	bool checkRecord(string s) {
		int countAbsent = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == 'A') countAbsent++;
			else if(s[i] == 'L') {
				if(i + 2 < s.length() && s[i + 1] == 'L' && s[i + 2] == 'L') {
					return false;
				}
			}
		}        
		if(countAbsent >= 2) return false;
		return true;
    }
};

void solve() {
	string s; cin >> s;
	Solution *soln = new Solution();
	cout << soln->checkRecord(s);
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