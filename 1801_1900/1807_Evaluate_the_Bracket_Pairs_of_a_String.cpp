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

// You are given a string s that contains some bracket pairs, with each pair
// containing a non-empty key.
// For example, in the string "(name)is(age)yearsold", there are two bracket
// pairs that contain the keys "name" and "age".
// You know the values of a wide range of keys. This is represented by a 2D
// string array knowledge where each knowledge[i] = [keyi, valuei] indicates
// that key keyi has a value of valuei.
// You are tasked to evaluate all of the bracket pairs. When you evaluate a
// bracket pair that contains some key keyi, you will:
// Replace keyi and the bracket pair with the key's corresponding valuei.
// If you do not know the value of the key, you will replace keyi and the
// bracket pair with a question mark "?" (without the quotation marks).
// Each key will appear at most once in your knowledge. There will not be
// any nested brackets in s.
// Return the resulting string after evaluating all of the bracket pairs.

class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for(auto know : knowledge) map.insert({know[0], know[1]});
        
        stringstream ss(s);
    	string token;
    	vector<string> tokens;
    	while(getline(ss, token, ')')) {
    		if(token != "") tokens.push_back(token);
    	}
    	string res = "";
    	for(auto t : tokens) {
    		int open = -1;
    		for(int i = 0; i < (int) t.length(); i++) {
    			char c = t[i];
    			if(c == '(') open = i;
    		}
    		if(open == -1) res += t;
    		else {
    			if(open == 0) {
    				if(map.find(t.substr(open + 1)) != map.end()) {
    					res += map[t.substr(open + 1)];
    				} else res += "?";
    			} else {
    				res += t.substr(0, open);
    				if(map.find(t.substr(open + 1)) != map.end()) {
    					res += map[t.substr(open + 1)];
    				} else res += "?";
    			}
    		}
    	}
    	return res;
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	int k; cin >> k;
	vector< vector<string> > knowledge(k, vector<string>(2));
	for(int i = 0; i < k; i++) cin >> knowledge[i][0] >> knowledge[i][1];
	
	Solution *soln = new Solution();
	cout << soln->evaluate(s, knowledge);

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