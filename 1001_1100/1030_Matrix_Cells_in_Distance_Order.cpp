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

// You are given four integers row, cols, rCenter, and cCenter. There is a
// rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).
// Return the coordinates of all cells in the matrix, sorted by their
// distance from (rCenter, cCenter) from the smallest distance to the
// largest distance. You may return the answer in any order that satisfies
// this condition. The distance between two cells (r1, c1) and (r2, c2)
// is |r1 - r2| + |c1 - c2|.

class Solution {
public:
	int distance(pair<int, int> p1, pair<int, int> p2) {
		return abs(p1.first - p2.first) + abs(p1.second - p2.second);
	}

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    	pair<int, int> center{rCenter, cCenter};
    	vector< pair<int, pair<int, int> > > distCordPairs;
    	for(int i = 0; i < rows; i++) {
    		for(int j = 0; j < cols; j++) {
    			pair<int, int> curCord{i, j};
    			int dist = distance(center, curCord);
    			distCordPairs.push_back({dist, {i, j}});
    		}
    	}
    	sort(distCordPairs.begin(), distCordPairs.end());
    	vector<vector<int> > acd;
    	for(auto dcp : distCordPairs) {
    		acd.push_back({dcp.second.first, dcp.second.second});
    	}
    	return acd;
    }
};

void solve() {
	// Main Code Goes Here !!
	int rows; cin >> rows;
	int cols; cin >> cols;
	int rCenter; cin >> rCenter;
	int cCenter; cin >> cCenter;	
	Solution *soln = new Solution();
	vvi acd = soln->allCellsDistOrder(rows, cols, rCenter, cCenter);
	for(auto c : acd) cout << c[0] << " - " << c[1] << nl;
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