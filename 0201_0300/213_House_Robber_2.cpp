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

// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed. All houses at this
// place are arranged in a circle. That means the first house is the
// neighbor of the last one. Meanwhile, adjacent houses have a security
// system connected, and it will automatically contact the police if two
// adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each
// house, return the maximum amount of money you can rob tonight without
// alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return 0;
		else if(n == 1) return nums[0];
		else if(n == 2) return max(nums[0], nums[1]);
		else {
			// Assume First House is Picked, We Cannot Pick the Last House.
			vector<int> dp1(n, 0);
			dp1[0] = nums[0];
        	dp1[1] = max(nums[0], nums[1]);
        	for(int i = 2; i < (n - 1); i++) {
        		dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
        	}
			// Assume First House is Not Picked, We Can Pick the Last House.
			vector<int> dp2(n, 0);
			dp2[1] = nums[1];
			dp2[2] = max(nums[1], nums[2]);
			for(int i = 3; i < n; i++) {
				dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
			}
			return max(dp1[n - 2], dp2[n - 1]);
		}
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	int maxAmt = soln->rob(nums);
	cout << maxAmt << nl;
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