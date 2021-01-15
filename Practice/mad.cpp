// // mad.cpp
// Mad monkey is on tower 0, there are total n towers (here for example n = 10), 
//  Mad monkey want to travel from tower 0 to tower n and initial jump power of monkey is 1 mtr,
  
//    0,1,2,3,4,5,6,7,8,9
   
//    Distances between towers=
//    0-1 = 10 mtr 
//    1-2 = 50 mtr
//    0-2 = 70 mtr
//    2-3 = 30 mtr
//    3-4 = 20 mtr
//    2-4 = 5 mtr
//    1-4 = 35 mtr
//    4-5 = 500 mtr
//    5-9 = 400 mtr
//    5-6=20 mtr
//    6-7 = 50 mtr
//    7-8=700 mtr
//    8-9 = 30 mtr



// tree
// 10  20     5      
//  0->1   2->3
// }
   
// 0 -> (1,10 )-> (2, 70)
// 1 -> (2,50) {visited} -> (4,500)
// 2 -> (3,30) ->(4,5)
// 3 -> (4,20)
// 4 -> (5,500)
// 5 -> (9,400) -> (6,20) 
// 6 -> (7,50)
// 7 -> (8,700)
// 8 -> (9,300)



//    Conditions:
//    Monkey won't come back from a higher to
// Conditions:
//    Monkey won't come back from a higher tower to lower tower like won't come back from 7th to 6th tower
//    initial power = 1
//    n=10 (0 to 9)
//    Findout minimum distance monkey will be travelling.
   
//    Expected output : 
//    min distance : 945 mtrs
   
   
//    Ans such that : 
//    What is minumum distance Monkey will travel ?
//    How many times monkey will fall ?
// Rakesh Kejriwal9:33 PM
// 1,2,4,8
// 16


// queue<>

// for(0->9){ v
//    for(childern nodes of ){
//        v
//    }
// }

// 0->(1,10)->(2,50)->()
// 1->(2,50)
// 3->
// 4->
// 5->
// 6->
// unordered<int,list<pair<int,int>>>
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

class Graph{
   int v;

   list<pair<int,int>> adj;
   unrdered<int,bool> visited;

   

public:
   Graph(int v){
      this->v = v;
      adj = new list<pair<int,int>>[v];
   }

   void push(int u, int v,int w){
         adj[u].pb(mp(v,w));
         adj[v].pb(mp(u,w));
   }

   void bfs(int src)

      for(auto children:adj){
         for(auto child:children){
            bfshelper()
         }
      }
      

   }

   void bfshelper(){}

}

int main(){
   
   fastIO

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif


   int n;
   cin>>n;
   Graph g(n);

   while(n--){
      int u,v,w;
      cin>>u>>v>>w;

      g.push(u,v,w);
   }

   g.dj(0);



   return 0;
}
