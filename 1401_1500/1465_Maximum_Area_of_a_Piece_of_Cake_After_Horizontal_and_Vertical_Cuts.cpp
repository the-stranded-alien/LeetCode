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

// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts
// and verticalCuts where: horizontalCuts[i] is the distance from the top of the rectangular
// cake to the ith horizontal cut and similarly, and verticalCuts[j] is the distance from the
// left of the rectangular cake to the jth vertical cut. Return the maximum area of a piece
// of cake after you cut at each horizontal and vertical position provided in the arrays
// horizontalCuts and verticalCuts. Since the answer can be a large number, return this
// modulo 109 + 7.

class Solution {
public:
	int moduloMultiplication(int a, int b) {
  		const int MOD = (1e9 + 7);
  		int res = 0;
  		a %= MOD;
  		while(b) {
  			if(b & 1) res = (res + a) % MOD;
  			a = (2 * a) % MOD;
  			b >>= 1;
  		}
  		return res;
	}

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
  		horizontalCuts.push_back(0);
  		horizontalCuts.push_back(h);
  		verticalCuts.push_back(0);
  		verticalCuts.push_back(w);
  		sort(horizontalCuts.begin(), horizontalCuts.end());
  		sort(verticalCuts.begin(), verticalCuts.end());
  		int maxHC = 0;
  		int maxVC = 0;
  		for(int i = 0; i < (horizontalCuts.size() - 1); i++) {
  			int cur = horizontalCuts[i + 1] - horizontalCuts[i];
  			maxHC = max(maxHC, cur);
  		}
  		for(int i = 0; i < (verticalCuts.size() - 1); i++) {
  			int cur = verticalCuts[i + 1] - verticalCuts[i];
  			maxVC = max(maxVC, cur);
  		}
  		return moduloMultiplication(maxHC, maxVC);
    }
};

void solve() {
	// Main Code Goes Here !!
	int h; cin >> h;
	int w; cin >> w;
	int hc; cin >> hc;
	vector<int> horizontalCuts(hc, 0);
	for(int i = 0; i < hc; i++) cin >> horizontalCuts[i];
	int vc; cin >> vc;
	vector<int> verticalCuts(vc, 0);
	for(int i = 0; i < vc; i++) cin >> verticalCuts[i];
	Solution *soln = new Solution();
	int ma = soln->maxArea(h, w, horizontalCuts, verticalCuts);
	cout << ma << nl;
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