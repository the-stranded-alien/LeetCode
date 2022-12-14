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

// You are given a 0-indexed integer array candies, where candies[i]
// represents the flavor of the ith candy. Your mom wants you to share
// these candies with your little sister by giving her k consecutive
// candies, but you want to keep as many flavors of candies as possible.
// Return the maximum number of unique flavors of candy you can keep
// after sharing with your sister.

class Solution {
public:
	int shareCandies(vector<int>& candies, int k) {
		int n = candies.size();
		unordered_map<int, int> map;
		for(auto candy : candies) map[candy]++;
		for(int i = 0; i <= k - 1; i++) {
			map[candies[i]]--;
			if(map[candies[i]] == 0) map.erase(candies[i]);
		}
		int mx = INT_MIN;
		for(int i = 1; i <= (n - k); i++) {
			int sz = map.size();
			mx = max(mx, sz);
			map[candies[i - 1]]++;
			map[candies[i + k - 1]]--;
			if(map[candies[i + k - 1]] == 0) map.erase(candies[i + k - 1]);
		}	
		mx = max(mx, (int) map.size());
		return mx;
    }
};

void solve() {
	// Main Code Goes Here !!
	int c; cin >> c;
	vector<int> candies(c);
	for(int i = 0; i < c; i++) cin >> candies[i];
	int k; cin >> k;
	
	Solution *soln = new Solution();
	cout << soln->shareCandies(candies, k);

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