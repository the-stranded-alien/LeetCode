#include<iostream>
#include<unordered_set>

using namespace std;

// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters,
// return true if sentence is a pangram, or false otherwise.

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> charsPresent(sentence.begin(), sentence.end());
        return charsPresent.size() == 26;        
    }
};

void solve() {
    string s; cin >> s;
    Solution *soln = new Solution();
    cout << soln->checkIfPangram(s);
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