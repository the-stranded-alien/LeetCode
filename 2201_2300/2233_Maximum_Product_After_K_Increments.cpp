#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > minHeap(nums.begin(), nums.end());
        while(k--) {
        	int newVal = minHeap.top() + 1;
        	minHeap.pop();
        	minHeap.push(newVal);
        }
        long long int maxProduct = 1;
        while(!minHeap.empty()) {
        	int num = minHeap.top();
        	cout << num << endl;
        	minHeap.pop();
        	maxProduct = (maxProduct * num) % int(1e9 + 7); 
        }
        return maxProduct;
    }
};

void solve() {
	Solution *soln = new Solution();
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int k; cin >> k;
	cout << soln->maximumProduct(nums, k);
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