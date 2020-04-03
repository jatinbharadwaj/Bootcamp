#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int m;
    cin>>m;
    ll a[m],res=0;
   
    for(int i=0;i<m;i++)
    {   
        cin>>a[i]; 
    }
    sort(a,a+m);
    for(int i=0;i<m;i++)
    {
        res+=abs(i+1-a[i]);
    }
    cout<<res;

    return 0;
}
