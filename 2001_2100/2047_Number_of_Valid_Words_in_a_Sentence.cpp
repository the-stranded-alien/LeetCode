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

// A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only. Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.
// A token is a valid word if all three of the following are true:
// It only contains lowercase letters, hyphens, and/or punctuation (no digits).
// There is at most one hyphen '-'. If present, it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
// There is at most one punctuation mark. If present, it must be at the end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
// Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".
// Given a string sentence, return the number of valid words in sentence.

class Solution {
public:
	bool isValidWord(string word) {
		int pun = 0;
		int chr = 0;
		int dig = 0;
		int hyp = 0;
		int oth = 0;
		for(auto ch : word) {
			if(ch >= 'a' && ch <= 'z') chr++;
			else if(ch >= '0' && ch <= '9') dig++;
			else if(ch == '-') hyp++;
			else if(ch == '!' || ch == ',' || ch == '.') pun++;
			else oth++;
		}
		if(oth != 0 || dig != 0) return false;
		else if(pun == 0 && hyp == 0 && chr >= 1) return true;
		else if(pun == 0 && hyp == 0 && chr == 0) return false;
		else if(hyp > 1) return false;
		else if(pun > 1) return false;
		else if(pun == 1 && hyp == 1) {
			bool v = true;
			char lw = word[word.length() - 1]; 
			if(lw == '.' || lw == ',' || lw == '!') v = true;
			else return false;
			for(int i = 0; i < word.length(); i++) {
				if(word[i] == '-') {
					if(i == 0 || i == word.length() - 1) return false;
					char prev = word[i - 1];
					char next = word[i + 1];
					if(prev >= 'a' && prev <= 'z' && next >= 'a' && next <= 'z') return true;
					else return false;
				}
			}
		} else if(pun == 1 && hyp == 0) {
			char lw = word[word.length() - 1]; 
			if(lw == '.' || lw == ',' || lw == '!') return true;
			else return false;
		} else if(hyp == 1 && pun == 0) {
			for(int i = 0; i < word.length(); i++) {
				if(word[i] == '-') {
					if(i == 0 || i == word.length() - 1) return false;
					char prev = word[i - 1];
					char next = word[i + 1];
					if(prev >= 'a' && prev <= 'z' && next >= 'a' && next <= 'z') return true;
					else return false;
				}
			}
		} else return false;
		return false;
	}

    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string token;
        vector<string> tokens;
        while(getline(ss, token, ' ')) {
        	if((token.length() > 0) && (token != " ")) {
        		tokens.push_back(token);	
        	} 
        }
        int validWords = 0;
        for(auto word : tokens) {
        	bool isValid = isValidWord(word);
        	if(isValid) validWords++; 
        }
        return validWords;
    }
};

void solve() {
	// Main Code Goes Here !!
	string sentence;
	getline(cin, sentence);
	Solution *soln = new Solution();
	int vw = soln->countValidWords(sentence);
	cout << vw << nl;
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