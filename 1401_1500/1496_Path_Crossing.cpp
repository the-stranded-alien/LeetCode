#include<iostream>
#include<set>

using namespace std;

// Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing
// moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
// Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int> > coordinates;
        int x = 0;
        int y = 0;
        coordinates.insert(make_pair(x, y));
        for(auto dir : path) {
            switch(dir) {
            case 'N':
                x++;
                break;
            case 'S':
                x--;
                break;
            case 'E':
                y++;
                break;
            case 'W':
                y--;
                break;            
            }
            if(coordinates.find(make_pair(x, y)) != coordinates.end()) return true;
            else coordinates.insert(make_pair(x, y));
        }
        return false;
    }
};

void solve() {
    string path; cin >> path;
    Solution *soln = new Solution();
    cout << soln->isPathCrossing(path);
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