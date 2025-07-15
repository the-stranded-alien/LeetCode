#include<bits/stdc++.h>
#include<iostream>
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


// A word is considered valid if:

// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.

// Return true if word is valid, otherwise, return false.

// Notes:

// 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
// A consonant is an English letter that is not a vowel.


class Solution {
private:
	bool isVowel(char c) {
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}
	bool isConsonant(char c) {
		return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) &&
		!isVowel(c);
	}
	bool containsVowel(string word) {
		bool containsVowel = false;
		for(char ch : word) {
			ch = tolower(ch);
			if(isVowel(ch)) {
				containsVowel = true;
			}
		}
		return containsVowel;
	}
	bool containsConsonant(string word) {
		bool containsConsonant = false;
		for (char ch : word) {
			ch = tolower(ch);
			if(isConsonant(ch)) {
				containsConsonant = true;
			}
		}
		return containsConsonant;
	}
	bool containsDigitsAndLetters(string word) {
		bool containsDigitsAndLetters = true;
		for(char ch : word) {
			if (ch >= '0' && ch <= '9') continue;
			else if(ch >= 'a' && ch <= 'z') continue;
			else if(ch >= 'A' && ch <= 'Z') continue;
			else containsDigitsAndLetters = false;
		}
		return containsDigitsAndLetters;
	}
public:
	bool isValid(string word) {
		return word.size() >= 3 && containsVowel(word) && 
			containsConsonant(word) && containsDigitsAndLetters(word);
	}
};

void solve() {
	// Main Code Goes Here !!
	string word;
	cin >> word;
	
	Solution *soln = new Solution();

	cout << soln->isValid(word);

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