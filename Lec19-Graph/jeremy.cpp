#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i/*
Logic:
We have to max dist amd min dist travlled while assigning house to 2k people.
we use same logic of HOLI (spoj question)
 
For Max dist we need to find how many max time we can use a particular edge.
For this we cal no of nodes in subtree in both direction for each edge (in left and right dir).
 
So ek edge max kitni bar use hogi uske liye hum uss edge ke right and left dono side mein kitni
nodes hai voh count kar lee, qki we need to chnage every person house so for a particular edge ke liye
uske left ke sabhi nodes edges ke right side ki nodes se house changes karegi.
 
now we tak min of these left,right nodes qki ghar tabhi swap hoga jab people available honge.
so if we have 3 in left and 5 in right toh 3 vale toh right mein ja sakta hai but 5 vale sare nahi sirf 3 
ja sakta hai.
 
For min dist we want ki hum ek edge ko kitni kam bar use kar sakta hai. So we want ki ek subtree mein nodes
apas mein hi ghar assign kar lee rather than to go in opposite direction as we did in to maximise dist
means if for a particualr node it has 4 nodes in its subtree, we assign house to couple in this substree
rahter than assign house in upper nodes of parent node.
 
So if in a substree we have even count of nodes we need not to worry as we can assign them house as they are even
But if we have odd nodes then we have to assign a node a house in upper tree(in other component).
So we use concept of mod 2.
 
so we take min(left, right)%2, this gives min usage of a edge
*/
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e4+5;
const int mod = 1e9+7;
ll n;


template<typename T>
class graph{
    unordered_map<T, list<pair<T, ll>>> m;
    //using dfs to find nodes in subtree on one side of the edge
    ll maxval_dfs(T node, unordered_map<T, bool> &visited, ll *cnt, ll &ans){
        visited[node]=1;

        cnt[node]=1;

        for(auto child:m[node]){

            ll dx= child.si;

            if(!visited[child.fi]){
                cnt[node] += maxval_dfs(child.fi, visited, cnt, ans);
                //NOTE: for edge btw node and child
                ll right = cnt[child.fi];
                ll left = n - right;
                ans += min(left, right)*dx;
            }
        }
        return cnt[node];
    }

    ll minval_dfs(T node, unordered_map<T, bool> &visited, ll *cnt, ll &ans){
        visited[node]=1;

        cnt[node]=1;

        for(auto child:m[node]){

            ll dx= child.si;

            if(!visited[child.fi]){
                cnt[node] += minval_dfs(child.fi, visited, cnt, ans);
                ll right = (cnt[child.fi])%2;
                ll left = (n- right)%2;
                ans += min(left, right)*dx;
            }
        }
        return cnt[node];
    }
public:
    void AddEdge(T a, T b, ll cost,bool bidir=true){
        m[a].pb(mp(b, cost));
        if(bidir){
            m[b].pb(mp(a, cost));
        }
    }

    ll max_val(){
        unordered_map<T, bool> visited;
        ll *cnt = new ll[n+1]; //stores the number of nodes on one side of an edge

        for(ll i=1; i<=n; i++){
            cnt[i]=0;
        }
        ll ans=0;
        maxval_dfs(1, visited, cnt, ans);
        return ans;
    }
    ll min_val(){
        unordered_map<T, bool> visited;
        ll *cnt = new ll[n+1]; //stores the number of nodes on one side of an edge

        for(ll i=1; i<=n; i++){
            cnt[i]=0;
        }
        ll ans=0;
        minval_dfs(1, visited, cnt, ans);
        return ans;
    }
};


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        n = 2*k;
        graph<ll> g;
        for(ll i=0;i<n-1; i++){
            ll a, b, cost;
            cin>>a>>b>>cost;
            g.AddEdge(a, b, cost);
        }
        cout<<g.min_val()<<" "<<g.max_val()<<"\n";
    }
}/*
Logic:
We have to max dist amd min dist travlled while assigning house to 2k people.
we use same logic of HOLI (spoj question)
 
For Max dist we need to find how many max time we can use a particular edge.
For this we cal no of nodes in subtree in both direction for each edge (in left and right dir).
 
So ek edge max kitni bar use hogi uske liye hum uss edge ke right and left dono side mein kitni
nodes hai voh count kar lee, qki we need to chnage every person house so for a particular edge ke liye
uske left ke sabhi nodes edges ke right side ki nodes se house changes karegi.
 
now we tak min of these left,right nodes qki ghar tabhi swap hoga jab people available honge.
so if we have 3 in left and 5 in right toh 3 vale toh right mein ja sakta hai but 5 vale sare nahi sirf 3 
ja sakta hai.
 
For min dist we want ki hum ek edge ko kitni kam bar use kar sakta hai. So we want ki ek subtree mein nodes
apas mein hi ghar assign kar lee rather than to go in opposite direction as we did in to maximise dist
means if for a particualr node it has 4 nodes in its subtree, we assign house to couple in this substree
rahter than assign house in upper nodes of parent node.
 
So if in a substree we have even count of nodes we need not to worry as we can assign them house as they are even
But if we have odd nodes then we have to assign a node a house in upper tree(in other component).
So we use concept of mod 2.
 
so we take min(left, right)%2, this gives min usage of a edge
*/