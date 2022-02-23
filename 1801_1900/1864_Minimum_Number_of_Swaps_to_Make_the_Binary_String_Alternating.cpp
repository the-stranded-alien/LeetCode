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

// Given a binary string s, return the minimum number of character swaps
// to make it alternating, or -1 if it is impossible.
// The string is called alternating if no two adjacent characters are
// equal. For example, the strings "010" and "1010" are alternating,
// while the string "0100" is not.
// Any two characters may be swapped, even if they are not adjacent.

class Solution {
public:
    int minSwaps(string s) {
        int l = s.length();
        if(l == 1) return 0;
        string v1 = "";
        string v2 = "";
        for(int i = 0; i < l; i++) {
        	if(i % 2 == 0) { v1 += '0'; v2 += '1'; } 
        	else { v1 += '1'; v2 += '0'; }
        }
        if((v1 == s) || (v2 == s)) return 0;
        int diffZero1 = 0;
        int diffOne1 = 0;
        int diffZero2 = 0;
        int diffOne2 = 0;
        for(int i = 0; i < l; i++) {
        	if((s[i] == '0') && (s[i] != v1[i])) diffZero1++;
        	if((s[i] == '1') && (s[i] != v1[i])) diffOne1++;
        	if((s[i] == '0') && (s[i] != v2[i])) diffZero2++;
        	if((s[i] == '1') && (s[i] != v2[i])) diffOne2++;
        }
        if((diffZero1 != diffOne1) && (diffZero2 != diffOne2)) return -1;
        else if((diffZero1 == diffOne1) && (diffZero2 == diffOne2)) return min(diffZero1, diffZero2);
        else if(diffZero1 == diffOne1) return diffZero1;
        else return diffZero2;
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	Solution *soln = new Solution();
	int ms = soln->minSwaps(s);
	cout << ms << nl;
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