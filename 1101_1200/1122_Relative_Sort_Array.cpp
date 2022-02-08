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

// Given two arrays arr1 and arr2, the elements of arr2 are distinct,
// and all elements in arr2 are also in arr1. Sort the elements of arr1
// such that the relative ordering of items in arr1 are the same as in
// arr2. Elements that do not appear in arr2 should be placed at the end
// of arr1 in ascending order.

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
  		map<int, int> relPos;
  		for(int i = 0; i < arr2.size(); i++) relPos[arr2[i]] = i;
  		sort(arr1.begin(), arr1.end(), [&](const int &a, const int &b){
  			if ((relPos.find(a) == relPos.end()) && (relPos.find(b) == relPos.end())) return (a < b);
  			else if (relPos.find(a) == relPos.end()) return false;
  			else if (relPos.find(b) == relPos.end()) return true;
  			else return (relPos[a] < relPos[b]);
  		});
  		return arr1;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n1; cin >> n1;
	vi arr1(n1, 0);
	for(int i = 0; i < n1; i++) cin >> arr1[i];
	int n2; cin >> n2;
	vi arr2(n2, 0);
	for(int i = 0; i < n2; i++) cin >> arr2[i];
	Solution *soln = new Solution();
	vi rsa = soln->relativeSortArray(arr1, arr2);
	for(auto x : rsa) cout << x << " ";
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