// SavingTheCity.cpp
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
		int a,b;
		cin>>a>>b;

		string s;
		cin>>s;
		int i=0;
		int activate=0, place = INT_MAX, total=0;
		bool activated=false;
		while(s[i]!='1' && i<s.length()){
			i++;
		}
		if(i!=s.length())
			total += a; i++;
		while(i<s.length()){
			
			if (s[i]=='1'){
				while(s[i]=='1') i++;				
			}
			else if( s[i]=='0'){
				place = 0;
				while(s[i]=='0'){
					place += b;
					i++;
				}				
			}

			if(i>0 && s[i]=='1' && s[i-1]=='0')
			{ 
				total += min(a,place);
				i++;
			}
				
		}
		cout<<total<<endl;
			
	}


	return 0;
}
