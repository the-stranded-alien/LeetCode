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

// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
// In the American keyboard:
// the first row consists of the characters "qwertyuiop",
// the second row consists of the characters "asdfghjkl", and
// the third row consists of the characters "zxcvbnm".

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	vector<string> typedUsingOneRow;
  		string kr1 = "qwertyuiopQWERTYUIOP";
  		string kr2 = "asdfghjklASDFGHJKL";
  		string kr3 = "zxcvbnmZXCVBNM";
  		unordered_set<char> krs1(kr1.begin(), kr1.end());
  		unordered_set<char> krs2(kr2.begin(), kr2.end());
  		unordered_set<char> krs3(kr3.begin(), kr3.end());
  		for(auto word : words) {
  			bool fromFR = true;
  			bool fromSR = true;
  			bool fromTR = true;
  			for(auto ch : word) {
  				if((fromFR) && (krs1.find(ch) == krs1.end())) fromFR = false;
  				if((fromSR) && (krs2.find(ch) == krs2.end())) fromSR = false;
  				if((fromTR) && (krs3.find(ch) == krs3.end())) fromTR = false;
  			}
  			if(fromFR || fromSR || fromTR) typedUsingOneRow.push_back(word);
  		}
  		return typedUsingOneRow;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vs words(n, " ");
	for(int i = 0; i < n; i++) cin >> words[i];
	Solution *soln = new Solution();
	vs pw = soln->findWords(words);
	for(auto w : pw) cout << w << " ";
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