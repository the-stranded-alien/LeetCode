#include<iostream>

using namespace std;


class Solution {
public:
	string removeTrailingZeros(string num) {
        int endIndex = num.length();
        while(endIndex) {
        	if(num[endIndex - 1] != '0') {
        		break;
        	}
        	endIndex--;
        }
        return num.substr(0, endIndex);
    }
};

void solve() {
	Solution *soln = new Solution();
	string s; cin >> s;
	cout << soln->removeTrailingZeros(s);
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