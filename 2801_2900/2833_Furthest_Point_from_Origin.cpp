#include<iostream>
#include<vector>
#include<set>

using namespace std;

// You are given a string moves of length n consisting only of
// characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.
// In the ith move, you can choose one of the following directions:
// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.

class Solution {
public:
	int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int dash = 0;
        for(char move : moves) {
        	if(move == 'L') l++;
        	else if(move == 'R') r++;
        	else dash++;
        }
        return abs(l - r) + dash;
    }
};

void solve() {
	string moves; cin >> moves;
	Solution *soln = new Solution();
	cout << soln->furthestDistanceFromOrigin(moves);

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