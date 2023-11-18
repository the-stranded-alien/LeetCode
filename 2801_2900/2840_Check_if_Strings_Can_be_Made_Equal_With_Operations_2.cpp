#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// You are given two strings s1 and s2, both of length n,
// consisting of lowercase English letters.
// You can apply the following operation on any of the two
// strings any number of times:
// Choose any two indices i and j such that i < j and the
// difference j - i is even, then swap the two characters
// at those indices in the string.
// Return true if you can make the strings s1 and s2 equal,
// and false otherwise.

class Solution {
public:
    void printMap(unordered_map<char, int> m) {
        for(auto kv : m) {
            cout << kv.first << " - " << kv.second << endl;
        }
        cout << endl;
    }
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> atEven;
        unordered_map<char, int> atOdd;
        for(int i = 0; i < s1.length(); i++) {
            if(i % 2 == 0) {
                if(atEven.count(s1[i])) atEven[s1[i]]++;
                else atEven[s1[i]] = 1;
            } else {
                if(atOdd.count(s1[i])) atOdd[s1[i]]++;
                else atOdd[s1[i]] = 1;
            }
        }
        for(int i = 0; i < s2.length(); i++) {
            if(i % 2 == 0) {
                if(atEven[s2[i]] > 1) atEven[s2[i]]--;
                else if(atEven[s2[i]] == 1) atEven.erase(s2[i]);
            } else {
                if(atOdd[s2[i]] > 1) atOdd[s2[i]]--;
                else if(atOdd[s2[i]] == 1) atOdd.erase(s2[i]);
            }
        }
        return atEven.empty() && atOdd.empty();
    }
};

void solve() {
    string s1; cin >> s1;
    string s2; cin >> s2;
    Solution *soln = new Solution();
    cout << soln->checkStrings(s1, s2);

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