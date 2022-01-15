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

// Given two strings word1 and word2, return the minimum number of operations required
// to convert word1 to word2.
// You have the following three operations permitted on a word:
// 1. Insert a character
// 2. Delete a character
// 3. Replace a character

class Solution {
public:
	// Top Down DP 
	int minDistanceHelper(string word1, string word2, int i, int j, vector<vector<int>> &dp) {
		if(i == 0) return j;
		else if(j == 0) return i;
		else if(dp[i - 1][j - 1] != -1) return dp[i - 1][j - 1];
		else if(word1[i - 1] == word2[j - 1]) {
			return (dp[i - 1][j - 1] = minDistanceHelper(word1, word2, (i - 1), (j - 1), dp));
		} else {
			int insert = minDistanceHelper(word1, word2, i, (j - 1), dp);
			int del = minDistanceHelper(word1, word2, (i - 1), j, dp);
			int replace = minDistanceHelper(word1, word2, (i - 1), (j - 1), dp);
			return (dp[i - 1][j - 1] = 1 + min(insert, min(del, replace)));
		}
	}

    int minDistanceTD(string word1, string word2) {
    	int l1 = word1.length();
    	int l2 = word2.length();
    	vector< vector<int> > dp(l1, vector<int>(l2, -1));
    	int minDist = minDistanceHelper(word1, word2, l1, l2, dp);
    	return minDist;
    }

    // Bottom Up DP (Faster)
    int minDistance(string word1, string word2) {
    	int l1 = word1.length();
    	int l2 = word2.length();
    	vector< vector<int> > dp((l1 + 1), vector<int>((l2 + 1), 0));
    	for(int i = 0; i <= l1; i++) {
    		for(int j = 0; j <= l2; j++) {
    			if(i == 0) dp[i][j] = j;
    			else if(j == 0) dp[i][j] = i;
    			else if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
    			else dp[i][j] = (1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])));
    		}
    	}
    	// for(int i = 0; i <= l1; i++) {
    	// 	for(int j = 0; j <= l2; j++) {
    	// 		cout << dp[i][j] << " ";
    	// 	} cout << nl;
    	// }
    	return dp[l1][l2];
    }
};

void solve() {
	// Main Code Goes Here !!
	string s1;
	cin >> s1;
	string s2;
	cin >> s2;
	Solution *soln = new Solution();
	int minDist = soln->minDistance(s1, s2);
	cout << minDist << nl;
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