#include<bits/stdc++.h>

using namespace std;

// #define int 				long long int
#define double				long double
#define F 					first
#define S 					second
#define pb 					push_back
#define pob					pop_back
#define mp 					make_pair
#define si 					set <int>
#define vi 					vector <int>
#define vs					vector <string>
#define vb					vector <bool>
#define pii 				pair <int, int>
#define vpi         		vector <pii>
#define vpp         		vector <pair <int, pii> >
#define vvi					vector <vector<int> >
#define mii         		map <int, int>
#define mpi         		map <pii, int>
#define spi         		set <pii>
#define nl					"\n"
#define tb					"\t"
#define sz(x)				((int) x.size())
#define all(p)				p.begin(), p.end()
#define maxQue				priority_queue <int>
#define minQue				priority_queue <int, vi, greater<int> >
#define bug(...)			__f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)			for(auto x : a) cout << x << " "; cout << endl
#define printRange(a,x,y)  	for(int i = x; i < y; i++) cout << a[i] << " "; cout << endl
#define printRev(a,x,y)		for(int i = x; i > y; i--) cout << a[i] << " "; cout << endl
#define printPair(p)      	for(auto x : p) cout << x.F << " " << x.S << endl; cout << endl
#define mod 				1e9 + 7

inline int power (int a, int b) {
	int x = 1;
	while (b) {
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

// You are given the array nums consisting of n positive integers. You computed the sum of
// all non-empty continuous subarrays from the array and then sorted them in non-decreasing
// order, creating a new array of n * (n + 1) / 2 numbers.
// Return the sum of the numbers from index left to index right (indexed from 1), inclusive,
// in the new array. Since the answer can be a huge number return it modulo 109 + 7.

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
    	int MOD = 1e9 + 7;
        vector<int> contSubArraySum;
        contSubArraySum.reserve(((n * (n + 1)) / 2));
        vector<int> cumSum((n + 1), 0);
        for(int i = 0; i < n; i++) cumSum[i + 1] = nums[i] + cumSum[i];
        for(int i = 0; i <= n; i++) {
        	for(int j = (i + 1); j <= n; j++) {
        		contSubArraySum.push_back(cumSum[j] - cumSum[i]);
        	}
        }
        sort(contSubArraySum.begin(), contSubArraySum.end());
        return accumulate(contSubArraySum.begin() + (left - 1), contSubArraySum.begin() + right, 0, [&MOD](int& a, int& b){ return (a + b) % MOD; });
    }
    // Optimized - Using Priority Queue
    int rangeSumOptimized(vector<int> &nums, int n, int left, int right) {
    	priority_queue< pair<int,int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    	int MOD = 1e9 + 7;
    	for(int i = 0; i < n; i++) {
    		// Store the index of Next Element to be Appended to Subarray
    		pq.push({nums[i], (i + 1)});
    	}
    	int ans = 0;
    	for(int i = 1; i <= right; i++) {
    		// Stop When we See "right" Smallest Subarrays' Sums
    		pair<int, int> p = pq.top();
    		pq.pop();
    		if(i >= left) {
    			// We Want the [left, right]th Subarray's Sum (Index: 1 Based)
    			ans = (ans + p.first) % MOD;
    		}
    		if(p.second < n) {
    			pq.push({(p.first + nums[p.second++]), p.second});
    		}
    	}
    	return ans;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums(n, 100);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int left; cin >> left;
	int right; cin >> right;
	Solution *soln = new Solution();
	int sum = soln->rangeSumOptimized(nums, n, left, right);
	cout << sum << nl;
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