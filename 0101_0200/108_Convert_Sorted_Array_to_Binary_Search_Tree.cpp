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

// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree. A height-balanced binary
// tree is a binary tree in which the depth of the two subtrees of every node 
// never differs by more than one.

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
	TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
		if(start > end) return nullptr;
		int mid = (start + end) / 2;
		int cur = nums[mid];
		// cout << cur << " ";
		TreeNode *curNode = new TreeNode(cur);
		curNode->left = sortedArrayToBSTHelper(nums, start, (mid - 1));
		curNode->right = sortedArrayToBSTHelper(nums, (mid + 1), end);
		return curNode;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        TreeNode *root = sortedArrayToBSTHelper(nums, start, end);
        return root;
    }
};

void printLevelOrder(TreeNode *root) {
	if(root == nullptr) return;
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	nodeQueue.push(nullptr);
	while(!nodeQueue.empty()) {
		TreeNode *cur = nodeQueue.front();
		if(cur == nullptr) {
			cout << nl;
			nodeQueue.pop();
			if(!nodeQueue.empty()) nodeQueue.push(nullptr);
		} else {
			cout << cur->val << " ";
			nodeQueue.pop();
			if(cur->left) nodeQueue.push(cur->left);
			if(cur->right) nodeQueue.push(cur->right);
		}
	}
	return;
}

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];	
	Solution *soln = new Solution();
	TreeNode *root = soln->sortedArrayToBST(nums);
	printLevelOrder(root);
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