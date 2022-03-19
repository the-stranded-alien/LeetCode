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

// Given an m x n binary matrix mat, return the distance
// of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m == 0) return mat;
        int n = mat[0].size();
        vector< vector<int> > dist(m, vector<int>(n, INT_MAX - 100000));
        // Check for Left & Top
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(mat[i][j] == 0) dist[i][j] = 0;
        		else {
        			if(i > 0) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
        			if(j > 0) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
        		}
        	}
        }
        // Check for Right & Bottom
        for(int i = m - 1; i >= 0; i--) {
        	for(int j = n - 1; j >= 0; j--) {
        		if(i < m - 1) dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
    	    	if(j < n - 1) dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        	}
        }
        return dist;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<int> > mat(m, vector<int>(n, 0));	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> mat[i][j];
	}
	Solution *soln = new Solution();
	vvi dist = soln->updateMatrix(mat);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cout << dist[i][j] << " ";
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