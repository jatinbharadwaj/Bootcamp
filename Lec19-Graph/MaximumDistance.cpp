//MaximumDistance.cpp
//MST
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

ll n,m,k;

class DSU{

	vector<ll> parent,rank;

	ll totalSpecialVertex;

public:
	DSU(ll v){
		totalSpecialVertex = 0;
		parent.resize(v);
		rank.resize(v);

		for(int i=0;i<v;i++){
			parent[i] = i;
		}
	}

	ll get(ll a){
		if(parent[a]==a) return a;
		return parent[a] = get(parent[a]);
	}

	void union_set(ll a,ll b){
		a = get(a);
		b = get(b);

		if(a!=b){
			parent[b] = a;
			rank[a] += rank[b];
			totalSpecialVertex =  max(totalSpecialVertex,rank[a]);
		}
	}

	void SetRank(ll a){
		rank[a] = 1;
	}

	bool isSpecialVertex(){
		assert(totalSpecialVertex<=k);

		return (totalSpecialVertex == k);
	}

};


int main(){
	
	fastIO

	vector<vector<ll>> edges;

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin>>n>>m>>k;

	DSU g(n+1);

	ll SpecialVertex[k];

	for(ll i = 0 ; i<k ;i++){
		cin>>SpecialVertex[i];
		g.SetRank(SpecialVertex[i]);
	}

	for(ll i=0; i<m ;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		edges.push_back({w,u,v});
	}

	sort(edges.begin(),edges.end());

	ll max_weight = 0;

	for(ll i=0;i<m;i++){

		ll w = edges[i][0];
		ll u = edges[i][1];
		ll v = edges[i][2];
		
		if(g.get(u) != g.get(v)){
			g.union_set(u,v);
      		if(g.isSpecialVertex()){
                max_weight=w;
                break;
            }
		}		

	}

	for(ll i=0; i<k ; i++){
		cout<<max_weight<<" ";
	}
	return 0;
}
