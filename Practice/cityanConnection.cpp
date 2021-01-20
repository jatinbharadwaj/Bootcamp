    #include<bits/stdc++.h>
using namespace std;
    #define MAXN 200100
typedef long long ll;
    #define fst first
    #define snd second
typedef pair<ll,ll>ii;
vector<ii>g[MAXN];
ll a[MAXN];
ll resp[MAXN];
ll dist[MAXN];
vector<int>solve(vector<int> &A, vector<vector<int> > &B) {
   int n=(ll)A.size();
   int m=(ll)B.size();
   int u,v;
   ll w;
   vector<pair<int,ii>>edges;
   for(int i=0;i<m;i++){
       u=B[i][0];
       u--;
       v=B[i][1];
       v--;
       w=B[i][2];
       edges.push_back({u,{v,w}});
   }
   priority_queue<ii,vector<ii>,greater<ii>>q;
   for(int i=0;i<n;i++){
       dist[i]=A[i];
       q.push({dist[i],i});
   }
   for(auto x:edges){
       int u=x.first;
       int v=x.second.first;
       int w=x.second.second;
       g[u].push_back({v,w});
       g[v].push_back({u,w});
   }
   while(!q.empty()){
       ll d=q.top().first, u=q.top().second;
       q.pop();
       if(d>dist[u]) continue;
       for(auto v:g[u]){
           if(d + 2*v.second < dist[v.first]){
               dist[v.first] = d + 2*v.second;
               q.push({dist[v.first],v.first});
           }
       }
   }
   vector<int>ans1;
   for(int i=0;i<n;++i){
                //cout<<dist[i]<<" ";
    ans1.push_back(dist[i]);
}
           //cout<<endl;
return ans1;
}
int main(){



#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n,m;
    cin>>n>>m;
    vector<int>A(n);
    vector<vector<int>>B(m,vector<int>(3,0));
    for(int i=0;i<n;i++){
     cin>>A[i];
 }
 for(int i=0;i<m;i++){
     cin>>B[i][0]>>B[i][1]>>B[i][2];
 }
 vector<int>ans=solve(A,B);
 for(auto it:ans){
     cout<<it<<" ";
 }
}