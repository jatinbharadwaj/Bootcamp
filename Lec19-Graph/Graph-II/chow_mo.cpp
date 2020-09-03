//chow_mo.cpp
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
const ll inf=1e15;

// Need to apply dijkstra on two adjacency matrix with common distance vector 
// First adjacency matrix of given n-1 nodes
// second adjacency matrix of same color nodes with a array of cost 


int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<int> adj[n+1];
		vector<ll> color[n+1];
		int col[n+1];
		int cost[n+1];
		int s,dest;
		
		for(int i=2;i<=n;i++){
			int tmp;
			cin>>tmp;
			adj[tmp].pb(i);
			adj[i].pb(tmp);
		}
		
		for(int i=1;i<=n;i++){
			int tmp;
			cin>>tmp;
			color[tmp].pb(i);
			col[i] = tmp;
		}

		for(int i=1;i<=n;i++){
			int tmp;
			cin>>cost[i];
		}

		cin>>s>>dest;

		//DIJKSTRA'S

		ll distance[n+1];
		for(int i = 1; i<=n; i++) distance[i] = inf;

		priority_queue<pair<ll,int>> pq;
		distance[s] = 0;
		int visited[n+1] = {};
		int wh[n+1] = {};

		pq.push({0,s});

		while(!pq.empty()){

			// -ve because priority queue required in ascending order
			ll w = -pq.top().fi;
			int u = pq.top().si;
			pq.pop();

			if(visited[u]) continue;
			visited[u] = 1;

			for(int i=0;i<adj[u].size();i++){
				int v=adj[u][i];

                if(distance[v]>distance[u]+d)
                {
                    distance[v]=distance[u]+d;
                    pq.push({-distance[v],v});
                }
			}

			int k=col[u];
            if(wh[k])continue;
            wh[k]=1;
            for(int i=0;i<color[k].size();i++)
            {
                if(visited[color[k][i]])continue;

                int v=color[k][i];
                if(distance[v]>distance[u]+cost[u])
                {
                    distance[v]=distance[u]+cost[u];
                    pq.push({-distance[v],v});

                }
            }

		}

		cout<<distance[dest]<<endl;
		
	}

	return 0;
}
