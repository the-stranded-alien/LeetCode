#include<iostream>
#include<vector>

using namespace std;

// Given an array of strings words and a string s, determine if s is an acronym of words.
// The string s is considered an acronym of words if it can be formed by concatenating the first character of each string in words in order. For example, "ab" can be formed from ["apple", "banana"], but it can't be formed from ["bear", "aardvark"].
// Return true if s is an acronym of words, and false otherwise.

class Solution {
public:
	bool isAcronym(vector<string>& words, string s) {
		string acry = "";
        for(auto word : words) acry += word[0];
        return s == acry;
    }
};

void solve() {
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i = 0; i < n; i++) {
		cin >> words[i];
	}	
	string s; cin >> s;
	Solution *soln = new Solution();
	cout << soln->isAcronym(words, s);

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