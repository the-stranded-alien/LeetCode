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

// An image is represented by an m x n integer grid image where image[i][j]
// represents the pixel value of the image. You are also given three
// integers sr, sc, and newColor. You should perform a flood fill on the
// image starting from the pixel image[sr][sc]. To perform a flood fill,
// consider the starting pixel, plus any pixels connected 4-directionally
// to the starting pixel of the same color as the starting pixel, plus any
// pixels connected 4-directionally to those pixels (also with the same
// color), and so on. Replace the color of all of the aforementioned pixels
// with newColor. Return the modified image after performing the flood fill.

class Solution {
public:
	void dfs(vector<vector<int>> &image, int r, int c, int curColor, int newColor, int m, int n) {
		if(image[r][c] == curColor) {
			image[r][c] = newColor;
			if(r >= 1) dfs(image, (r - 1), c, curColor, newColor, m, n);
			if(c >= 1) dfs(image, r, (c - 1), curColor, newColor, m, n);
			if(r + 1 < m) dfs(image, (r + 1), c, curColor, newColor, m, n);
			if(c + 1 < n) dfs(image, r, (c + 1), curColor, newColor, m, n);
		}
		return;
	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
    	int curColor = image[sr][sc];
    	if(curColor != newColor) dfs(image, sr, sc, curColor, newColor, m, n);
    	return image;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m, n;
	cin >> m >> n;
	vector< vector<int> > image(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> image[i][j];
	}	
	int sr; cin >> sr;
	int sc; cin >> sc;
	int newColor; cin >> newColor;
	Solution *soln = new Solution();
	vvi floodFillImage = soln->floodFill(image, sr, sc, newColor);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cout << floodFillImage[i][j] << " ";
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