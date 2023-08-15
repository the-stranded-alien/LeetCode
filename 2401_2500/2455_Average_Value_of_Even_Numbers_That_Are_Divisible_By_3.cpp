#include<iostream>

using namespace std;


class Solution {
public:
	int averageValue(vector<int>& nums) {
        int c = 0;
        int s = 0;
        for(auto num : nums) {
            if(num % 2 == 0 && num % 3 == 0) {
                s += num;
                c += 1;
            }
        }
        if(c == 0) return 0;
        return s / c;
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