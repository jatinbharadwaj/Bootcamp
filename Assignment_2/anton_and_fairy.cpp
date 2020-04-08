#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 2e9

int main()
{
    
    ll n,m;
    cin>>n>>m;
    ll s=1,e=inf,ans=0;
    if(n<=m)
    { 
        cout<<n;
        return 0;
    }
    else{ 
            ll k=n-m;
            while(s <= e)
            {
                ll mid = (s+e)/2;
                ll l = (mid*(mid+1))/2;
                if(l >= k)
                {
                    ans=mid;
                    e=mid-1;
                }
                else s=mid+1;
            }      
        }

    cout<<ans+m;
    
    return 0;
}
