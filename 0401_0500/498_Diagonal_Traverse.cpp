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

// Given an m x n matrix mat, return an array of all the elements
// of the array in a diagonal order.

class Solution {
public:
	bool isValid(int m, int n, int x, int y) {
		return ((x >= 0) && (x < m) && (y >= 0) && (y < n));
	}

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    	int m = mat.size();
    	int n = mat[0].size();
    	int row = 0;
    	int col = 0;
    	int dir = 1;
    	vector<int> diagonalOrder(m * n);
    	int itr = 0;
    	while((row < m) && (col < n)) {
    		diagonalOrder[itr++] = mat[row][col];
    		int newRow = row + (dir == 1 ? -1 : 1);
    		int newCol = col + (dir == 1 ? 1 : -1);
    		if(newRow < 0 || newRow == m || newCol < 0 || newCol == n) {
    			if(dir == 1) {
    				row += (col == n - 1 ? 1 : 0);
    				col += (col < n - 1 ? 1 : 0);
    			} else {
    				col += (row == m - 1 ? 1 : 0);
    				row += (row < m - 1 ? 1 : 0);
    			}
    			dir = 1 - dir;
    		} else {
    			row = newRow;
    			col = newCol;
    		}
    	}
    	return diagonalOrder;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<int> > mat(m, vector<int>(n));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	Solution *soln = new Solution();
	vi diagonalOrder = soln->findDiagonalOrder(mat);
	for(auto d : diagonalOrder) cout << d << " ";
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