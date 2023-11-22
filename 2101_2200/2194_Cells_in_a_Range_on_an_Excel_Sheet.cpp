#include<iostream>
#include<vector>

using namespace std;

// A cell (r, c) of an excel sheet is represented as a string
// "<col><row>" where: <col> denotes the column number c of the cell.
// It is represented by alphabetical letters.
// For example, the 1st column is denoted by 'A', the 2nd by 'B',
// the 3rd by 'C', and so on.
// <row> is the row number r of the cell. The rth row is represented
// by the integer r. You are given a string s in the format
// "<col1><row1>:<col2><row2>", where <col1> represents the column c1,
// <row1> represents the row r1, <col2> represents the column c2,
// and <row2> represents the row r2, such that r1 <= r2 and c1 <= c2.
// Return the list of cells (x, y) such that r1 <= x <= r2 and
// c1 <= y <= c2. The cells should be represented as strings in the
// format mentioned above and be sorted in non-decreasing order first
// by columns and then by rows.

class Solution {
public:
	vector<string> cellsInRange(string s) {
        vector<string> cells;
        char col1 = s[0];
        char row1 = s[1];
        char col2 = s[3];
        char row2 = s[4];
        for(char c = col1; c <= col2; c++) {
        	for(int r = row1; r <= row2; r++) {
        		string cell;
        		cell += c;
        		cell += r;
        		cells.push_back(cell);
        	}
        }
        return cells;
    }
};

void solve() {
	string s;
	cin >> s;
	
	Solution *soln = new Solution();
	vector<string> res = soln->cellsInRange(s);
	for(auto r : res) cout << r << endl;
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