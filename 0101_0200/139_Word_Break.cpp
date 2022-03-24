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

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented
// into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

class Solution {
public:
	bool wordBreakMemo(string s, set<string> &wordSet, int startItr, vector<int> &memo) {
		if(itr == s.length()) return true;
		if(memo[startItr] != -1) return memo[startItr];
		for(int endItr = startItr + 1; endItr <= s.length(); endItr++) {
			if(wordSet.find(s.substr(startItr, endItr - startItr)) != wordSet.end()
				&& wordBreakMemo(s, wordSet, endItr, memo)) return memo[startItr] = true;
		}
		return memo[start] = false;
	}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);
        return wordBreakMemo(s, wordSet, 0, memo);
    }

    bool wordBreakDP(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
    	vector<bool> dp(s.length() + 1);
    	dp[0] = true;
    	for(int i = 1; i <= s.length(); i++) {
    		for(int j = 0; j < i; j++) {
    			if(dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}
    	return dp[s.length()];
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	int d; cin >> d;
	vs wordDict(d, " ");	
	for(int i = 0; i < d; i++) cin >> wordDict[i];
	Solution *soln = new Solution();
	bool canBeSegmented = soln->wordDict(s, wordDict);
	if(canBeSegmented) cout << "true\n";
	else cout << "false\n";
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