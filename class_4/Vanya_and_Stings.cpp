#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(a,n) for(int i=0;i<=n;i++){ cout<<a[i]<<' '; }
int main() 
{
    ll n,m;
    cin>>n>>m;
    ll a[n];
    a[0]=0;
    

    for(ll i=0;i<n;i++){ cin>>a[i]; }

    sort(a,a+n);
    

    double diff=0,d=0,k=0;

    for(ll i=0;i<n-1;i++)
    {  
       
        diff = a[i+1] - a[i];
        
        if(diff>d)
            d = diff;  
        k = d/2;
    } 

    d = d/2;

    double low = a[0] - 0;
    
    double high = m - a[n-1];


    high = high>low ? high:low;
    d = high>d ? high:d;
    cout<<setprecision(10)<<d;

    return 0;
}
