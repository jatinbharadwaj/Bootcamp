#include<bits/stdc++.h>
using namespace std;
#define ll long long
 void add(ll arr[], ll N, ll lo, ll hi) 
{ 
	arr[lo] += 1; 
	if (hi != N - 1) 
	arr[hi + 1] -= 1; 
} 
void updateArray(ll arr[], ll N) 
{ 
	
	for (int i = 1; i < N; i++) 
		arr[i] += arr[i - 1]; 
}
int main(){

    ll n,q;
    cin>>n>>q;
    ll a[n];
    vector<pair<ll,ll>> v;
    
    for(int i=0;i<n;i++)
    {   cin>>a[i];   }

    for(int i=0;i<q;i++)
    {
        ll q,r;
        cin>>q>>r;
        v.push_back(make_pair(q,r));        
    }
    ll ar[n];
    memset(ar,0,sizeof(a));
   
    for(int i=0;i<q;i++)
    {   
            add(ar,n,v[i].first-1,v[i].second-1);

    }
    updateArray(ar, n);
    sort(ar,ar+n);
    sort(a,a+n);
    ll sum=0;
    for(int i=0;i<n;i++){
        
        sum+=a[i]*ar[i];
    }
    cout<<sum;
    return 0;
}
