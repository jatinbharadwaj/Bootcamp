//Planttreessavelife.cpp
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

ll n,k;
vector<ll> Rank;

class dsu{
	
	vector<ll> parent;
	ll totalcomponents = n;

public:
	dsu(ll n){

		parent.resize(n+1);
		//Rank.resize(n+1);

		for(ll i = 0; i<=n ; i++){
			parent[i] = i;
			//cin>>Rank[i];
		}
	}


	ll get(ll a){
		if(a == parent[a]){
			return a;
		}
		return parent[a] = get(parent[a]);

	}

	void union_sets(ll a, ll b){

		a = get(a);
		b = get(b);

		if(a!=b){
			if(Rank[a]>Rank[b]){
				swap(a,b);
			}
			parent[b] = a;
			
		}

	}

};


int main(){
	
	fastIO


	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin>>n>>k;
	Rank.resize(n+1);

	for(int i=1; i<=n;i++) 
	{
		cin>>Rank[i];
	}

	dsu g(n);

	for(int i=0; i<k ; i++ ){
		ll x,y;
		cin>>x>>y;
		g.union_sets(x,y);
	}

	ll ans = 0;


	for(ll i = 1; i<=n; i++){
		//cout<<"i->"<<i<<" get(i)->"<<g.get(i)<<" Rank->"<<Rank[i]<<endl;
		if(g.get(i) == i){
			ans += Rank[i];
		}
	}

	cout<<ans<<endl;

    return 0;

}

/*
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10
*/