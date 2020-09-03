
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
struct edge{
	int x, y, we;
};
int n, m, r, l; 
vector< pair< int, int> > adj[MAXN];
edge  e[MAXN];
int dis[MAXN];
 
void di(int r){
	fill(dis, dis + n, INT_MAX);
	dis[r] = 0;
	set< pair< int, int> > s;
	s.insert({0,r});
	while( s.size() ){
		int v = s.begin() -> second;
		s.erase(s.begin());
		for(int i = 0; i < adj[v].size(); i ++){
			int u = adj[v][i].first;
			if( dis[v] + adj[v][i].second < dis[u]){
				s.erase({dis[u],u});
				dis[u] = dis[v] + adj[v][i].second;
				s.insert({dis[u],u});
			}
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> r;
	r --;
	for( int i = 0; i < m; i ++){
		int v, u, w;
		cin >> u >> v >> w;
		v --, u --;
		adj[v].push_back({u,w});
		adj[u].push_back({v,w});
		e[i].x = u, e[i].y = v, e[i].we = w;
	}
	cin >> l;
	di(r);
	int ans = 0;
	for( int i = 0; i < n; i ++)
		if(dis[i] == l) ans ++;
	for( int i = 0; i < m; i ++){
		int u = e[i].x, v = e[i].y, w = e[i].we;
		if( dis[u] < l && dis[v] < l && dis[u] + dis[v] + w == 2 * l)
			ans ++;
		if( dis[v] < l && (l - dis[v]) && l < dis[u] + w - (l - dis[v]))
			ans ++;
		if( dis[u] < l && (l - dis[u]) && l < dis[v] + w - (l - dis[u]))
			ans ++;
	}
	cout << ans << endl;
	return 0;
}