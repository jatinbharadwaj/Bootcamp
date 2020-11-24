// LectureSleep.cpp
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

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,k,overall = 0;
	cin>>n>>k;

	ll a[n],t[n]; 
	F(a,n);
	F(t,n);

	int dp[n]={0};

	int res = 0;
	for(int i=0;i<n;i++){
		if(i){
			dp[i] += dp[i-1]; 
		}
		if(t[i]==0) dp[i] += a[i];

		else 
			overall +=a[i];
	}

	// for(auto x:dp) cout<<x<<' ';
	// cout<<endl;

	int add = 0;
	
	for(int i=k-1;i<n;++i){
		add = max(add,dp[i]-(i>=k?dp[i-k]:0));
	}

	cout<<overall+add<<endl;
	
	return 0;
}
