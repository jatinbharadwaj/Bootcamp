// YetAnotherBrokenKeyboard.cpp
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


ll solve(int n,string s,int *alpha){

	int i = 0;
	ll sum=0,dp[AS]={0};

	for(;i<s.length();i++){
		ll k = 0;
		while(i<s.length() && alpha[s[i]-'a']){
			k++;
			i++;
		}	
		if(dp[k]!=0){
			sum += dp[k];
		}
		else{
			dp[k] = (k*k + k)/2;
			sum +=dp[k];
		}
	}
	return sum;
}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,k,alpha[26] = {0};
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<k;i++){
		char c;
		cin>>c;
		alpha[c-'a'] = 1;
	}

	cout<<solve(n,s,alpha);



	return 0;
}
