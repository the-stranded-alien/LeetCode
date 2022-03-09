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

// A robot is located at the top-left corner of a m x n grid (marked 'Start'
// in the diagram below). The robot can only move either down or right at
// any point in time. The robot is trying to reach the bottom-right corner
// of the grid (marked 'Finish' in the diagram below). Now consider if some
// obstacles are added to the grids. How many unique paths would there be?
// An obstacle and space is marked as 1 and 0 respectively in the grid.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]) return 0;
        if(m == 1 && n == 1) {
        	return (obstacleGrid[0][0] == 1) ? 0 : 1;
        } 
        vector< vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int j = 1; j < n; j++) {
        	if(obstacleGrid[0][j]) dp[0][j] = 0;
        	else dp[0][j] = dp[0][j - 1];
        }
        for(int i = 1; i < m; i++) {
        	if(obstacleGrid[i][0]) dp[i][0] = 0;
        	else dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i < m; i++) {
        	for(int j = 1; j < n; j++) {
        		if(!obstacleGrid[i][j]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        		else dp[i][j] = 0;
        	}
        }
        return dp[m - 1][n - 1];
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<int> > obstacleGrid(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> obstacleGrid[i][j];
	}
	Solution *soln = new Solution();
	int up = soln->uniquePathsWithObstacles(obstacleGrid);
	cout << up << nl;
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