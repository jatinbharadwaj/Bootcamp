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

ll n,z,cost,food_trucks[1000005];

template<typename T>
class Graph
{
	unordered_map<T,list<ppi>> h;
    unordered_map<T, bool> visited;

public:
	void addEdge(T u,T v,ll cost,bool bidir=true){
		h[u].pb({v,cost});
		if(bidir)
			h[v].pb({u,cost});
	}

    ll solve(ll node){
        ll sum = 0;
        visited[node] = true;
        for(auto children : h[node]){
            ll cost = children.si;
            if(!visited[children.fi]){
                sum += min(solve(children.first),cost);
            }
        }

        sum += food_trucks[node];
        return sum;
    }
	

};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	//ll n;
	cin>>n>>z;
	Graph<ll> g;
	for(ll i = 1 ; i<n; i ++){
		ll x,y;
		cin>>x>>y>>cost;
		g.addEdge(x,y,cost);
	}

	for(ll i=1; i<=n ; i++){
		cin>>food_trucks[i];
	}
	
	cout<<g.solve(z)<<endl;
	//g.tps_bfs();
	return 0;
}
