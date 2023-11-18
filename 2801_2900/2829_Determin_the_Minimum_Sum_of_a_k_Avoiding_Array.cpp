#include<iostream>
#include<vector>
#include<set>

using namespace std;

// You are given two integers, n and k.
// An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.
// Return the minimum possible sum of a k-avoiding array of length n.

class Solution {
public:
	int minimumSum(int n, int k) {
        set<int> numbersAdded;
        int sum = 0;
        int currentNumber = 1;
        int numbersToAdd = n;
        while(true) {
        	if(numbersAdded.find(k - currentNumber) == numbersAdded.end()) {
        		numbersAdded.insert(currentNumber);
        		numbersToAdd--;
        		sum += currentNumber;
        	}
        	currentNumber++;
        	if(!numbersToAdd) break;
        }
        return sum;
    }
};

void solve() {
	int n; cin >> n;
	int k; cin >> k;

	Solution *soln = new Solution();
	cout << soln->minimumSum(n, k);

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