#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
    ll n;
    cin>>n;
    unordered_map<ll,ll> umap;
    // freq[]=;
    
    for(int i=0;i<n;i++)
    {   
        ll x;
        cin>>x;
        umap[x]++;    
    }
    int count=0;
    for(auto &x:umap){
        int tmp=x.second-x.first;
        count+=tmp>=0?tmp:x.second;
    }
    cout<<abs(count);
}

