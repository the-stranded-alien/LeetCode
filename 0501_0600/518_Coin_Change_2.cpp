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

// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

class Solution {
public:
	int changeHelper(int amount, vector<int> &coins, int idx) {
		if(amount == 0) return 1;
		if(amount < 0) return 0;
		if(idx <= 0 && amount >= 1) return 0;
		return (changeHelper(amount, coins, idx - 1) +
			   changeHelper(amount - coins[idx - 1], coins, idx));
	}

	int changeHelperDPTD(int amount, vector<int> &coins, int idx, vector<vector<int>> &dp) {
		if(amount == 0) return (dp[idx][amount] = 1);
		if(idx == 0) return 0;
		if(dp[idx][amount] != -1) return dp[idx][amount];
		if(coins[idx - 1] <= amount) {
			// Either Pick Coin or Not
			return (dp[idx][amount] = changeHelperDPTD(amount - coins[idx - 1], coins, idx, dp) 
				+ changeHelperDPTD(amount, coins, idx - 1, dp));
		} else {
			// Leave The Coin
			return (dp[idx][amount] = changeHelperDPTD(amount, coins, idx - 1, dp));
		}
	}

	int changeHelperDPBU(int amount, vector<int> &coins, int idx) {
		vector< vector<int> > dp(amount + 1, vector<int>(idx, 0)); 
		for(int i = 0; i < idx; i++) dp[0][i] = 1;
		for(int i = 1; i < (amount + 1); i++) {
			for(int j = 0; j < idx; j++) {
				// Include coins[j]
				int x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
				// Exclude coins[j]
				int y = (j >= 1) ? dp[i][j - 1] : 0;
				dp[i][j] = x + y;
			}
		}
		return dp[amount][idx - 1];	
	}

    int change(int amount, vector<int>& coins) {
    	vector< vector<int> > dp((coins.size() + 1), vector<int>((amount + 1), -1));
    	return changeHelperDPTD(amount, coins, coins.size(), dp);
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi coins(n, 0);
	for(int i = 0; i < n; i++) cin >> coins[i];
	int amt; cin >> amt;
	Solution *soln = new Solution();
	int ways = soln->change(amt, coins);
	cout << ways << nl;
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