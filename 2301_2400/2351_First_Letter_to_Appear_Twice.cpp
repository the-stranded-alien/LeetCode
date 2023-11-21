#include<iostream>
#include<set>

using namespace std;

// Given a string s consisting of lowercase English letters, return the first letter to appear twice.
// Note:
// A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
// s will contain at least one letter that appears twice.

class Solution {
public:
	char repeatedCharacter(string s) {
        set<char> bag;
        char rep;
        for(auto c : s) {
        	if(bag.find(c) != bag.end()) {
        		rep = c;
        		break;
        	}
        	bag.insert(c);
        }
        return rep;
    }
};

void solve() {
	string s;
	cin >> s;
	
	Solution *soln = new Solution();
	cout << soln->repeatedCharacter(s);

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