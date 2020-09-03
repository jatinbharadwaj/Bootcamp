//Timber.cpp
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
	int c=1;

	while(t--){
		ll n,m,k=0;
		cin>>n>>m;
	
		ll a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		k=m;
		ll cost=0,curr_min=INT_MAX;

		for(int i=n-1;i>=0;i--){
			
			//for(int j=i-1;j>=i-m;i++)

			if(i+m<n && curr_min==a[i+m]){
				curr_min = a[i+m-1]; 
			}
			if(i<n-m-1)
			{
				cost +=curr_min;
				curr_min=a[i]; 

				if(curr_min>a[i] && a[i]!=0 ){
					curr_min = a[i];
				}
			}

			if(curr_min>a[i] && a[i]!=0){
				curr_min = a[i];
			}
		}


		cout<<"Case #"<<c<<": ";
		c++;
		cout<<cost<<endl;

	}

	return 0;
}
