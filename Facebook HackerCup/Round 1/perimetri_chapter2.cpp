// perimetri_chapter2.cpp

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
int ans = 1;

void solve(ll *L,ll *H,ll *W, ll *P){

	ll i=0,ox=L[0]+W[0],nx = 0,l=W[0],h=H[0];
	P[0] = 2*(W[0] + H[0]);
	ans = P[0];
	ll tmp = 0;
	
	for(int i=1;i<n;i++){

		if(i>=k){
			L[i] = (((al*L[i-2])%dl  + (bl*L[i-1])%dl  + cl)%dl + 1);
			H[i] = (((ah*H[i-2])%dh + (bh*H[i-1])%dh + ch)%dh + 1);
			W[i] = (((aw*W[i-2])%dw + (bw*W[i-1])%dw + cw)%dw + 1);
			
		}

		nx = L[i] + W[i];
		if(L[i]<=ox){
			// cout<<ox<<" "<<nx<<endl;
			l+= nx-ox;

			h = max(h,H[i]);
			//cout<<l<<"______"<<h<<endl;
			P[i] = 2*l + 2*h + (tmp%mod);
			ox = nx;

		}

		else{
			tmp+=P[i-1];
			h = H[i];
			l = W[i];
			//cout<<l<<" "<<h<<endl;
			P[i] = (tmp%mod) + 2*l + 2*h;
			ox = nx;
		}
		
		//P[i] = P[i]%10000000;

		ans = (ans*P[i] + mod)%mod;
		
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
		
		cin>>n>>k;
		
		ll *L = new ll[n+1];
		ll *H = new ll[n+1];
		ll *W = new ll[n+1];
		ll *P = new ll[n+1];

		// ll al,bl,cl,dl,ah,bh,ch,dh;

		F(L,k);
		cin>>al>>bl>>cl>>dl;
		F(W,k);
		cin>>aw>>bw>>cw>>dw;
		F(H,k);
		cin>>ah>>bh>>ch>>dh;
		
		P(L,k);
		P(W,k);
		P(H,k);

		solve(L,H,W,P);
		P(P,n);
		cout<<"Case #"<<ca<<": "<<ans<<endl;
		
		ca++;
		free(L);
		free(H);
		free(W);
		free(P);
			
	} 
	return 0;
}
