#include<iostream>
using namespace std;

// A valid cut in a circle can be:
// A cut that is represented by a straight line that touches two points on the edge of the circle and passes through its center, or
// A cut that is represented by a straight line that touches one point on the edge of the circle and its center.
// Given the integer n, return the minimum number of cuts needed to divide a circle into n equal slices.

class Solution {
public:
    int numberOfCuts(int n) {
        if(n == 1) return 0;
        return (n % 2 == 0) ? (n / 2) : n;
    }
};

int main () {
    int n; cin >> n;
    Solution *soln = new Solution();
    cout << soln->numberOfCuts(n) << endl;
    return 0;
}