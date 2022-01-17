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

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Valid Values : [-1000, 1000]
TreeNode *buildTree() {
	int val;
	cin >> val;
	if((val >= -1000) && (val <= 1000)) {
		TreeNode *root = new TreeNode(val);
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
	else return nullptr;
}


// Valid Values : [-1000, 1000]
TreeNode *buildTreeLevelOrder() {
	int val;
	cin >> val;
	if((val >= -1000) && (val <= 1000)) {
		TreeNode *root = new TreeNode(val);
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		while(!nodeQueue.empty()) {
			TreeNode *curNode = nodeQueue.front();
			nodeQueue.pop();
			int v1, v2;
			cin >> v1 >> v2;
			if((v1 >= -1000) && (v1 <= 1000)) {
				curNode->left = new TreeNode(v1);
				nodeQueue.push(curNode->left);
			}
			if((v2 >= -1000) && (v2 <= 1000)) {
				curNode->right = new TreeNode(v2);
				nodeQueue.push(curNode->right);
			}
		}
		return root;
	}
	else return nullptr;
}

void inorderTraversal(TreeNode *root) {
	if(root == nullptr) return;
	else {
		inorderTraversal(root->left);
		cout << root->val << " ";
		inorderTraversal(root->right);
		return;
	}
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        else if(root->left == nullptr && root->right == nullptr) return 1;
        else {
        	int l = INT_MIN;
        	int r = INT_MIN;
        	if(root->left != nullptr) l = maxDepth(root->left);
        	if(root->right != nullptr) r = maxDepth(root->right);
        	return (1 + max(l, r)); 
        }
    }
};

void solve() {
	// Main Code Goes Here !!
	TreeNode *root = buildTreeLevelOrder();
	Solution *soln = new Solution();
	int maxDepth = soln->maxDepth(root);
	cout << maxDepth << nl;
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