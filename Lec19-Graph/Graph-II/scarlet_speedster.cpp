//scarlet_speedster.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define ppi pair<int,int>
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
// odd-odd = even
// odd-even = odd
// even - even = even

ll n,m,x,y;
vector<vector<ll> >adj;
vector<vector<bool> >visited;

const int dx[] ={0, 0, 1, -1};
const int dy[] ={1, -1, 0, 0};

bool isValid(int i, int j){
    return (i>=0 and j>=0 and i<n and j<m and !visited[i][j]);
}

int BFS(bool even=true){

	deque<pair<int, ppi > >q;
	q.push_back({0, {0,0}});
	visited[0][0]=true;

	 while(!q.empty()){
	        pair<int, ppi >front = q.front();
	        q.pop_front();

	        int old_x = front.second.first;
	        int old_y = front.second.second;
	        int dist = front.first;

	        for(int i=0; i<4; i++){
	            int new_x = old_x+dx[i];
	            int new_y = old_y+dy[i];

	            if(!isValid(new_x, new_y))continue;
	            if(even){
	                visited[new_x][new_y]=true;
	                if((adj[old_x][old_y]&1) == (adj[new_x][new_y]&1)){
	                    q.push_front({dist, {new_x,new_y}});
	                    if(new_x == n-1 and new_y==m-1)return dist;
	                }
	                else{
	                    q.push_back({dist+1, {new_x,new_y}});
	                    if(new_x == n-1 and new_y==m-1)return dist+1;
	                }
	            }
	            else{
	                visited[new_x][new_y]=true;
	                if((adj[old_x][old_y]&1) != (adj[new_x][new_y]&1)){
	                    q.push_front({dist, {new_x,new_y}});
	                    if(new_x == n-1 and new_y==m-1)return dist;
	                }
	                else{
	                    q.push_back({dist+1, {new_x,new_y}});
	                    if(new_x == n-1 and new_y==m-1)return dist+1;
	                }
	            }
	        }
	    }

	    return INT_MAX;
}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){

		cin>>n>>m>>x>>y;

	    adj.assign(n, vector<ll>(m));
	    visited.assign(n, vector<bool>(m, false));

	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>adj[i][j];
	        }
	    }    

	    ll flash_dist = BFS();
	    flash_dist *= x;
	    
	    visited.assign(n, vector<bool>(m, false));

	    ll reverse_flash_dist = BFS(false);
	    reverse_flash_dist *= y;

	    if(flash_dist < reverse_flash_dist){
	        cout<<"YES\n";
	    }
	    else cout<<"NO\n";

	}

	return 0;
}
