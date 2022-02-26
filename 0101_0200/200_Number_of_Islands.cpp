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

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
// return the number of islands. An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.

class DSU {
private:
	vector<int> parent;
	vector<int> rank;
	int numCC;
public:
	DSU(vector< vector<char> > &grid) {
		numCC = 0;
		int m = grid.size();
		int n = grid[0].size();
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == '1') {
					parent.push_back((i * n) + j);
					numCC++;
				} else parent.push_back(-1);
				rank.push_back(0);
			}
		}
	}
	// Path Compression
	int find(int i) {
		if(parent[i] != i) return (parent[i] = find(parent[i]));
		return parent[i];
	}
	// Union By Rank
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if(s1 != s2) {
			if(rank[s1] > rank[s2]) parent[s2] = s1;
			else if(rank[s1] < rank[s2]) parent[s1] = s2;
			else { parent[s2] = s1; rank[s1] += 1; }
			numCC--;
		}
		return;
	}
	int getNumComp() {
		return numCC;
	}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr) return 0;
        int nc = grid[0].size();
        DSU dsu(grid);
        int numIslands = 0;
        for (int r = 0; r < nr; ++r) {
      		for (int c = 0; c < nc; ++c) {
        		if (grid[r][c] == '1') {
         			grid[r][c] = '0';
          			if (r - 1 >= 0 && grid[r-1][c] == '1') dsu.unite(r * nc + c, (r-1) * nc + c);
          			if (r + 1 < nr && grid[r+1][c] == '1') dsu.unite(r * nc + c, (r+1) * nc + c);
          			if (c - 1 >= 0 && grid[r][c-1] == '1') dsu.unite(r * nc + c, r * nc + c - 1);
          			if (c + 1 < nc && grid[r][c+1] == '1') dsu.unite(r * nc + c, r * nc + c + 1);
        		}
      		}	
    	}
    	return dsu.getNumComp();
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<char> > grid(m, vector<char>(n, ' '));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> grid[i][j];
	}
	Solution *soln = new Solution();
	int num = soln->numIslands(grid);
	cout << num << nl;
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