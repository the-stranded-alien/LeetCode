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

// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More
// formally, if you are on index i on the current row, you may move to either
// index i or index i + 1 on the next row.

class Solution {
public:
	int minimumTotalHelper(vector<vector<int>> &tri, int rowItr, int idx, vector<vector<int>> &dp) {
		if(tri.size() == rowItr) return 0;
		if(dp[rowItr][idx] != -1) return dp[rowItr][idx];
		int op1 = minimumTotalHelper(tri, (rowItr + 1), idx, dp);
		int op2 = minimumTotalHelper(tri, (rowItr + 1), (idx + 1), dp);
		return (dp[rowItr][idx] = tri[rowItr][idx] + min(op1, op2));
	}

    int minimumTotal(vector<vector<int>>& triangle) {
    	int n = triangle.size();
    	vector< vector<int> > dp(n, vector<int>(triangle[n - 1].size(), -1));
    	return minimumTotalHelper(triangle, 0, 0, dp);
    }
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	vvi triangle;
	triangle.reserve(n);
	for(int i = 1; i <= n; i++) {
		vi temp(i, 0);
		for(int j = 0; j < i; j++) cin >> temp[j];
		triangle.push_back(temp);
		temp.clear();
	}
	Solution *soln =  new Solution();
	int minPathSum = soln->minimumTotal(triangle);
	cout << minPathSum << nl;
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