//stringProblem.cpp
//Floyd Warshall's

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

	string s,t;

	cin>>s>>t;

	if(s.length() != t.length()){
		cout<<"-1"<<endl;
		return 0;
	}

	vector<vector<ll>> Word(26, vector<ll> (26,INT_MAX));

	for(int i=0;i<26;i++) Word[i][i] = 0;

	int edges;
	cin>>edges;	
	for(int i=0; i<edges ; i++){
		char u,v;
		ll w;
		cin>>u>>v>>w;
		Word[u-'a'][v-'a'] = min(Word[u-'a'][v-'a'],w);
	}

	for(int k=0; k<26; k++){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				Word[i][j] = min(Word[i][j],Word[i][k] + Word[k][j]);
			}
		}
	}

	ll min_cost = 0;
	string ans="";

	for(int i=0; i<s.length();i++){

		if(s[i] != t[i]){
			char currmin;
			ll currmincost=INT_MAX;

			for(int j=0; j<26; j++){
				
				if ( Word[s[i]-'a'][j] + Word[t[i]-'a'][j] < currmincost )
				{
					currmincost = Word[s[i]-'a'][j] + Word[t[i]-'a'][j];
					currmin = j + 'a';
				}
			}

			if(currmincost == INT_MAX)
			{
				cout<<"-1"<<endl;
				return 0;
			}
			min_cost += currmincost; 
			ans += currmin;
		}
		else
			ans += s[i];
	}
 
 	cout<<min_cost<<endl<<ans<<endl;

	return 0;
}

/*uayd
uxxd
3
a x 8
x y 13
d c 3
*/