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

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Valid Node Values [-100, 100], Using 999 as Terminating Value
TreeNode *buildTree() {
	int val;
	cin >> val;
	if(val != 999) {
		TreeNode *node = new TreeNode(val);
		node->left = buildTree();
		node->right = buildTree();
		return node;
	}
	else return nullptr;
}
 
class Solution {
public:
	void postorderTraversalHelper(TreeNode *root, vector<int> &post) {
		if(root == nullptr) return;
		else {
			postorderTraversalHelper(root->left, post);
			postorderTraversalHelper(root->right, post);
			post.push_back(root->val);
			return;
		}
	}

    vector<int> postorderTraversalRec(TreeNode* root) {
    	vector<int> post;
    	post.reserve(100);
    	postorderTraversalHelper(root, post);
    	return post;
    }

    vector<int> postorderTraversal(TreeNode *root) {
    	if(root == nullptr) return {};
    	stack<TreeNode*> stk1;
    	stack<TreeNode*> stk2;
    	stk1.push(root);
    	while(!stk1.empty()) {
    		TreeNode *node = stk1.top();
    		stk1.pop();
    		stk2.push(node);
    		if(node->left != nullptr) stk1.push(node->left);
    		if(node->right != nullptr) stk1.push(node->right);
    	}
    	vector<int> post;
    	post.reserve(stk2.size() + 1);
    	while(!stk2.empty()) {
    		post.push_back(stk2.top()->val);
    		stk2.pop();
    	} 
    	return post;
    }

};

void solve() {
	// Main Code Goes Here !!
	TreeNode *root = buildTree();
	Solution *soln = new Solution();
	vi post = soln->postorderTraversal(root);
	for(auto p : post) cout << p << " ";
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