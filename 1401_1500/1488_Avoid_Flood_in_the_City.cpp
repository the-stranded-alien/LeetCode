#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<list>

using namespace std;

// Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.
// Given an integer array rains where:
// rains[i] > 0 means there will be rains over the rains[i] lake.
// rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
// Return an array ans where:
// ans.length == rains.length
// ans[i] == -1 if rains[i] > 0.
// ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
// If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.
// Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.

class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        list<int> zero_pos;
        int n =  r.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> freq;

        for(int i = 0;i<n;i++)
        {
            if(r[i]==0)
            zero_pos.push_back(i);
            else
            {
                if(freq.find(r[i])==freq.end())
                freq[r[i]]  = i;
                else
                {
                    vector<int> tmp;
                    while(zero_pos.size()>0 && zero_pos.front()<freq[r[i]])
                    {
                        tmp.push_back(zero_pos.front());
                        zero_pos.pop_front();
                    }
                    if(zero_pos.size()==0) return {};
                    else
                    {
                        ans[zero_pos.front()] = r[i];
                        zero_pos.pop_front();
                        freq[r[i]] = i;
                        for(int j = tmp.size()-1;j>=0;j--) zero_pos.push_front(tmp[j]);
                    }
                }
            }
        }
        while(!zero_pos.empty())
        {
            ans[zero_pos.front()] = 1;
            zero_pos.pop_front();
        }
        return ans;
        
    }
};

// class Solution {
// public:
//     vector<int> avoidFlood(vector<int>& rains) {
//         unordered_set<int> lakesFilled;
//         priority_queue<int, vector<int>, greater<int>> dryDayIndexes;
//         int dryDays = 0;
//         vector<int> ans(rains.size(), -1);
//         for(int i = 0; i < rains.size(); i++) {
//             if(rains[i] == 0) { 
//                 dryDayIndexes.push(i);
//                 dryDays++;
//             }
//             else {
//                 int curLake = rains[i];
//                 if(lakesFilled.find(curLake) != lakesFilled.end()) {
//                     if(dryDays == 0) return {};
//                     else {
//                         dryDays--;
//                         ans[dryDayIndexes.top()] = curLake;
//                         dryDayIndexes.pop();
//                     }
//                 } else lakesFilled.insert(curLake);
//             }
//         }
//         while(!dryDayIndexes.empty()) {
//             ans[dryDayIndexes.top()] = 1;
//             dryDayIndexes.pop();
//         }
//         return ans;
//     }
// };

void solve() {
    int n; cin >> n;
    vector<int> rains(n);
    for(int i = 0; i < n; i++) cin >> rains[i];
    Solution *soln = new Solution();
    vector<int> ans = soln->avoidFlood(rains);
    for(auto v : ans) cout << v << " ";
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