//pathtree.cpp
/*
let's find some diameter of the tree. Let 𝑎 and 𝑏 be the endpoints of this
diameter (and first two vertices of the answer). You can prove yourself
why it is always good to take the diameter and why any diameter can be
taken in the answer. Then there are two cases: the length of the
diameter is 𝑛−1 or the length of the diameter is less than 𝑛−1. 
In the first case, you can take any other vertex as the third vertex 
of the answer 𝑐, it will not affect the answer anyway.
Otherwise, we can run multi-source bfs from all vertices of the 
diameter and take the farthest vertex as the third vertex of the answer. 
It is always true because we can take any diameter and the farthest vertex will
increase the answer as much as possible.

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define ppi pair<int,int>
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

vector<int> p;
vector<std::vector<int>> g;

//Find Diameter of the tree
ppi dfs(int v,int par = -1,int distance = 0){

	p[v] = par;
	ppi res = mp(distance,v);

	for(auto to : g[v]){
		if(to == par) continue;
		res = max(res, dfs(to,v,distance+1));
	}
	return res;
}

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	p = vector<int>(n);
	g = vector<vector<int>>(n);

	for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);  
    }

    ppi da = dfs(0);
    ppi db = dfs(da.si);
    
    vector<int> diameter;
    int v = db.si;
    	
    
    while(v != da.si){
  
    	diameter.pb(v);
    	v = p[v];
    }

    // cout<<endl<<da.si<<endl;
    diameter.pb(da.si);

    if(int (diameter.size())== n){

        cout << n - 1 << " " << endl << diameter[0] + 1 << " " << diameter[1] + 1 << " " << diameter.back() + 1 << endl;
    }

    else {
    	//MUlti-Source_	BFS
    	queue<int> q;
    	vector<int> d(n,-1);

    	for( auto v: diameter){
    		d[v] = 0;
    		q.push(v);
    	}

    	while(!q.empty()){

    		int v = q.front();
    		q.pop();

    		for(auto children : g[v]){
    			if(d[children] == -1){
    				d[children] = d[v] + 1;
    				q.push(children);
    			}
    		}
    	}

    	ppi mx = mp(d[0],0);

    	for(int v = 1; v<n; ++v){
    		mx = max(mx,mp(d[v],v));
    	} 


      cout << int(diameter.size()) - 1 + mx.fi << endl << diameter[0] + 1 << " " << mx.si + 1 << " " << diameter.back() + 1 << endl;
    }
 
	return 0;
}
