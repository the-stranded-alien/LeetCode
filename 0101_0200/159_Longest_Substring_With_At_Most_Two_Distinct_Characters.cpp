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

// Given a string s, return the length of the longest 
// substring that contains at most two distinct characters.

// class Solution {
// public:
//     int lengthOfLongestSubstringTwoDistinct(string s) {
//         size_t n = s.length();
//         if (n < 3) {
//             return n;
//         }

//         // sliding window left and right pointers
//         int left = 0, right = 0;
//         // hashmap character -> its rightmost position
//         // in the sliding window
//         map<char, int> hashmap;

//         int max_len = 2;

//         while (right < n) {
//             // when the sliding window contains less than 3 characters
//             hashmap[s[right]] = right;
//             right++;

//             // slidewindow contains 3 characters
//             if (hashmap.size() == 3) {
//                 int del_idx = INT_MAX;
//                 for (pair<char, int> element : hashmap) {
//                     del_idx = min(del_idx, element.second);
//                 }
//                 // delete the leftmost character
//                 hashmap.erase(s[del_idx]);
//                 left = del_idx + 1;
//             }
//             max_len = max(max_len, right - left);
//         }
//         return max_len;
//     }
// };

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = s.length();
        int maxLen = 1;
        set<char> st;
        for(int i = 0; i < (l - 1); i++) {
        	st.insert(s[i]);
        	for(int j = (i + 1); j < l; j++) {
        		int len = (j - i + 1);
        		st.insert(s[j]);
        		if(st.size() > 2) break; 
        		else maxLen = max(maxLen, len);
        	}
        	st.clear();
        }
        return maxLen;
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	
	Solution *soln = new Solution();
	cout << soln->lengthOfLongestSubstringTwoDistinct(s);

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