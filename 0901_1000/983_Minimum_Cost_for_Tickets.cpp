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

// You have planned some train traveling one year in advance.
// The days of the year in which you will travel are given as
// an integer array days. Each day is an integer from 1 to 365.
// Train tickets are sold in three different ways:
// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.
// For example, if we get a 7-day pass on day 2, then we can
// travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel
// every day in the given list of days.

class Solution {
public:
	int mincostTicketsHelper(int day, vector<int> &dp, unordered_set<int> &daySet, vector<int> &costs) {
		if(day > 365) return 0;
		if(dp[day] != -1) return dp[day];
		int ans;
		if(daySet.find(day) != daySet.end()) {
			ans = min(mincostTicketsHelper(day + 1, dp, daySet, costs) + costs[0],
				min(mincostTicketsHelper(day + 7, dp, daySet, costs) + costs[1], mincostTicketsHelper(day + 30, dp, daySet, costs) + costs[2]));
		} else {
			ans = mincostTicketsHelper(day + 1, dp, daySet, costs);
		}
		return (dp[day] = ans);
	}

	int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        unordered_set<int> daySet(days.begin(), days.end());
        return mincostTicketsHelper(1, dp, daySet, costs);
    }
};

void solve() {
	// Main Code Goes Here !!
	int d; cin >> d;
	vi days(d);
	for(int i = 0; i < d; i++) cin >> days[i];
	vi costs(3);
	cin >> costs[0] >> costs[1] >> costs[2];	
	Solution *soln = new Solution();
	cout << soln->mincostTickets(days, costs);

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