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

// Given an array of points where points[i] = [xi, yi] represents a point on the
// X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance
// (i.e., √(x1 - x2)2 + (y1 - y2)2). You may return the answer in any order.
// The answer is guaranteed to be unique (except for the order that it is in).

class Solution {
public:

	struct sortByDist {
		bool operator()(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2) {
			return (p1.first > p2.first);
		}
	};

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  		vector< vector<int> > kClosestPoints;
  		kClosestPoints.reserve(k);
  		priority_queue< pair<int, pair<int, int> > , vector< pair<int, pair<int, int> > >, sortByDist> pq;
  		for(auto point : points) {
  			int distFromOrigin = (point[0] * point[0]) + (point[1] * point[1]);
  			pq.push(make_pair(distFromOrigin, make_pair(point[0], point[1])));
  		}
  		while(k--) {
  			auto tp = pq.top();
  			kClosestPoints.push_back({tp.second.first, tp.second.second});
  			pq.pop();
  		}
  		return kClosestPoints;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vvi points(n, {0, 0});
	for(int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];
	int k; cin >> k;
	Solution *soln = new Solution();
	vvi kClosestPoints = soln->kClosest(points, k);
	for(auto p : kClosestPoints) cout << p[0] << ", " << p[1] << nl;
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