#include<bits/stdc++.h>

using namespace std;

#define int 				long long int
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

// Given an integer array nums, find a contiguous non-empty subarray
// within the array that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit
// integer. A subarray is a contiguous subsequence of the array.

class Solution {
public:
    int maxProductES(vector<int>& nums) {
    	int n = nums.size();
    	if(n == 1) return nums[n - 1];
    	int maxSoFar = nums[0];
        vector<int> maxProduct(n, 0);
        vector<int> minProduct(n, 0);
        maxProduct[0] = nums[0];
        minProduct[0] = nums[0];
        for(int i = 1; i < n; i++) {
        	maxProduct[i] = max(nums[i], max((nums[i] * maxProduct[i - 1]), (nums[i] * minProduct[i - 1])));
        	minProduct[i] = min(nums[i], min((nums[i] * minProduct[i - 1]), (nums[i] * maxProduct[i - 1])));
        	maxSoFar = max(maxSoFar, maxProduct[i]);
        }
        return maxSoFar;
    }
    int maxProduct(vector<int>& nums) {
    	int n = nums.size();
    	if(n == 1) return nums[0];
    	int maxEndingHere = nums[0];
    	int minEndingHere = nums[0];
    	int maxSoFar = nums[0];
    	for(int i = 1; i < n; i++) {
    		int temp = max(nums[i], max(nums[i] * maxEndingHere, nums[i] * minEndingHere));
    		minEndingHere = min(nums[i], min(nums[i] * maxEndingHere, nums[i] * minEndingHere));
    		maxEndingHere = temp;
    		maxSoFar = max(maxSoFar, maxEndingHere);
    	}
    	return maxSoFar;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	int mp = soln->maxProduct(nums);
	cout << mp << nl;
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