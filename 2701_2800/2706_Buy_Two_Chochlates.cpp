#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int buyChoco(vector<int>& prices, int money) {
		sort(prices.begin(), prices.end());
		int twoCheapest = prices[0] + prices[1];
		if(twoCheapest > money) return money;
		return money - twoCheapest;		
    }
};

void solve() {
	Solution *soln = new Solution();
	int n; cin >> n;
	vector<int> prices(n);
	for(int i = 0; i < n; i++) cin >> prices[i];
	int money; cin >> money;
	cout << soln->buyChoco(prices, money);
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