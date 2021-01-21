// dsu_practice.cpp
#include<bits/stdc++.h>
using namespace std;

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

// Kruskal's Algorithm
/*

	1. Sort all the weights
	2. Make DSU of all the sorted weight if they don't have a common parent
	3. Add the DSU accepted nodes into another map used for make MST

*/

class DSU {
	vector<ll> parent, rank;
	ll totalComponents;
public:
	// initialisation of DSU components
	DSU(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		iota(parent.begin(), parent.end(), 0);
		totalComponents = n;
	}

	ll get(ll a) {
		if (a == parent[a])
			return a;
		return parent[a] = get(parent[a]);

	}

	void union_set(int a, int b) {

		a = get(a);
		b = get(b);

		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			parent[b] = a;
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
			totalComponents--;
		}
	}

};


int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, e;

	cin >> n >> e;

	vector<vector<int>> edges(e);
	map<ll, list<ppi>> mst;
	DSU g(n);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {w, u, v};
	}

	// sorted according to the weights
	sort(edges.begin(), edges.end());

	int min_wt = 0;

	for (int i = 0; i < e; i++) {

		int u = edges[i][1];
		int v = edges[i][2];
		int w = edges[i][0];

		if (g.get(u) != g.get(v)) {
			g.union_set(u, v);
			min_wt += w;
			mst[u].pb({v, w});
		}
		// cout<<u<<v<<w;

	}
	// cout<<min_wt;
	for (auto node : mst) {
		for (auto child : node.si) {
			cout << node.fi << " is connected to: " << child.fi << " with weight: " << child.si << endl;
		}
	}
	return 0;
}

