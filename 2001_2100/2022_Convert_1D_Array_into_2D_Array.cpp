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


// You are given a 0-indexed 1-dimensional (1D) integer array original, and
// two integers, m and n. You are tasked with creating a 2-dimensional (2D)
// array with  m rows and n columns using all the elements from original.
// The elements from indices 0 to n - 1 (inclusive) of original should form
// the first row of the constructed 2D array, the elements from indices n to
// 2 * n - 1 (inclusive) should form the second row of the constructed 2D
// array, and so on. Return an m x n 2D array constructed according to the
// above procedure, or an empty 2D array if it is impossible.

class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int l = original.size();
        if(l != (m * n)) return {};
        vector<vector<int> > matrix(m, vector<int>(n, 0));
        for(int i = 0; i < l; i++) {
        	matrix[i / n][i % n] = original[i];
        }
        return matrix;
    }
};

void solve() {
	// Main Code Goes Here !!
	int o; cin >> o;
	vector<int> original(o);
	for(int i = 0; i < o; i++) cin >> original[i];
	int m; cin >> m;
	int n; cin >> n;
	
	Solution *soln = new Solution();
	vvi mat = soln->construct2DArray(original, m, n);
	for(auto row : mat) {
		for(auto col : row) cout << col << " ";
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