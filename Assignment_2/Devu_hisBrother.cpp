#include <bits/stdc++.h>
using namespace std;
#define f(a,n) for(ll i=0;i<n;i++) cin>>a[i]
#define ll long long

int main() {
    ll m,n;
    cin>>m>>n;
    ll a[m],b[n];
    for(ll i=0;i<m;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        }
    sort(a,a+m);
    sort(b,b+n,greater<ll>());
    ll s=0;
    for(ll i=0;i<min(m,n);i++)
    {
        if(b[i]>a[i])
            s+=(b[i]-a[i]);
    }
    cout<<s;
    return 0;
}

