// Dijkstras_practice.cpp
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

// Dijktra's Algorithm

/*
	1. Make all node INF except Source node
	2. Add the node into a set or priority queue and updates it's imediate neighbour's distance
	   checking condition d[u] + cost[u][v] < d[v] then update d[v]
	3. pop or remove the node and append neighbour's into the set

	Cannot be used for negative cycles

	Time Complexity:	O(ELogV)

*/

template<typename T>
class Graph {
	int V;
	list<ppi> *h;
public:
	Graph(int V) {
		this->V = V;
		h = new list<ppi> [V];
	}

	void addEdge(T u, T v, T w, bool bidir = false) {
		h[u].pb(mp(v, w));
		h[v].pb(mp(u, w));
	}

	int Dijktra(ll src, ll target) {

		set<ppi> setds;
		vector<ll> dist(V, INT_MAX);

		setds.insert(mp(0, src));
		dist[src] = 0;

		while (!setds.empty()) {

			auto front  = *(setds.begin());
			setds.erase(setds.begin());

			auto u = front.si;

			for (auto i : h[u]) {

				auto v = (i).fi;
				auto w = (i).si;

				if (dist[v] > dist[u] + w) {
					if (dist[v] != INT_MAX)
						setds.erase(setds.find(mp(dist[v], v)));
					dist[v] = dist[u] + w;
					setds.insert(mp(dist[v], v));

				}

				if (v == target) {
					return dist[v];
				}
			}
		}
		for (int i = 0; i < V; i++) {
			cout << "vertex :" << i << " distance from source: " << dist[i] << endl;
		}

		return -1;
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

	Graph<ll> g(n);

	for (int i = 0; i < e; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}

	cout << g.Dijktra(0, 4);



	return 0;
}

