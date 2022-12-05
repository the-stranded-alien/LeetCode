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

// You are given a string s of lowercase English letters and an array widths
// denoting how many pixels wide each lowercase English letter is. Specifically,
// widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.
// You are trying to write s across several lines, where each line is no longer
// than 100 pixels. Starting at the beginning of s, write as many letters on the
// first line such that the total width does not exceed 100 pixels. Then, from
// where you stopped in s, continue writing as many letters as you can on the
// second line. Continue this process until you have written all of s.
// Return an array result of length 2 where:
// result[0] is the total number of lines.
// result[1] is the width of the last line in pixels.

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string s) {
        int numberOfLines = 1;
        int widthOfLastLine = 0;

        int lw = 100;
        for(auto ch : s) {
        	int w = widths[ch - 97];
        	if(lw >= w) lw -= w;
        	else {
        		numberOfLines++;
        		lw = 100;
        		lw -= w;
        	}
        }
        widthOfLastLine = 100 - lw;

        return {numberOfLines, widthOfLastLine};
    }
};

void solve() {
	// Main Code Goes Here !!
	vector<int> widths(26, 0);
	for(int i = 0; i < 26; i++) cin >> widths[i];
	string s; cin >> s;
	
	Solution *soln = new Solution();
	vi nol = soln->numberOfLines(widths, s);
	cout << nol[0] << " " << nol[1];

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