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

// Given a 2D grid consists of 0s (land) and 1s (water).  An island is
// a maximal 4-directionally connected group of 0s and a closed island
// is an island totally (all left, top, right, bottom) surrounded by 1s.
// Return the number of closed islands.

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        int m = grid.size();
        int n = grid[0].size();
        int closedIslands = 0;
        for(int i = 0; i < m; i++) {
        	int j = 0;
        	if(grid[i][j] == 0) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 1;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n)
        					&& (grid[nr][nc] == 0)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 1;
        				}

        			}
        		}
        	}
        }
        for(int i = 0; i < m; i++) {
        	int j = (n - 1);
        	if(grid[i][j] == 0) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 1;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n)
        					&& (grid[nr][nc] == 0)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 1;
        				}

        			}
        		}
        	}
        }
        for(int j = 0; j < n; j++) {
        	int i = 0;
        	if(grid[i][j] == 0) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 1;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n)
        					&& (grid[nr][nc] == 0)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 1;
        				}

        			}
        		}
        	}
        }
        for(int j = 0; j < n; j++) {
        	int i = (m - 1);
        	if(grid[i][j] == 0) {
        		stack< pair<int, int> > stk;
        		stk.push({i, j});
        		grid[i][j] = 1;
        		while(!stk.empty()) {
        			pair<int, int> pr = stk.top();
        			stk.pop();
        			int r = pr.first;
        			int c = pr.second;
        			for(int k = 0; k < 4; k++) {
        				int nr = r + dr[k];
        				int nc = c + dc[k];
        				if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n)
        					&& (grid[nr][nc] == 0)) {
        					stk.push({nr, nc});
        					grid[nr][nc] = 1;
        				}

        			}
        		}
        	}
        }
        for(int i = 1; i < (m - 1); i++) {
        	for(int j = 1; j < (n - 1); j++) {
        		if(grid[i][j] == 0) {
        			stack< pair<int, int> > stk;
        			stk.push({i, j});
        			grid[i][j] = 1;
        			closedIslands++;
        			while(!stk.empty()) {
        				pair<int, int> pr = stk.top();
        				stk.pop();
        				int r = pr.first;
        				int c = pr.second;
        				for(int k = 0; k < 4; k++) {
        					int nr = r + dr[k];
        					int nc = c + dc[k];
        					if((0 <= nr) && (nr < m) && (0 <= nc) && (nc < n)
        						&& (grid[nr][nc] == 0)) {
        						stk.push({nr, nc});
        						grid[nr][nc] = 1;
        					}
        				}
        			}
        		}
        	}
        }
        return closedIslands;
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
	int ci = soln->closedIsland(grid);
	cout << ci << nl;
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