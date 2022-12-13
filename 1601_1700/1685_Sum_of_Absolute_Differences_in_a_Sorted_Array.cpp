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

// You are given an integer array nums sorted in non-decreasing order.
// Build and return an integer array result with the same length as nums
// such that result[i] is equal to the summation of absolute differences
// between nums[i] and all the other elements in the array.
// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where
// 0 <= j < nums.length and j != i (0-indexed).

class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];

        vector<int> suffix(n, 0);
    	suffix[n - 1] = nums[n - 1];
    	for(int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + nums[i]; 

      	vector<int> result(n, 0);
      	for(int i = 0; i < n; i++) {
      		result[i] += (i > 0) ? abs(i * nums[i] - prefix[i - 1]) : 0;
      		result[i] += (i < n - 1) ? abs((n - i) * nums[i] - suffix[i]) : 0;
      	}
        return result;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	
	Solution *soln = new Solution();
	vi sol = soln->getSumAbsoluteDifferences(nums);
	for(auto s : sol) cout << s << " ";

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