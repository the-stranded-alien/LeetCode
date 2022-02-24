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

// Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:
	// Optimization : Storing the last occurence of current char
	// Lookup : unordered_map, Start a new window, Expand your current window. 
    int lengthOfLongestSubstring(string s) {
    	int ptr1 = 0;
    	int ptr2 = 0;
    	int curWinLen = 0;
    	int maxWinLen = 0;
    	int startWin = -1;
    	unordered_map<char, int> lookupMap;
		while(ptr2 < s.length()) {
			char ch = s[ptr2];
			// If it is inside hashmap & its index >= start of the current window.
			if(lookupMap.count(ch) && lookupMap[ch] >= ptr1) {
				ptr1 = lookupMap[ch] + 1;
				// Update Remaining Window Length 
				// Excluding Current Char
				curWinLen = ptr2 - ptr1;
			}
			// Update the Last Occurence
			lookupMap[ch] = ptr2;
			curWinLen++;
			ptr2++;
			// Update maxWinLen at every step
			if(curWinLen > maxWinLen) {
				maxWinLen = curWinLen;
				startWin = ptr1;
			}
		}
		return maxWinLen;    	
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	Solution *soln = new Solution();
	int lols = soln->lengthOfLongestSubstring(s);
	cout << lols << nl;
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