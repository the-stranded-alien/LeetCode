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

// A substring is a contiguous (non-empty) sequence of characters
// within a string. A vowel substring is a substring that only
// consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all
// five vowels present in it. Given a string word, return the number
// of vowel substrings in word.

class Solution {
public:
	bool isVowel(char c) {
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
		else return false;
	}

	bool acceptableSubString(unordered_map<char, int> vm) {
		if(vm['$'] > 0) return false;
		else if(vm['a'] < 1) return false;
		else if(vm['e'] < 1) return false;
		else if(vm['i'] < 1) return false;
		else if(vm['o'] < 1) return false;
		else if(vm['u'] < 1) return false;
		else return true;
	}

    int countVowelSubstrings(string word) {
   		unordered_map<char, int> vm;
   		int count = 0;
   		int l = word.length();
   		for(int i = 0; i < l; i++) {
   			for(int j = i; j < l; j++) {
   				if(isVowel(word[j])) vm[word[j]]++;
   				else vm['$']++;
   				if(acceptableSubString(vm)) count++;
   			}
   			vm.clear();
   		} 
   		return count;
    }
};

void solve() {
	// Main Code Goes Here !!
	string word; cin >> word;
	Solution *soln = new Solution();
	int cvss = soln->countVowelSubstrings(word);
	cout << cvss << nl;
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