//DefendTheRohan.cpp
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

const int MAXN = 55;
const int inf = 1<<30;
int n,r;
int w[MAXN][MAXN], d[MAXN];

int dijkstra(int src, int dest){

	for(int i = 0; i<=n; i++) d[i] = inf;

	priority_queue <ppi,vector<ppi>,greater <ppi> > q;
	
	d[src] = 0;
	q.push({0,src});

	while(!q.empty()){
		
		int dist = q.top().fi;
		int cur = q.top().si;
		q.pop();

		if(dist>d[cur]) continue;

		for(int i=1; i<=n; i++){
			if(i==cur) continue;

			int next = i;

			int w_extra = w[cur][i];
			if(d[cur] + w_extra < d[next]){
				d[next] = d[cur] + w_extra;
				q.push({d[next],next});
			}

		}

	}
	return d[dest];

}
int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	int testcount = 1;
	while(t--){
		
		cin>>n;

		for(int i=1 ; i<=n;i++){
			for(int j=1 ; j<=n; j++)
				cin>>w[i][j];
		}
		cin>>r;
		int ans  = 0;

		while(r--){
			int a,b;
			cin>>a>>b;
			ans += dijkstra(a,b); 
		} 

		cout<<"Case #"<<testcount<<": "<<ans<<endl;
		testcount++;
	}

	return 0;
}
