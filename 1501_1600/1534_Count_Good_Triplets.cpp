#include<iostream>
#include<set>

using namespace std;

// Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.
// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:
// 0 <= i < j < k < arr.length
// |arr[i] - arr[j]| <= a
// |arr[j] - arr[k]| <= b
// |arr[i] - arr[k]| <= c
// Where |x| denotes the absolute value of x.
// Return the number of good triplets.

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int goodTriplets = 0;
        for(int i = 0; i < arr.size() - 2; i++) {
            for(int j = i + 1; j < arr.size() - 1; j++) {
                for(int k = j + 1; k < arr.size(); k++) {
                    if(abs(arr[i] - arr[j]) <= a && 
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c) {
                        goodTriplets++;
                    }
                }
            }
        }
        return goodTriplets;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;

    Solution *soln = new Solution();
    cout << soln->countGoodTriplets(arr, a, b, c);
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