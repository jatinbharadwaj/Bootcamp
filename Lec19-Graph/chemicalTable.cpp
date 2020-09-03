//chemicalTable.cpp 
//DSU
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


class DSU{
	vector<ll> parent,rank;
public:
	DSU(ll n){
		parent.resize(n);
		rank.assign(n,0);
		iota(parent.begin(),parent.end(),0);
	}

	ll get(ll a){
		if(parent[a]==a) return a;

		return parent[a] = get(parent[a]);
	}

	void union_sets(ll a, ll b){
		a = get(a);
		b = get(b);

		if(a!=b){
			if(rank[a]<rank[b]){
				swap(a,b);
			}
		
		parent[b] = a;

		if(rank[a]==rank[b]) rank[a]++;
		}
	}

};

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n,m,q;
	cin>>n>>m>>q;

	DSU g(n+m);

	for(int i=0;i<q;i++){
		ll x,y;
		cin>>x>>y;
		x--,y--;
		g.union_sets(x,n+y);
	}

	vector<bool> cnt(n+m,0);

	for(int i=0; i<n+m ;i++){
		cnt[g.get(i)] = true;
	}
	
	ll ans = 0;
	for(int i=0; i<n+m; i++){
		if(cnt[i]) ans++;
	}
	cout<<ans-1<<endl;

	return 0;
}
