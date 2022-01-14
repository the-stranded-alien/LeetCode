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

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

class Solution {
public:
	bool canPlaceQueen(int n, vector< vector<bool> > &board, int x, int y) {
		// Column
		for(int k = 0; k < x; k++) if(board[k][y]) return false;
		// Left Diagonal
		int i = x;
		int j = y;
		while((i >= 0) && (j >= 0)) {
			if(board[i][j]) return false;
			i--; j--;
		}
		// Right Diagonal
		i = x;
		j = y;
		while((i >= 0) && (j < n)) {
			if(board[i][j]) return false;
			i--; j++;
		}
		return true;
	}

	bool totalNQueensHelper(int n, int idx, vector< vector<bool> > &board, int &ways) {
		if(idx == n) {
			ways += 1;
			return false; // false : To find all solutions	
		}
		for(int j = 0; j < n; j++) {
			if(canPlaceQueen(n, board, idx, j)) {
				board[idx][j] = true;
				bool canPlace = totalNQueensHelper(n, (idx + 1), board, ways);
				if(canPlace) return true;
				board[idx][j] = false;
			}
		}
		return false;
	}

    int totalNQueens(int n) {
        vector< vector<bool> > board(n, vector<bool>(n, false));
    	int ways = 0;
    	bool canPlace = totalNQueensHelper(n, 0, board, ways);
    	return ways;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	Solution *soln = new Solution();
	int totalWays = soln->totalNQueens(n);
	cout << totalWays << nl;
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