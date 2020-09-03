#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
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

ll n,m,r,c,x,y;

ll rows[4]={0,0,1,-1};
ll cols[4]={1,-1,0,0};
ll cost[4]={0,1,0,0};  //

string maze[2005];
ll dp[2005][2005];

bool isvalidcell(ll x, ll y){
	return (x>=0 && y>=0 && x<r && y<c && maze[x][y] == '.');
}

void  solve(){
	deque<pii> q;
	memset(dp,-1,sizeof dp);
	
	//yha mein khada hu
	dp[r][c] = 0;
	q.pb({r,c});

	while(!q.empty()){
		auto node = q.front();
		q.pop_front();

		ll ci = node.fi;
		ll cj = node.si;
		for(ll i = 0 ; i<4 ; i++){
			
			ll ni = ci + rows[i];
			ll nj = cj + cols[i];
			ll len = cost[i]; //

			if(isvalidcell(nx,ny)){
				// mein jis bhi cell p aaya hu agr iska dist -1 then i can update it 
				// otherwise iska current dist zayda hote hein 

				if(dp[ni][nj] == -1 || dp[ni][nj] > dp[ci][cj] +cost ){
					dp[ni][nj] = dp[ci][cj] + cost;

				}
				if(cost){
					q.pb({ni,nj});
				}
				else 
					q.push_front({ni,nj})

			}
		}
	}

	for(ll i=0 ; i<r ;i++){
		for(ll j =0; j<c ;j++){
			ll left = dp[i][j];
			if(left != -1){

			}
		}
	}
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cin>>n>>m>>r>>c>>x>>y;
	r--; c--;
	for(ll i=0; i<n ; i++){
		cin>>maze[i];
	}
	return 0;
}
