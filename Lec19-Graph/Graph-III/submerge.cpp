//submerge.cpp

/*
https://codeforces.com/blog/entry/71146
THEORY:

If there is NO way to get to a node 𝑉 with strictly
smaller discovery time than the discovery time of 𝑈 
following the DFS traversal, then 𝑈 is an articulation point. 
(it has to be strictly because if it is equal it means that 𝑈 
is the root of a cycle in the DFS traversal which means that 𝑈 
is still an articulation point).

If 𝑈 is the root of the DFS tree and it has at least 2 children 
subgraphs disconnected from each other, then 𝑈 is an articulation point.
*/

/*
CONDITIONS:

If all paths from 𝐴 to 𝑉 require 𝑈 to be in the graph.

If 𝑈 is the root of the DFS traversal with at least 2 
children subgraphs disconnected from each other.

*/
#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1e4+4;
vector<int>arr[maxn];
bool visit[maxn];
int parent[maxn];
int low[maxn];
set<int> ap;
int disc[maxn];
 
void ArticulationPoint(int u){
	static int time = 0;
	int child = 0;
	visit[u]  = 1;
	disc[u] = low[u] = ++time; 	//discovery time

	for(int i = 0; i<arr[u].size();i++){

		int v = arr[u][i];
		
		if(!visit[v]){
			child++;
			parent[v] = u;
			ArticulationPoint(v);
			// low[v] might be an ancestor of u
			low[u] = min(low[u],low[v]);

			if(parent[u] == -1 && child>1) ap.insert(u);		 // condition #1 IF ROOT AND HAVE MORE THAN ONE DISCONNECTED CHILD
			if(parent[u] != -1 && low[v]>=disc[u]) ap.insert(u); // THEORY #1
		}
		else if (v != parent[u])
		{
			low[u] = min(low[u],disc[v]); 
			// finds the ancestor with the least discovery time
		}
	}

	
}
int main(){
	//freopen("t.txt","r",stdin);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m,u,v;
	while(cin>>n>>m){
		
		if(!n && !m) break;
		
		memset(parent,-1,sizeof parent);
		memset(visit,0,sizeof visit);

		for(int i=0;i<n+1;i++)arr[i].clear();
		
		//arr.clear();

		for(int i=0;i<m;i++){
			cin>>u>>v;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(int i=0;i<n;i++){
			if(!visit[i]){
				ArticulationPoint(i);
			}
		}
		cout<<ap.size()<<endl;
		ap.clear();
	}
}
