//Reachability.cpp

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


ll n,m,s;
ll MAX = 1000005;

template<typename T>
class Graph{

	unordered_map <T,list<T>> h;
	vector<bool> visit;
	vector<pair<int,ll>> unreachable_vertex_count;

public:
	Graph(){
		visit.assign(MAX,0);
		//unreachable_vertex_count()
	}
	void addEdge(T u, T v, bool bidir = false){

		h[u].pb(v);
	}
	//Travel all nodes reachable from the capital
	void dfs(T node)
	{
		visit[node] = true;

		for(auto child : h[node]){
			if(!visit[child]){
				dfs(child);
			}
		}

	}

	void dfs_unreachable(T node,vector<bool> &unreachable, ll &cnt){

		unreachable[node] = true;
		cnt++;

		for(auto child : h[node] ){
			//cout<<child<<" ";
			if(!visit[child] && !unreachable[child]){
				dfs_unreachable(child,unreachable,cnt);
			}
		}

	}

	ll solve(){
		
		//cout<<" code is here";

	
		vector<bool> unreachable(n+1,0);

		ll cnt = 0;

	//count all unreachable nodes or unvisited nodes in after first dfs	and store all unreachable node in a vector
	for(int i =1; i<= n; i++){
			if(!visit[i]){
				cnt = 0;
				dfs_unreachable(i, unreachable, cnt);
				unreachable.assign(n+1, 0);
				unreachable_vertex_count.pb({cnt,i});


			}
		}

		//sort the unreachable nodes 

		sort(unreachable_vertex_count.begin(),unreachable_vertex_count.end());
		reverse(unreachable_vertex_count.begin(),unreachable_vertex_count.end());

		ll ans = 0;

		//count all nodes needed to be added add nodes after connecting some node x.si
		for(auto x : unreachable_vertex_count){
			//cout<<x.si<<" ";
			if(!visit[x.si]){
				ans++;
				dfs(x.si);
			}
		}
		
		return ans;
	}

};

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	Graph<ll> g;

	cin>>n>>m>>s;


	for(int i=0; i<m; i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	g.dfs(s);

	ll ans = g.solve();
	//DFS starts from root node or capital
	cout<<ans<<endl;
	return 0;
}

/*
9 9 1
1 2
1 3
2 3
1 5
5 6
6 1
1 8
9 8
7 1
*/