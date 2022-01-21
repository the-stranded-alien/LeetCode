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

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane,
// return the maximum number of points that lie on the same straight line.

class Solution {
public:
	bool pointLiesOnLine(pair<int, int> p3, pair<int, int> p1, pair<int, int> p2) {
		int areaTri = p1.first * (p2.second - p3.second) +
					p2.first * (p3.second - p1.second) + 
					p3.first * (p1.second - p2.second);
		if(areaTri == 0) return true;
		else return false;
	}

    int maxPoints(vector<vector<int>>& points) {
    	int np = points.size();
    	if(np >= 0 && np <= 2) return np; 
    	int maxLen = 0;
    	for(int i = 0; i < np; i++) {
    		for(int j = (i + 1); j < np; j++) {
    			pair<int, int> p1 = {points[i][0], points[i][1]};
    			pair<int, int> p2 = {points[j][0], points[j][1]};
    			int curLine = 2;
    			for(int k = 0; k < np; k++) {
    				if((i != k) && (j != k)) {
    					pair<int, int> p3 = {points[k][0], points[k][1]};
    					if(pointLiesOnLine(p3, p1, p2)) curLine++;
    				}
    			}
    			if(maxLen < curLine) maxLen = curLine;
    		}
    	}
    	return maxLen;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vvi points(n, vector<int>(2, 0));
	for(int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];
	Solution *soln = new Solution();
	int maxPointsOnALine = soln->maxPoints(points);
	cout << maxPointsOnALine << nl;
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