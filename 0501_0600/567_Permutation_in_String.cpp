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

// Given two strings s1 and s2, return true if s2 contains a
// permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the
// substring of s2.

class Solution {
public:
	bool isPermutation(string s1, vector<int> &freqMap) {
		vector<int> copy(freqMap.begin(), freqMap.end());
		for(auto ch : s1) {
			copy[ch - '0' - 49] -= 1;
		}
		for(int i = 0; i < 26; i++) {
			if(copy[i] != 0) return false;
		}
		return true;
	}

    bool checkInclusion(string s1, string s2) {
    	if(s2.length() < s1.length()) return false;
        vector<int> freqMap(26, 0);
        int l1 = s1.length();
        int l2 = s2.length();
        for(int i = 0; i < l1; i++) {
        	freqMap[s2[i] - '0' - 49] += 1;
        }
        for(int i = l1; i < l2; i++) {
        	if(isPermutation(s1, freqMap)) return true;
        	freqMap[s2[i] - '0' - 49]++;
        	freqMap[s2[i - l1] - '0' - 49]--;
        }
        if(isPermutation(s1, freqMap)) return true;
        else return false;
    }
};

void solve() {
	// Main Code Goes Here !!
	string s1; cin >> s1;
	string s2; cin >> s2;
	Solution *soln = new Solution();
	bool ci = soln->checkInclusion(s1, s2);
	if(ci) cout << "true" << nl;
	else cout << "false" << nl;
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