#include<iostream>

using namespace std;

// Your laptop keyboard is faulty, and whenever you type a
// character 'i' on it, it reverses the string that you have written. Typing other characters works as expected.
// You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.
// Return the final string that will be present on your laptop screen.


class Solution {
public:
	string finalString(string s) {
        string fs = "";
        for(auto ch : s) {
        	if(ch == 'i') {
        		reverse(fs.begin(), fs.end());
        	} else {
        		fs += ch;
        	}
        }
        return fs;
    }
};

void solve() {
	Solution *soln = new Solution();
	string s; cin >> s;
	cout << soln->finalString(s);

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