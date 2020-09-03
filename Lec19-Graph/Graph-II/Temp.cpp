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
#define AS 200005
#define mod 1000000007


int solve(int *a,int n){

    if(n==1 || n==2) return 1;

    int max_so_far = a[0];
    int ans=a[1]<a[0]?1:0;

    for(int i=1;i<n-1;i++){

        if (a[i]>max_so_far)
        {
            max_so_far = a[i];
            if(a[i+1]<a[i])
                ans++;
        }
    }
    if(a[n-1]>a[n-2]) ans++;

    return ans;
}




int main(){
    
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t;
    cin>>t;
    int k=1;
    while(t--){
        int n;
        cin>>n;
        int ar[AS];
        F(ar,n);
        cout<<"Case #"<<k<<": "<<solve(ar,n)<<"\n";
        k++;

    }

    return 0;
}
