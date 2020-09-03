//travel.cpp
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

	int t;
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string incoming,outgoing;
		cin>>incoming>>outgoing;

		//unordered_map<int,list<int>> mp;
		char ans[n][n];
		memset(ans,'N',sizeof(ans));

		for(int i=0;i<n-1;i++)
		{
			if(incoming[i]=='Y' && outgoing[i+1]=='Y')
				ans[i+1][i] = 'Y';	
			if(incoming[i+1]=='Y' && outgoing[i]=='Y')
				ans[i][i+1] = 'Y';
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
			{
				if(i==j)
				{ 
					ans[i][j]='Y';
				}
				cout<<ans[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
