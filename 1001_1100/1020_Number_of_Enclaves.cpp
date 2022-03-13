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

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1
// represents a land cell. A move consists of walking from one land cell to another
// adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary
// of the grid in any number of moves.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        // First Row
        for(int j = 0; j < n; j++) {
        	int i = 0;
        	if(grid[i][j] == 1) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 0;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n) && (grid[nr][nc] == 1)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 0;
        				}
        			}
        		}
        	}
        }
        // Last Row
        for(int j = 0; j < n; j++) {
        	int i = (m - 1);
        	if(grid[i][j] == 1) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 0;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n) && (grid[nr][nc] == 1)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 0;
        				}
        			}
        		}
        	}
        }
        // First Col
        for(int i = 0; i < m; i++) {
        	int j = 0;
        	if(grid[i][j] == 1) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 0;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n) && (grid[nr][nc] == 1)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 0;
        				}
        			}
        		}
        	}
        }
        // Last Col
        for(int i = 0; i < m; i++) {
        	int j = (n - 1);
        	if(grid[i][j] == 1) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 0;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n) && (grid[nr][nc] == 1)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 0;
        				}
        			}
        		}
        	}
        }
        // Check for Enclaves
        int enc = 0;
        for(int i = 1; i < (m - 1); i++) {
        	for(int j = 1; j < (n - 1); j++) {
        		if(grid[i][j] == 1) enc++;
        	}
        }
        return enc;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<int> > grid(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> grid[i][j];
	}	
	Solution *soln = new Solution();
	int enc = soln->numEnclaves(grid);
	cout << enc << nl;
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