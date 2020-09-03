// Cow_DSU.cpp
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


class dsu{
	vector<ll> parent, rank;
	ll totalcomponents;

public:
	dsu(ll n){
		parent.resize(n+1);
		rank.resize(n+1);

		for(ll i = 1; i <= n ; i++){
		
			parent[i] = i; // making the node parent of itself
			rank[i] = 0;
		} 	// all rank has same 0
			totalcomponents = n;
	}	
	
	ll get(ll a)
	{
		if(a == parent[a]){
			return a;
		}
		return parent[a] = get(parent[a]); //get the root node
		
	}

	void union_set(ll a, ll b){

		a = get(a);
		b = get(b);

		if(a != b){

			if(rank[a]<rank[b]){
				swap(a,b);
			}
			parent[b] = a;

			if(rank[a] == rank[b]) 
				rank[a]++;
			totalcomponents--;
		}
	}

};

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;
	dsu g(n);

	for(int i = 0; i<k ; i++){
		int x,y;
		cin>>x>>y;
		g.union_set(x,y);
	}

	bool leader[n+1] = {0};

	for(int i=1; i<=n; i++){

		leader[g.get(i)] = true;
	}

	int c = 0;
	for(int i=1;i<=n;i++){
		
		if(leader[i]) c++;
	}
	//cout<<c<<endl;
	cout<<k-(n-c)<<endl;

	return 0;
}
//use the nodes ans dishes and edges as guests
// we create disjoint components
// a single component of size c is at max capable of feeding c-1 guests 
//as the 1st guest will eat 2 dishes rest eat one
//use dsu to create disjoint components
// total satisfied guests = comp_size - 1 , for each component
// hence, comp_size1 -1 + compo_size2 - 1... comp_sizen -1 
//(comp_size1 to comp_sizen) == n
// and -1 occurs n times
//hence, satisfied guest-> n - c
//unsatisfied guests = k- (n-c)