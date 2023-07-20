#include<iostream>
#include<vector>

using namespace std;

// Given a string s and a character letter, return the percentage
// of characters in s that equal letter rounded down
// to the nearest whole percent.

class Solution {
public:
	int percentageLetter(string s, char letter) {
        int l = s.length();
        int match = 0;
        for(auto c : s) {
        	if (c == letter) match++;
        }
        return (match * 100 / l);
    }
};

void solve() {
	Solution *soln = new Solution();
	string s;
	char letter;
	cin >> s;
	cin >> letter;
	cout << soln->percentageLetter(s, letter); 
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