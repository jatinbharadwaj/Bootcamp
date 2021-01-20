#include<bits/stdc++.h>
using namespace std;

// Concept of Instack
// Add nodes to the stack if the node is already present in the stack then the cycle is present

#define ll long long int
#define mp make_pair
#define pb push_back
#define ppi pair<ll,ll>
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007

template<typename T>

class Graph {
	unordered_map<T, list<T> > h;
	bool isCylic_dfs_helper(T node, unordered_map<T, bool> & visited, unordered_map<T, bool> &instack) {

		instack[node] = true;
		visited[node] = true;

		for (auto children : h[node]) {
			if ( (!visited[children] && isCylic_dfs_helper(children, visited, instack)) || instack[children] )
				return true;
		}
		instack[node] = false;
		return false;
	}

	bool isCylic_dfs_helper_undirected(T node, unordered_map<T, bool> &visited, T parent) {
		visited[node] = true;

		for (auto children : h[node]) {
			if (!visited[children]) {
				bool KyaCyclePresentHai = isCylic_dfs_helper(children, visited, node);
			}
			else if (children != parent) {
				return true;
			}
		}
		return false;
	}

public:
	void addEdge(T u, T v, bool bidir = false) {

		h[u].pb(v);
		if (bidir) {
			h[v].pb(u);
		}
	}

	bool isCylic_dfs() {
		// Visited and instack is used if the node is traversed then stack
		unordered_map<T, bool> visited, instack;

		for (auto i : h) {
			T node = i.fi;
			if (!visited[node]) {
				bool checkCycle = isCylic_dfs_helper(node, visited, instack);
				if (checkCycle) return true;
			}
		}
		return false;
	}

	// check karna hota hai kee koi visited node dobara aya ya nhi agar aaya toh agr vo parent hai toh continue otherwise cycle present 
	bool isCylic_dfs_undirected() {
		unordered_map<T, bool> visited;

		for (auto i : h) {
			T node = i.fi;
			if (!visited[node]) {
				bool KyaCyclePresentHai = isCylic_dfs_helper(node, visited, node);
				if (KyaCyclePresentHai)
					return true;
			}
		}
		return false;
	}

	bool isCylic_bfs_undirected(T src) {
		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;

		parent[src] = src;
		visited[src] = true;
		queue<T> q;
		q.push(src);

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			for (auto children : h[node]) {
				if ( (visited[children] == true) and (parent[node] != children))
					return true;
				else if (!visited[children]) {
					visited[children] = true;
					parent[children] = node;
					q.push(children);
				}
			}
		}

		return false;
	}
};


int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	Graph<ll> g;
	for (ll i = 0 ; i  < n ; i ++) {
		ll x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	cout << g.isCylic_dfs() << endl;
	return 0;

	return 0;
}
