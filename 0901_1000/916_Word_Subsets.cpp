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

// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter
// in b occurs in a including multiplicity.
// For example, "wrr" is a subset of "warrior" but is not a
// subset of "world".
// A string a from words1 is universal if for every string b
// in words2, b is a subset of a.
// Return an array of all the universal strings in words1.
// You may return the answer in any order.

class Solution {
public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> countB(26, 0);
        for(auto b : words2) {
        	vector<int> curCount(26, 0);
        	for(auto ch : b) curCount[ch - 'a']++;
        	for(int i = 0; i < 26; i++) countB[i] = max(countB[i], curCount[i]);
        }
    	vector<string> ws;
    	for(auto a : words1) {
    		vector<int> countA(26, 0);
    		bool universal = true;
    		for(auto ch : a) countA[ch - 'a']++;
    		for(int i = 0; i < 26; i++) {
    			if(countA[i] < countB[i]) {
    				universal = false;
    				continue;
    			}
    		}
    		if(universal) ws.push_back(a);
    	}
    	return ws;
    }
};

void solve() {
	// Main Code Goes Here !!
	int w1, w2;
	cin >> w1 >> w2;
	vs words1(w1);
	vs words2(w2);
	for(int i = 0; i < w1; i++) cin >> words1[i];
	for(int i = 0; i < w2; i++) cin >> words2[i];
	
	Solution *soln = new Solution();
	vs ws = soln->wordSubsets(words1, words2);
	for(auto w : ws) cout << w << " ";

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