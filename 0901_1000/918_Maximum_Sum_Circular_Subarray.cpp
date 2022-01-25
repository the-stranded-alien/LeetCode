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

// Given a circular integer array nums of length n, return the maximum
// possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning
// of the array. Formally, the next element of nums[i] is nums[(i + 1) % n]
// and the previous element of nums[i] is nums[(i - 1 + n) % n].
// A subarray may only include each element of the fixed buffer nums at
// most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j],
// there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

class Solution {
public:

	// Kadane's Algorithm for Max Subarray Sum
	int kadaneAlgorithm(vector<int> &nums) {
    	int n = nums.size();
    	int current_sum = 0;
    	int max_so_far = 0;
    	for(int i = 0; i < n; i++) {
    		current_sum += nums[i];
    		if(current_sum < 0) current_sum = 0;
    		else max_so_far = max(current_sum, max_so_far);
    	}
    	return max_so_far;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
    	int n = nums.size();
    	// Special Case -> All Numbers Are Negative
    	bool pos = false;
    	int minimum = INT_MIN;
    	for(auto num : nums) {
    		if(num >= 0) {
    			pos = true;
    			break;
    		} else {
    			if(num > minimum) minimum = num;
    		}
    	}
    	if(!pos) return minimum;
        // Case 1 : Get Max Sum Using Standard Kadane's Algorithm
        int maxKadane = kadaneAlgorithm(nums);
        if(maxKadane < 0) return maxKadane;
        // Case 2 : Find Maximum Sum That Includes 
        // Corner Elements (Circular Array)
        int maxWrap = 0;
        for(int i = 0; i < n; i++) {
        	maxWrap += nums[i];
        	nums[i] = -nums[i];
        }
        maxWrap = maxWrap + kadaneAlgorithm(nums);
    	return (maxWrap > maxKadane) ? maxWrap : maxKadane;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	int mssc = soln->maxSubarraySumCircular(nums);
	cout << mssc << nl;
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