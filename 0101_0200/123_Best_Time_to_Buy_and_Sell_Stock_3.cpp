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

// You are given an array prices where prices[i] is the price of a given
// stock on the ith day. Find the maximum profit you can achieve. You may
// complete at most two transactions. Note: You may not engage in multiple
// transactions simultaneously (i.e., you must sell the stock before you
// buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int leftMin = prices[0];
        int rightMax = prices[n - 1];
        vector<int> leftProfits(n, 0);
        vector<int> rightProfits((n + 1), 0);
        for(int i = 1; i < n; i++) {
        	leftProfits[i] = max(leftProfits[i - 1], (prices[i] - leftMin));
        	leftMin = min(leftMin, prices[i]);
        	int j = n - 1 - i;
        	rightProfits[j] = max(rightProfits[j + 1], rightMax - prices[j]);
        	rightMax = max(rightMax, prices[j]);
        }
        int maxProfit = 0;
        for(int i = 0; i < n; i++) {
        	maxProfit = max(maxProfit, (leftProfits[i] + rightProfits[i + 1]));
        }
        return maxProfit;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> prices(n, 0);
	for(int i = 0; i < n; i++) cin >> prices[i];	
	Solution *soln = new Solution();
	int mp = soln->maxProfit(prices);
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