#include <bits/stdc++.h>
using namespace std;
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define inf 10000005
#define f(a,n) for(int i=0;i<n;i++){if(prime[i]) cout<<i;}
bool prime[inf];

int main()
{
    fstIO;
    ll n;
    cin>>n;
    ll ar[n],freq[inf]={0};

    for(int i=0;i<n;i++){
        cin>>ar[i];
        //MAX=MAX<ar[i]?ar[i]:MAX;
        freq[ar[i]]++;
    }


    memset(prime,true,sizeof(prime)); 

    ll count[inf]={0},prefixsum[inf]={0};

    for(ll i=2;i<inf;i++)
    {
        if(prime[i])
        {
            for(ll j=i;j<inf;j+=i)
            {
                prime[j]=false;
                count[i]+=freq[j];
            }
        }
        prefixsum[i]+=prefixsum[i-1]+count[i];
    }

    ll m;
    cin>>m;

    while (m--)
    {
        ll l,r;
        cin>>l>>r;
        if (l > inf - 1)
            l = inf - 1;
        if (r > inf - 1)
            r = inf - 1;
 
        cout<<prefixsum[r]-prefixsum[l - 1]<<"\n";
    }
    return 0;    
}
