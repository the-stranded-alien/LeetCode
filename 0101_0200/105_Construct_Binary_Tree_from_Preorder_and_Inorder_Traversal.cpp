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

// Given two integer arrays preorder and inorder where preorder is the preorder traversal
// of a binary tree and inorder is the inorder traversal of the same tree, construct and
// return the binary tree.

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
	
	int preIndex = 0; // LeetCode C++ Doesn't Allow Static Variables

	TreeNode* buildTreeHelper(vector<int> const &preorder, vector<int> const &inorder, int startIndex, int endIndex, unordered_map<int, int> &inorderSearchMap) {
		if(startIndex > endIndex) return nullptr;
		int cur = preorder[preIndex++];
		TreeNode *node = new TreeNode(cur);
		if(startIndex == endIndex) return node;
		int inIndex = inorderSearchMap[node->val];
		node->left = buildTreeHelper(preorder, inorder, startIndex, (inIndex - 1), inorderSearchMap);
		node->right = buildTreeHelper(preorder, inorder, (inIndex + 1), endIndex, inorderSearchMap);
		return node;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  		int n = inorder.size();
    	int startIndex = 0;
    	int endIndex = (n - 1);
  		unordered_map<int, int> inorderSearchMap;
  		for(int i = 0; i < n; i++) inorderSearchMap[inorder[i]] = i;
  		return buildTreeHelper(preorder, inorder, startIndex, endIndex, inorderSearchMap);
    }
};

void inorderTraversal(TreeNode *root) {
	if(root == nullptr) return;
	inorderTraversal(root->left);
	cout << root->val << " ";
	inorderTraversal(root->right);
	return;
}

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi preorder(n, 0);
	vi inorder(n, 0);
	for(int i = 0; i < n; i++) cin >> preorder[i];
	for(int i = 0; i < n; i++) cin >> inorder[i];
	Solution *soln = new Solution();
	TreeNode *root = soln->buildTree(preorder, inorder);
	inorderTraversal(root);
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