//TwoFairs.cpp

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define ppi pair<ll,ll>
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007

ll m,n,a,b;
//Two nodes a & b one by one check if a is not in the map and another when b is not then 
template<typename T>

class graph{
	
	unordered_map <T,list<T>> h;

	void dfs(T node, T v, unordered_map<T,bool> &visited,ll &count){
			visited[node] = true;
			count++;

			for(T children: h[node]){
				if(!visited[children] && (children != v)){
					
					dfs(children, v, visited, count);

				}
			}
	}
public:
	void addEdge(T u,T v){
		h[u].pb(v);
		h[v].pb(u);
	}

	ll solve(){
		unordered_map<T, bool> visited;
		ll op1,op2;
		op1 = op2 = 0;
		ll count = 0;

		dfs(a,b,visited,count); // without a 
		op1 = n-count-1;
		//cout<<count<<endl;

		visited.clear();
		count = 0;
		
		dfs(b,a,visited,count); // without b
		op2 = n-count-1;
		//cout<<count<<endl;

		return op1*op2;
	}
};

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
    cin>>t;
    while(t--){
        
        cin>>n>>m>>a>>b;
       
        graph<ll> g;
        for(ll i=0;i<m; i++){
            ll x, y;
            cin>>x>>y;
            g.addEdge(x, y);
        }
       	
       	cout<<g.solve()<<endl;
    }
	return 0;
}

