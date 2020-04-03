#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<ll> v;
    vector<ll> vec;
    ll s=0;

    for(int i=0;i<n;i++)
    { 
        ll c,t;
        cin>>c>>t;
        s+=c*t; 
        v.push_back(s); 
    }

    for(int i=0;i<m;i++){
        ll mo;
        cin>>mo; 
        vec.push_back(mo);
    }
    int j=0;
    for(int i=0;i<m;i++){
        while(vec[i]>v[j])
        {
            ++j;
        }
        
        cout<<j+1<<endl;
    }

    return 0;
}
