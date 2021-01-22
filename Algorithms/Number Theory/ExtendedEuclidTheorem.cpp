// ExtendedEuclidTheorem.cpp
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


int x, y, GCD;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

/*
	Ax + By = GCD(A,B)
	Bx1 + (A%B)y1 = GCD(B,A%B)    ------>Property of Euclidien theroem

	Here,
	x1 = Y
	y1 =  X - (A/B)*Y;

 
*/
void ExtendedEuclidMethod(int a, int b) {

	if (b == 0) {
		x = 1;
		y = 0;
		GCD = a;
		return;
	}

	ExtendedEuclidMethod(b,a%b);

	int cX = y;
	int cY = x - (a/b)*y;

	x = cX;
	y = cY;

}
int inverseModulo(int a, int m){
	ExtendedEuclidMethod(a,m);
	return (x+m)%m;
}

int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	
	// ExtendedEuclidMethod(18,30);
	// cout<<x<<y;
	cout<<inverseModulo(6,7)<<endl;

	return 0;
}

