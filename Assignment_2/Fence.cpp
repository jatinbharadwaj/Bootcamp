#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() 
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   
 
    ll s=0,l=INT_MAX,sum=0,i=0;
 
    while(i<k)
    {
        sum+=a[i]; i++;
    }
    l=sum;
    while(i<n)
    {   
        sum+=a[i]-a[i-k]; 
        //cout<<sum<<' '<<i<<endl;
 
        if(sum<l)
        {   
            l=sum;
            s=i-k+1;
            //cout<<'h';
        }       
        ++i;
    }
    
    cout<<s+1;
    return 0;
}
