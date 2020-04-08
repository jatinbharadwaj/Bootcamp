#include <bits/stdc++.h>
#define ll long long int
#define inf 100005
#define f(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}
using namespace std;
int main() {
    ll n;
    cin>>n;
    ll a[inf],prefix[inf]={0},prefix2[inf]={0};
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(i==0)
            prefix[i]=a[i];
        else
            prefix[i]=prefix[i-1]+a[i];
    }
   // f(prefix,n);cout<<endl;

    sort(a,a+n);

  
    for(ll i=0;i<n;i++){
        
        if(i==0)
            prefix2[i]=a[i];
        else
            prefix2[i]=prefix2[i-1]+a[i];
    }  
    //f(prefix2,n);cout<<endl;

    ll m;
    ll q,l,k;
    cin>>m;
    while(m--){
        
        cin>>q>>l>>k;

        if(q==1){
            
            if(l==1) cout<<prefix[k-1];

            else
                cout<<prefix[k-1]-prefix[l-2];
        }
        else
        {
                if(l==1) cout<<prefix2[k-1];
                else    cout<<prefix2[k-1]-prefix2[l-2];
        }

        cout<<endl;    

    }
    return 0;
}

