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

// Given an array of positive integers nums, remove the smallest subarray
// (possibly empty) such that the sum of the remaining elements is divisible
// by p. It is not allowed to remove the whole array.
// Return the length of the smallest subarray that you need to remove,
// or -1 if it's impossible.
// A subarray is defined as a contiguous block of elements in the array.

class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
    	int mod = 0;
    	int rem = 0;
    	int minWidth = nums.size();
    	for(auto num : nums) mod = (mod + n) % p;
    	if(mod == 0) return 0;
    	unordered_map<int, int> pos = {{0, -1}};
    	for(int i = 0; i < nums.size(); i++) {
    		rem = (rem + nums[i]) % p;
    		int comp = (p - mod + rem) % p;
    		if(pos.count(comp)) minWidth = min(minWidth, i - pos[comp]);
    		pos[rem] = i;
    	}
    	return (minWidth >= nums.size() ? -1 : minWidth);	
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int p; cin >> p;

	Solution *soln = new Solution();
	cout << soln->minSubarray(nums, p);

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