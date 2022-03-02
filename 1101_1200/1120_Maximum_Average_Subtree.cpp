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

// Given the root of a binary tree, return the maximum average value of a subtree
// of that tree. Answers within 10-5 of the actual answer will be accepted.
// A subtree of a tree is any node of that tree plus all its descendants.
// The average value of a tree is the sum of its values, divided by the number
// of nodes.

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
	double maxAvg = 0.0;
	pair<double, double> sumCount(TreeNode *root) {
		pair<double, double> sc; // {nodeCount, descSum}
		if(root == nullptr) {
			sc.first = sc.second = 0;
			return sc;
		}
		pair<double, double> left = sumCount(root->left);
		pair<double, double> right = sumCount(root->right);
		sc.first = (left.first + right.first + 1);
		sc.second = (root->val + left.second + right.second);
		maxAvg = max(maxAvg, (double)(sc.second / sc.first));
		return sc;
	}

    double maximumAverageSubtree(TreeNode* root) {
        pair<int, int> sc = sumCount(root);
        return maxAvg;
    }
};

TreeNode *levelOrderBuild() {
	int d; cin >> d;
	TreeNode *root = new TreeNode(d);
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;
		if(c1 != -1) {
			node->left = new TreeNode(c1);
			q.push(node->left);
		}
		if(c2 != -1) {
			node->right = new TreeNode(c2);
			q.push(node->right);
		}
	}
	return root;
}

void solve() {
	// Main Code Goes Here !!
	TreeNode *root = levelOrderBuild();
	Solution *soln = new Solution();
	double maxAvg = soln->maximumAverageSubtree(root);
	cout << maxAvg << nl;
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