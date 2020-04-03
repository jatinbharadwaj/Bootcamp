#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll m,n;
    cin>>m>>n;
    ll a[m],b[n];
    a[0]=0;

    for(int i=0;i<m;i++)
    {   ll k;
        cin>>k;
        if(i==0)
            a[i]=k;
        else    
            a[i]=k+a[i-1];
    }
    ll tmp=a[m-1],sum=0;

    for(int i=0;i<n;i++)
    {   
        ll k;
        cin>>k;
        sum+=k;
        if(k>tmp || sum>tmp)
        { 
            b[i]=k;
            sum=0;
        }

        else
        {   
            b[i]=sum;
        }
    }
    for(int i=0;i<n;i++){ 
        int tmp=upper_bound(a,a+m,b[i])-a;
        if(tmp<m)
            cout<<m-tmp<<endl;
        else
            cout<<tmp<<endl;  
          }
    /*cout<<endl;
    for(int i=0;i<m;i++){ cout<<a[i]<<' ';   }
    cout<<endl;
    for(int i=0;i<n;i++){ cout<<b[i]<<' ';   }
    */
    return 0;

}

