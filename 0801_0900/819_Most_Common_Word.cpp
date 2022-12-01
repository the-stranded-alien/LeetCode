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

// Given a string paragraph and a string array of the banned words banned, return the 
// most frequent word that is not banned. It is guaranteed there is at least
// one word that is not banned, and that the answer is unique.
// The words in paragraph are case-insensitive and the answer should be
// returned in lowercase.

class Solution {
private:
	const unordered_set<char> breaks{' ', '!', '?', '\'', ',', ';', '.'};

public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		int l = paragraph.length();
		transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
		for(int itr = 0; itr < l; itr++) {
			char w = paragraph[itr];
			if(!(w >= 'a' && w <= 'z') && !(w >= 'A' && w <= 'Z')) {
				paragraph[itr] = ' ';
			}
		}

	    stringstream ss(paragraph);
	    string token;
    	vector<string> words;
    	while(getline(ss, token, ' ')) {
    		if(token != "") words.push_back(token);
    	}

    	unordered_set<string> bannedWords(banned.begin(), banned.end());
    	unordered_map<string, int> freqMap;
    	for(auto word : words) freqMap[word]++;

    	int maxCount = 0;
    	string maxCountWord;
    	for(auto fp : freqMap) {
    		string w = fp.first;
    		int f = fp.second;

    		if(maxCount < f && (bannedWords.find(w) == bannedWords.end())) {
    			maxCount = f;
    			maxCountWord = w;
    		}
    	}

        return maxCountWord;
    }
};

void solve() {
	// Main Code Goes Here !!
	string paragraph;
	getline(cin, paragraph);
	int n; cin >> n;
	vs banned(n);
	for(int i = 0; i < n; i++) cin >> banned[i];
	
	Solution *soln = new Solution();
	cout << soln->mostCommonWord(paragraph, banned);

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