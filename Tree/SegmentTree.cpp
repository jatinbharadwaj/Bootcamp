#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int a[N];

struct segment_tree {
	vector<int> st;
	void init(int n) {
		st.resize(4 * n);
	}

	void build(int start, int end, int node) {
		if (start == end) {
			st[node] = a[start];
			return;
		}

		int mid = (start + end) / 2;
		// left build
		build(start, mid, 2 * node + 1);
		// right build
		build(mid + 1, end, 2 * node + 2);
		// update current node
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	// summation
	int query(int start, int end, int l, int r , int node) {
		// no overlap
		if (end < l || start > r) {
			return 0;
		}
		// complete overlap
		if (start >= l && end <= r) {
			return st[node];
		}
		// partial overlap
		int mid = (start + end) / 2;
		int left = query(start, mid, l, r, 2 * node + 1);
		int right = query(mid + 1, end, l, r, 2 * node + 2);
		return left + right;
	}

	// update
	void update(int start, int end, int index, int val, int node) {
		if (start == end) {
			a[index] = val;
			st[node] = val;
			return;
		}
		int mid = (start + end) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, index, val, 2 * node + 1);
		}
		else {
			// right subtree
			update(mid + 1, end, index, val, 2 * node + 2);
		}
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}
};

void solve() {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	segment_tree tree;
	tree.init(n);
	tree.build(0, n - 1, 0);
	cout << tree.query(0, n - 1, 0, 3, 0) << '\n';
	cout << tree.query(0, n - 1, 3, 7, 0) << '\n';
	tree.update(0, n - 1, 2, 10, 0);
	cout << tree.query(0, n - 1, 0, 3, 0) << '\n';
	return ;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	solve();
	return 0;
}

