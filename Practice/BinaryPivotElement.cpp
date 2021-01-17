// BinaryPivotElement.cpp
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


//  1 2 3 4 8 5 6 7
//  8 7 6 5 4 3 2 1
//  1 2 3 4 5 6 8 7

int findPivot(int *a, int n) {


	int s = 0, e = n - 1;

	if(a[s]>a[s+1]){
		return s;
	}

	if(a[e-1]>a[e]){
		return e-1;
	}

	while (s <= e) {
		int m = (s + e) / 2;

		if (m < e && a[m] > a[m + 1])
			return m;

		if (m > s && a[m] < a[m - 1]) {
			return m-1;
		}

		if (a[s] >= a[m]) {
			e = m - 1;
		}
		else {
			s = m + 1;
		}

	}

	return -1;
}

int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;
		int a[n];
		F(a, n)
		P(a, n)

		int k = findPivot(a, n);
		cout<<a[k]<<endl;
	}



	return 0;
}

