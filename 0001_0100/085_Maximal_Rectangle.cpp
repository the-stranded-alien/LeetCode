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

// Given a rows x cols binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int maxArea = 0;
        vector< vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(matrix[i][j] == '1') {
        			// Compute the maximum width and update dp with it
        			dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;
        			int width = dp[i][j];
        			// Compute the maximum area rectangle with a lower right corner at [i, j]
        			for(int k = i; k >= 0; k--) {
        				width = min(width, dp[k][j]);
        				maxArea = max(maxArea, (width * (i - k + 1)));
        			}
        		}
        	}
        }
        return maxArea;
    }
    int maxAreaHistogram(vector<int> &heights) {
    	int n = heights.size();
        stack<int> stk;
        int maxArea = 0;
        int areaWithTop = 0;
        int tp;
        int i = 0;
        while(i < n) {
        	if(stk.empty() || heights[stk.top()] <= heights[i]) stk.push(i++);
       		else {
       			tp = stk.top();
       			stk.pop();
       			areaWithTop = heights[tp] * (stk.empty() ? i : (i - stk.top() - 1));
       			if(maxArea < areaWithTop) maxArea = areaWithTop;
       		}
        }
        while(!stk.empty()) {
        	tp = stk.top();
        	stk.pop();
        	areaWithTop = heights[tp] * (stk.empty() ? i : i - stk.top() - 1);
       		if(maxArea < areaWithTop) maxArea = areaWithTop;
        }
        return maxArea;
    }
    // Monotonic Stack
    int maximalRectangleMS(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
    	int maxArea = 0;
    	vector<int> dp(n, 0);
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
    		}
    		maxArea = max(maxArea, maxAreaHistogram(dp));
    	}
    	return maxArea;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector<vector<char> > matrix(m, vector<char>(n, ' '));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> matrix[i][j];
	}
	Solution *soln = new Solution();
	int mr = soln->maximalRectangle(matrix);
	cout << mr << nl;
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