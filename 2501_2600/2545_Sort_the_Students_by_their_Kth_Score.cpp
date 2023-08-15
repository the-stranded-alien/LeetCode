#include<iostream>
#include<vector>

using namespace std;

// There is a class with m students and n exams. You are given
// a 0-indexed m x n integer matrix score, where each row represents
// one student and score[i][j] denotes the score the ith student
// got in the jth exam. The matrix score contains distinct integers
// only. You are also given an integer k. Sort the students
// (i.e., the rows of the matrix) by their scores in the kth
// (0-indexed) exam from the highest to the lowest.
// Return the matrix after sorting it.

class Solution {
public:
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](const vector<int> &a, const vector<int> &b) {
        	return a[k] > b[k];
        });
        return score;
    }
};

void solve() {
	int m, n;
	cin >> m >> n;
	vector<vector<int> > score(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> score[i][j];
		}
	}
	int k; cin >> k;
	Solution *soln = new Solution();
	vector<vector<int> > sortedScores = soln->sortTheStudents(score, k);

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << sortedScores[i][j] << " ";
		}
		cout << endl;
	}
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