// EAGLE1.cpp
// https://cp-algorithms.com/graph/depth-first-search.html
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



template<typename T>
class Graph {
	unordered_map<T, list<ppi>> h;
	unordered_map<T,ll> d;
public:
	void addEdge(T u, T v, ll w,bool bidir = true) {
		h[u].pb({v,w});
		h[v].pb({u,w});
	}

	void dfs_helper(T node, unordered_map<T,bool>&visited,int m){
		visited[node] = true;
		for(auto child:h[node]){
			if(!visited[child.fi]){
				dfs_helper(child.fi,visited,m+child.si);
			}
		}
		if(d[node]<m)
			d[node] = m;
	}

	void dfs(ll n){

		unordered_map<T,bool> visited;
		for(auto node:h){

			int mx=0;
			if(!visited[node.fi]){
				dfs_helper(node.fi,visited,mx);
			}
		}

		for(int i=1;i<=n;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;
	}
};


int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		Graph<ll> g;

		for(int i=0;i<n-1;i++){
			ll a,b,w;
			cin>>a>>b>>w;
			g.addEdge(a,b,w);
		}


		g.dfs(n);

	}


	return 0;
}

