// perimetric.cpp
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

ll n,k,w;
ll al,bl,cl,dl,ah,bh,ch,dh;
ll aw,bw,cw,dw;
ll ans= 1;

void solve(ll *L,ll *h, ll *p){
	p[0] = (2*(w+ h[0]))%mod; 
	ans = p[0];
	ll tmp = 0;		
    for(int i=1; i<n; i++){
    	if(i>=k){
			L[i] = (((al*L[i-2])%dl  + (bl*L[i-1])%dl  + cl)%dl + 1);
			h[i] = (((ah*h[i-2])%dh  + (bh*h[i-1])%dh +  ch)%dh + 1);
		}
	    ll x = w; 
	    ll y = h[i]; 
	    p[i] = (p[i-1]%mod + (2*(x+y))%mod)%mod; 
	    if(L[i]<(L[i-1]+w)){ 
	        ll ix = L[i-1]+w-L[i]; 
	        ll iy = min(h[i],h[i-1]); 
	        p[i] = (p[i] - 2*(ix+iy) + mod)%mod;
        }
        cout<<p[i]<<" ";
        ans *= p[i];
        ans %= mod;
	}	
}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	int ca=1;
	
	while(t--){
		
		cin>>n>>k>>w;
		
		ll *L = new ll[n+1];
		ll *H = new ll[n+1];
		ll *P = new ll[n+1];

		// ll al,bl,cl,dl,ah,bh,ch,dh;

		F(L,k);
		cin>>al>>bl>>cl>>dl;
		F(H,k);
		cin>>ah>>bh>>ch>>dh;
		//P(L,k);
		//P(H,k);

		solve(L,H,P);
		cout<<"Case #"<<ca<<": "<<ans<<endl;
		// P(L,n);
		// P(H,n);
		// P(P,n);
		ca++;
		free(L);
		free(H);
		free(P);
		
	} 
	return 0;
}
