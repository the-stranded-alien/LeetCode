#include<iostream>
#include<vector>

using namespace std;

// You are given a 0-indexed 2D integer array brackets where
// brackets[i] = [upperi, percenti] means that the ith tax bracket
// has an upper bound of upperi and is taxed at a rate of percenti.
// The brackets are sorted by upper bound (i.e. upperi-1 < upperi
// for 0 < i < brackets.length).

// Tax is calculated as follows:

// The first upper0 dollars earned are taxed at a rate of percent0.
// The next upper1 - upper0 dollars earned are taxed at a rate of percent1.
// The next upper2 - upper1 dollars earned are taxed at a rate of percent2.
// And so on.
// You are given an integer income representing the amount of
// money you earned. Return the amount of money that you have to
// pay in taxes. Answers within 10^-5 of the actual answer will be accepted.


class Solution {
public:
	double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0.00;
        int alreadyTaxed = 0;
        int prev = 0;
        for (int i = 0; i < brackets.size(); i++) {
        	int upper = brackets[i][0];
        	double taxRate = brackets[i][1];
        	int from = min(upper, income);
        	int toBeTaxed = from - prev;
        	cout << toBeTaxed << endl;
        	if (toBeTaxed > 0) {
        		tax += (toBeTaxed * taxRate) / 100.0;
        	}

        	prev = upper;
        }
        return tax;
    }	
};

void solve() {
	Solution *soln = new Solution();
	int n; cin >> n;
	vector<vector<int> > brackets(n, vector<int> (2, 0));
	for(int i = 0; i < n; i++) {
		cin >> brackets[i][0] >> brackets[i][1];
	}
	int income; cin >> income;
	cout << soln->calculateTax(brackets, income);
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