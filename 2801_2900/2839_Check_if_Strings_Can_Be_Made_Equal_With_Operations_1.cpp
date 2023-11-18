#include<iostream>
#include<vector>
#include<set>

using namespace std;

// You are given two strings s1 and s2, both of length 4,
// consisting of lowercase English letters.
// You can apply the following operation on any of the
// two strings any number of times:
// Choose any two indices i and j such that j - i = 2,
// then swap the two characters at those indices in the string.
// Return true if you can make the strings s1 and s2 equal,
// and false otherwise.

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;

        string s2_op1 = s2;
        swap(s2_op1[0], s2_op1[2]);
        if(s1 == s2_op1) return true;

        string s2_op2 = s2;
        swap(s2_op2[1], s2_op2[3]);
        if(s1 == s2_op2) return true;
        
        string s2_op3 = s2;
        swap(s2_op3[0], s2_op3[2]);
        swap(s2_op3[1], s2_op3[3]);
        if(s1 == s2_op3) return true;

        return false;
    }
};

void solve() {
    string s1; cin >> s1;
    string s2; cin >> s2;
    Solution *soln = new Solution();
    cout << soln->canBeEqual(s1, s2);

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