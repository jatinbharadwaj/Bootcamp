//linovaAndKingdom.cpp
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
#define AS 2000005
#define mod 1000000007

unordered_map<ll,list<ll>> graph;
vector<ll> depth(AS,0), cnt(AS,0), ans(AS,0);
unordered_map<ll, bool> visit;


ll DFS(ll node){
	visit[node] = 1;
	cnt[node] = 1;

	for(auto children: graph[node]){
		if(!visit[children]){
			cnt[node] = cnt[node] + DFS(children);
		}
	}
	return cnt[node];
}

void BFS(){

	unordered_map<ll , bool> visited;
	queue<ll> q;

	q.push(1);
	depth[1] = 0;
	visited[1] = 0;
	//cout<<q.front();

	while(!q.empty())
	{
		ll front = q.front();
		q.pop();

		for(auto children : graph[front]){

			if(!visited[children]){

				depth[children] = depth[front]+1;
				visited[children] = true;
				q.push(children);
			}
		}
	} 	
	return;
}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n,k;
	cin>>n>>k;
	
	for(ll i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x); 
	}

	BFS();
	DFS(1);

	ans[0] = INT_MIN;
	for(int i=1; i<=n; i++) 
	{
		cout<<i<<"->"<<cnt[i]<<" ";
		ans[i] = depth[i]-cnt[i]+1;
	}
	cout<<endl;

	sort(ans.rbegin(),ans.rend());
	ll max_cost=0;
	for(ll i=0;i<k;i++){
		max_cost += ans[i];
	}
	cout<<max_cost<<endl;

	return 0;
}
