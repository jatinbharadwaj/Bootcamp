// C++ program to make atleast
// K or N elements of the given array
// equal by dividing by 2

//  CONCEPT: How many Steps it took to reach a particular number x?
//  Suppose a number 80/2= 40 then at index 40 append 1 and then 80/4=20 at index 20 append 2 .... till 1  
//  {Means keep the current number of divisions for each number in an hashmap}
//  Iterate for all the elements of array update map with each division until x>0
//  A list of at every step is formed 
//  Now check whether the size of list formed at every steps is equal to K or not if yes then it implies that at that index all the numbers are equal 
//  Hence sum all the number at that index 
//  If sum minimum then prev is achieved then update it in ans
// 

// For eg {1,1,3,3}
// for 1 & 1 it will take 0 step as 1/2 gives 0 
// 3 & 3 both will contribute 1 at index 1 twice 
// hence, ans 2
//  MAP WILL LOOK LIKE THIS
// 1-> 0 0 1 1 
// 3-> 0 0

//  REFERENCE: https://www.geeksforgeeks.org/count-of-array-elements-to-be-divided-by-2-to-make-at-least-k-elements-equal/

#include <bits/stdc++.h>
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
#define MAXN 100005
#define mod 1000000007
using namespace std;

// Function to return the
// minimum number of divisions
// required
int get_min_opration(int arr[], int N,
	int K)
{
	// vector<vector<int> > vals(200001);
	unordered_map<ll,vector<int>> vals;
	for (int i = 0; i < N; ++i) {
		int x = arr[i];

		int cur = 0;
		while (x > 0) {
			
			vals[x].push_back(cur);
			x /= 2;
			++cur;
		}
	}

	int ans = INT_MAX;

	for(auto i:vals){

		if(i.si.size()<N){
			continue;
		}
		int sum = 0;
		for(auto j:i.si){
			sum+=j;
		}
		ans = min(ans,sum);

	}

	return ans;
}
// Driver Program
int main()
{
	// int N = 4, K = 4;

	// int arr[] = { 1,3,3,1};
	// cout << get_min_opration(arr, N, K);

	// float A = 3, B = 17;
	// float d = ceil(float(B/A));
	// float w = ceil(float(d/5));
	int a=3,b=17;
	int d = b/a + (b%a>0?1:0);
	int w = d/5 + (d%5>0?1:0); 
	cout<<d<<"here "<<w;


	return 0;
}
