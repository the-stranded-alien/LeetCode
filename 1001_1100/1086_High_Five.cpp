#include<bits/stdc++.h>

using namespace std;

#define int 				long long int
#define double				long double
#define F 					first
#define S 					second
#define pb 					push_back
#define pob					pop_back
#define mp 					make_pair
#define si 					set <int>
#define vi 					vector <int>
#define vs					vector <string>
#define vb					vector <bool>
#define pii 				pair <int, int>
#define vpi         		vector <pii>
#define vpp         		vector <pair <int, pii> >
#define vvi					vector <vector<int> >
#define mii         		map <int, int>
#define mpi         		map <pii, int>
#define spi         		set <pii>
#define nl					"\n"
#define tb					"\t"
#define sz(x)				((int) x.size())
#define all(p)				p.begin(), p.end()
#define maxQue				priority_queue <int>
#define minQue				priority_queue <int, vi, greater<int> >
#define bug(...)			__f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)			for(auto x : a) cout << x << " "; cout << endl
#define printRange(a,x,y)  	for(int i = x; i < y; i++) cout << a[i] << " "; cout << endl
#define printRev(a,x,y)		for(int i = x; i > y; i--) cout << a[i] << " "; cout << endl
#define printPair(p)      	for(auto x : p) cout << x.F << " " << x.S << endl; cout << endl
#define mod 				1e9 + 7

inline int power (int a, int b) {
	int x = 1;
	while (b) {
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

// Given a list of the scores of different students, items, where items[i] =
// [IDi, scorei] represents one score from a student with IDi, calculate each
// student's top five average.
// Return the answer as an array of pairs result, where result[j] = 
// [IDj, topFiveAveragej] represents the student with IDj and their top five
// average. Sort result by IDj in increasing order.
// A student's top five average is calculated by taking the sum of their top
// five scores and dividing it by 5 using integer division.

class Solution {
public:
	vector<vector<int>> highFive(vector<vector<int>>& items) {
    	map<int, vector<int> > idScoreMap;
    	for(auto item : items) {
    		int id = item[0];
    		int sc = item[1];
    		if(idScoreMap.find(id) != idScoreMap.end()) idScoreMap[id].push_back(sc);
    		else idScoreMap[id] = {sc};
    	}    
    	vector<vector<int> > highFives;
    	for(auto kv : idScoreMap) {
    		int id = kv.first;
    		vector<int> scores = kv.second;
    		sort(scores.begin(), scores.end(), greater<int>());
    		int topFiveAvg = 0;
    		for(int i = 0; i < 5; i++) topFiveAvg += scores[i];
    		topFiveAvg /= 5;
    		highFives.push_back({id, topFiveAvg});
    	}
    	sort(highFives.begin(), highFives.end(), 
    		[](const vector<int> &hf1, const vector<int> &hf2) {
    			return hf1[0] < hf2[0];
    		});
    	return highFives;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vvi items(n, vi(2, 0));
	for(int i = 0; i < n; i++) { cin >> items[i][0]; cin >> items[i][1]; }

	Solution *soln = new Solution();
	vvi hf = soln->highFive(items);
	for(auto h : hf) cout << h[0] << " -> " << h[1] << nl;
	
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