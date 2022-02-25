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

// Given a wooden stick of length n units. The stick is labelled from 0 to n.
// For example, a stick of length 6 is labelled as follows:
// Given an integer array cuts where cuts[i] denotes a position you should
// perform a cut at. You should perform the cuts in order, you can change the
// order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is
// the sum of costs of all cuts. When you cut a stick, it will be split into
// two smaller sticks (i.e. the sum of their lengths is the length of the stick
// before the cut). Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.

// 2 <= n <= 106
// 1 <= cuts.length <= min(n - 1, 100)
// 1 <= cuts[i] <= n - 1
// All the integers in cuts array are distinct.

class Solution {
public:
	int minCostHelper(int s, int e, vector<int> &cuts, vector< vector<int> > &dp, int csi, int cei) {
		if(csi > cei) return 0;
		if(dp[csi][cei] != -1) return dp[csi][cei];
		int minSubCost = INT_MAX;
		for(int k = csi; k <= cei; k++) {
			minSubCost = min(minSubCost, (minCostHelper(s, cuts[k], cuts, dp, csi, k - 1) + minCostHelper(cuts[k], e, cuts, dp, k + 1, cei)));
		}
		return (dp[csi][cei] = (e - s) + minSubCost);
	}

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size() + 1;
        vector< vector<int> > dp(c, vector<int>(c, -1));
        int cut_start_itr = 0;
        int cut_end_itr = cuts.size() - 1;
        sort(cuts.begin(), cuts.end());
        return minCostHelper(0, n, cuts, dp, cut_start_itr, cut_end_itr);
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	int c; cin >> c;
	vi cuts(c, 0);
	for(int i = 0; i < c; i++) cin >> cuts[i];
	Solution *soln = new Solution();
	int mc = soln->minCost(n, cuts);
	cout << mc << nl;
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