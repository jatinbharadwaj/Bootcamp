//travel.cpp
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

class Graph {
   private:
  bool** adjMatrix;
  int numVertices;


   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
  }



  // Print the martix
  void toString() {
     for (int i = 0; i < numVertices; i++) {
    //   cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
      {
       	if( adjMatrix[i][j])
       	 cout <<'Y';
        else
        	cout<<'N';
      }
      cout << "\n";
    }
  }

void DFS(int start, vector<bool>& visited,int parent) 
{   
  	adjMatrix[parent][start] = 1;
  
    visited[start] = true; 
     
    for (int i = 0; i < numVertices; i++) { 
        if (adjMatrix[start][i] == 1 && (!visited[i])) { 
            DFS(i, visited,parent); 
        } 
    } 
} 
  ~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};



int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	int cse=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string incoming,outgoing;
		cin>>incoming>>outgoing;
		
		Graph g(n);
		for(int i=0;i<n-1;i++)
		{
			g.addEdge(i,i);
			if(incoming[i]=='Y' && outgoing[i+1]=='Y')
				g.addEdge(i+1,i);	
			if(incoming[i+1]=='Y' && outgoing[i]=='Y')
				g.addEdge(i,i+1);
		}
		g.addEdge(n-1,n-1);
		for(int i=0;i<n;i++){
		
			vector<bool> visited(n, false); 
			g.DFS(i,visited,i);
			
		}	
		
		cout<<"Case #"<<cse<<":"<<'\n';cse++;
		
		 g.toString();


	}

	return 0;
}
