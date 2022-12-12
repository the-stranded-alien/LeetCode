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

// You are given an integer array prices where prices[i] is the price of
// the ith item in a shop.
// There is a special discount for items in the shop. If you
// buy the ith item, then you will receive a discount equivalent to 
// prices[j] where j is the minimum index such that j > i and
// prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
// Return an integer array answer where answer[i] is the final price you
// will pay for the ith item of the shop, considering the special discount.

class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> stk; // to store index
        vector<int> finalPrice(n);
        for(int i = 0; i < n; i++) {
        	while(!stk.empty() && prices[stk.top()] >= prices[i]) {
        		finalPrice[stk.top()] = prices[stk.top()] - prices[i];
        		stk.pop();
        	}
        	stk.push(i);
        }
        if(stk.size() == prices.size()) return prices;
        while(!stk.empty()) {
        	finalPrice[stk.top()] = prices[stk.top()];
    		stk.pop();
    	}
        return finalPrice;
    }
};

void solve() {
	// Main Code Goes Here !!
	int p; cin >> p;
	vi prices(p);
	for(int i = 0; i < p; i++) cin >> prices[i];
	
	Solution *soln = new Solution();
	vi fp = soln->finalPrices(prices);
	for(auto f : fp) cout << f << " ";

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