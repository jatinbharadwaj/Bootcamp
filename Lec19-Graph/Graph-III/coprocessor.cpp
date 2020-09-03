//coprocessor.cpp
//Dynamic programming in Graphs

#include<bits/stdc++.h>
using namespace std;

const int N = 123456;
int n,m,dp[N];
vector<int> adj[N];
bool c[N];

int dfs(int node){

	if(dp[node] != -1) return dp[node];

	dp[node] = c[node]; //either 0 or 1;

	for(int i:adj[node]){
		dp[node] = max(dp[node], dfs(i) + (c[node] && ! c[i]));
	}
	return dp[node];
}

int main(){
	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    cin>>n>>m;
  	

  	for(int i=0;i<n;i++) cin>>c[i];

  	while(m--){
  		int x,y;
  		cin>>x>>y;
  		adj[x].push_back(y);
  	}

  	fill(dp,dp + n, -1);
  	int ans = 0;
  	for(int i=0;i<n;i++){
  		ans = max(ans,dfs(i));
  	}
  	cout<<ans<<endl;

  	return 0;
}