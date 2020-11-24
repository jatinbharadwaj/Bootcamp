// Vitamins.cpp
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

const int INF = 1e9;

map <string, int> m;
int n;

int getC(string a, string b) {
 	if (!m.count(a) || !m.count(b)) {
 		return INF;
 	}
 	return m[a] + m[b];
}

void solve(){

	int ans = INF;

	// if A,B,C 
	if(m.count("A") && m.count("B") && m.count("C")){
		ans = m["A"] + m["B"] + m["C"];
		
	}

	if(m.count("ABC")){
		ans = min(ans,m["ABC"]);
	}

	ans = min(ans, getC("AB", "C"));
    ans = min(ans, getC("A", "BC"));
    ans = min(ans, getC("AC", "B"));
    ans = min(ans, getC("AB", "BC"));
    ans = min(ans, getC("AC", "BC"));
    ans = min(ans, getC("AC", "AB"));

    if (ans == INF) {
    	ans = -1;
    }
    cout << ans << endl;


}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	cin>>n;

	for(int i=0;i<n;i++){
		int c;
		string s;

		cin>>c>>s;
		sort(s.begin(),s.end());

		if(m.count(s)==0){
			m[s] = c;

		}
		else{
			m[s] = min(m[s],c);
		}
	}



	solve();

	return 0;
}
