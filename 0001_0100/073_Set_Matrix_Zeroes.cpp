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

// Given an m x n integer matrix matrix,
// if an element is 0, set its entire row and column
// to 0's, and return the matrix. You must do it in place.
// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set< pair<int, int> > zeroPoints;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(matrix[i][j] == 0) zeroPoints.insert({i, j});
			}
		}
		for(auto xy : zeroPoints) {
			int x = xy.first;
			int y = xy.second;
			for(int k = 0; k < m; k++) matrix[k][y] = 0;
			for(int k = 0; k < n; k++) matrix[x][k] = 0;
		}
		return;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vvi matrix(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	Solution *soln = new Solution();
	soln->setZeroes(matrix);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << nl;
	}
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