// CyclicShift.cpp
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

int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {

		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		string cs =s+s;
		int a[AS],pos=0,mx=INT_MIN;

		a[0] = cs[0]-'0';
		for(int i=1;i<2*n-1;i++){
			if(cs[i]=='1'){
				a[i]=a[i-1]+1;
			}
			else
				a[i]=0;

			if(a[i]>mx){
				mx=a[i];
				pos=i-a[i]+1;
			}

		}
		P(a,2*n-1)

		if(a.find(as))

			int ans = pos + ((s.length())* (k-1));
		cout<<ans<<endl;
	}
	// 111100

	return 0;
}

