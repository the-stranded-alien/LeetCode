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

// An axis-aligned rectangle is represented as a list [x1, y1, x2, y2],
// where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2)
// is the coordinate of its top-right corner. Its top and bottom edges are
// parallel to the X-axis, and its left and right edges are parallel to the Y-axis.
// Two rectangles overlap if the area of their intersection is positive. To be clear,
// two rectangles that only touch at the corner or edges do not overlap.
// Given two axis-aligned rectangles rec1 and rec2, return true if they overlap,
// otherwise return false.

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int r1x1 = rec1[0], r1y1 = rec1[1], r1x2 = rec1[2], r1y2 = rec1[3];
        int r2x1 = rec2[0], r2y1 = rec2[1], r2x2 = rec2[2], r2y2 = rec2[3];
    
        // Zero Area Rectangle
        if((r1x1 == r1x2) || (r1y1 == r1y2) || (r2x1 == r2x2) || (r2y1 == r2y2)) return false;

        return !((r1x2 <= r2x1) // Left
        	|| (r1x1 >= r2x2) // Right
        	|| (r1y2 <= r2y1) // Top
        	|| (r1y1 >= r2y2) // Bottom
        	);
    }	
};

void solve() {
	// Main Code Goes Here !!
	const int n = 4;
	vi rec1(n);
	vi rec2(n);
	for(int i = 0; i < n; i++) cin >> rec1[i];
	for(int i = 0; i < n; i++) cin >> rec2[i];
	
	Solution *soln = new Solution();
	cout << soln->isRectangleOverlap(rec1, rec2);

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