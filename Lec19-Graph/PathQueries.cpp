//PathQueries.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
typedef long long ll;

vector<ll> prefix(MAX,0);
class DSU{

	vector<ll> parent, rank;
public:
	DSU(ll n){
		parent.resize(n);
		rank.resize(n);
		for(int i=0;i<n;i++){
			parent[i] = i;
			rank[i] = 1;
		}
	}

	ll get(ll a){
		if(parent[a] == a) return a;
		return parent[a] = get(parent[a]);
	}

	void union_sets(ll a, ll b){

		a = get(a);
		b = get(b);

		if(a!=b){

			if(rank[a]<rank[b]){
				swap(a,b);
			}
			parent[b] = a;
			rank[a] += rank[b];
		}
	}

	ll getRankCount(ll a){
		a = get(a);
		return rank[a];
	}
};

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> edges;

    for(ll i=1; i<n; i++){

    	ll u,v,w;
    	cin>>u>>v>>w;
    	edges.push_back({w,u,v});
    }

    sort(edges.begin(),edges.end());
    DSU g(n+1);

    for(ll i=0; i<n-1; i++){
    	ll u = edges[i][1];
    	ll v = edges[i][2];
    	ll w = edges[i][0];

    	prefix[w] += g.getRankCount(u) * g.getRankCount(v);
    	g.union_sets(u,v);
    }

    for(ll i =1; i<MAX; i++){
    	prefix[i] += prefix[i-1];
    }

    while(m--){
    	ll w;
    	cin>>w;
    	cout<<prefix[w]<<" ";
    }

    cout<<endl;

    return 0;

}