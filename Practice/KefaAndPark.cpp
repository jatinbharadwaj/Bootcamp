// KefaAndPark.cpp
// https://codeforces.com/problemset/problem/580/C
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
#define MAXN 100005
#define mod 1000000007

int CAT[MAXN];

int n, k, ans = 0;

template<typename T>
class Graph {
	unordered_map<T, list<T> > h;

public:
	void addEdge(T u, T v, bool bidir = true) {
		h[u].pb(v);
		if (bidir)
			h[v].pb(u);
	}

	void dfs(int u, int p, int cats) {

		// check karo CAT HAI YA NHI AGAR HAI TOH ADD KARDO PICHLE CONSECUTIVE CATS MEIN 
		if (CAT[u])
			cats++;
		else
			cats = 0; // AGAR NHI TOH 0 kyuki Consecutive check karni hai 

		if (cats > k) { return; }	// AGAR CAT ZAYDA HEIN TOH RETURN 

		if (h[u].size() == 1 && u != 1) {
			ans++;  //ANS increment by 1 kyuki yeh leaf node hai
			return;
		}

		for (auto v : h[u]) {
			if (v != p ) {
				dfs(v, u, cats);
			}
		}


	}
};


int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//	int t;
	//	cin>>t;

	// while(t--){

	//	}
	cin >> n >> k;
	F1(CAT, n);

	Graph<int> g;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g.addEdge(a, b);
	}

	g.dfs(1, -1, CAT[0]);
	cout << ans;



	return 0;
}

