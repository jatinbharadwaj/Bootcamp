//NavigationSystem.cpp
//Transpose of a Graph

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
#define AS 200005
#define mod 1000000007

vector<ll> adj[AS];

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n,m,k;
	cin>>n>>m;
	for(int i=0; i<m;i++){
		ll u,v;
		cin>>u>>v;
		adj[v].push_back(u);
	}

	cin>>k;

	ll a[k];
	for(int i=0;i<k;i++) cin>>a[i];

	vector<ll> Distance(n+1,INT_MAX);
	vector<ll> path_count(n+1,0);

	queue<ppi> q;
	// Transposed Destination is treated as source Node
	q.push({0,a[k-1]});
	Distance[a[k-1]] = 0;

	//Bredth First Traversal on Transpose

	while(!q.empty()) {

		auto front = q.front();
		q.pop();

		for(ll children : adj[front.si]){

			if(Distance[children] > Distance[front.si]+1){
				Distance[children] = Distance[front.si]+1;
				path_count[children] = 1;
				q.push({Distance[children],children});
			}

			else if(Distance[children] ==  Distance[front.si] +1){
				path_count[children]++;
			}
		}
	}

	int maxi,mini;
	maxi=mini=0;


	for(ll i=0; i<k-1;i++){

		if(Distance[a[i]]-1 < Distance[a[i+1]]){
			maxi++; mini++;
		}
		else if(path_count[a[i]]>1){
			maxi++;
		}

	}
	cout<<mini<<" "<<maxi<<endl;

	return 0;
}

/*
6 9
1 5
5 4
1 2
2 3
3 4
4 1
2 6
6 4
4 2
4
1 2 3 4
*/