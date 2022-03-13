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

// You are given two integers, x and y, which represent your current location on a
// Cartesian grid: (x, y). You are also given an array points where each points[i]
// = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it
// shares the same x-coordinate or the same y-coordinate as your location.
// Return the index (0-indexed) of the valid point with the smallest Manhattan
// distance from your current location. If there are multiple, return the valid
// point with the smallest index. If there are no valid points, return -1.
// The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2)
// + abs(y1 - y2).

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDist = INT_MAX;
        int minPoint = -1;
        for(int i = 0; i < points.size(); i++) {
        	int curPx = points[i][0];
        	int curPy = points[i][1];
        	if(curPx == x || curPy == y) {
        		int manhattan = abs(curPx - x) + abs(curPy - y);
        		if(manhattan < minDist) {
        			minDist = manhattan;
        			minPoint = i;
        		}
        	}
        }
        return minPoint;
    }
};

void solve() {
	// Main Code Goes Here !!
	int x; cin >> x;
	int y; cin >> y;
	int p; cin >> p;
	vector< vector<int> > points(p, vector<int>(2, 0));
	for(int i = 0; i < p; i++) cin >> points[i][0] >> points[i][1];
	Solution *soln = new Solution();
	int nvp = soln->nearestValidPoint(x, y, points);
	cout << nvp << nl;
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