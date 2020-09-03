//0_1_MST.cpp

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

map<int,bool> g[AS];
set<int> s;

void dfs(int u){

	vector<int> adj;
	set<int> ns;

	for(int v:s){
		if(g[u][v]) ns.insert(v);
		else
			adj.pb(v);
	}
	s=ns;
	for(auto u : adj) dfs(u);
}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		g[u][v] = g[v][u] = 1;
	}

	for(int i=0; i<n; i++){
		s.insert(i+1);
	}

	int count = 0;

	while(s.size()){
		dfs(*s.begin());
		count++;
	}

	count<<count-1<<endl;

	return 0;
}