#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// You are given a positive integer n. Each digit of n has a
// sign according to the following rules:
// The most significant digit is assigned a positive sign.
// Each other digit has an opposite sign to its adjacent digits.
// Return the sum of all digits with their corresponding sign.

class Solution {
public:
	int alternateDigitSum(int n) {
    	stack<int> digits;
    	while(n) {
    		int d = n % 10;
    		digits.push(d);
    		n /= 10;
    	}
    	bool add = true;
    	int ads = 0;
    	while(!digits.empty()) {
    		ads += add ? digits.top() : -digits.top();
    		digits.pop();
    		add = !add;
    	}
    	return ads;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	
	Solution *soln = new Solution();
	cout << soln->alternateDigitSum(n);

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