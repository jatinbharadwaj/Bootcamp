#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define scan(any)       for(auto &i:any) cin>>i;
#define print(any)      for(auto i:any) cout<<i<<" "; 
#define endl            '\n'
#define pb              push_back
#define vll             vector<ll> 
#define f(i,x,y)        for(i=x;i<y;i++)
#define INF             LLONG_MAX
#define s(x)            sort(x.begin(),x.end())
#define all(v)          v.begin(),v.end()
#define p2(n,x)         cout << fixed << setprecision(x) <<n<<endl; 
#define pll             pair<ll,ll> 
#define ff              first
#define ss              second
#define blt(x)          __builtin_popcount(x)

void solve()
{
    ll i,j,k,n;
    cin>>n;
    vll v(n);
    scan(v);
    ll mn=v[0];
    f(i,1,n)
    {
    	if(v[i]>=v[i-1])
    	{
    		mn=min(mn,v[i]);
    	}
    	else
    	{
    		ll dif=v[i-1]-v[i];
    		if(mn<dif)
    		{
    			cout<<"NO\n";
    			return ;
    		}
    		mn-=dif;
    		mn=min(mn,v[i]);
    	}
    }
    cout<<"YES\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();    
    }
    return 0;
}	