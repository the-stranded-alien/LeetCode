#include<iostream>

using namespace std;


class Solution {
public:
	int commonFactors(int a, int b) {
        int minNum = min(a, b);
        int cf = 0;
        for(int i = 1; i <= minNum; i++) {
            if(a % i == 0 && b % i == 0) {
                cf++;
            }
        }
        return cf;
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