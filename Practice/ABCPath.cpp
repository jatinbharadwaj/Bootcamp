// ABCPath.cpp
// https://www.spoj.com/problems/ABCPATH/
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

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

int m, n;
int sol_mat[51][51];



int dfs(int row, int col, char letter, vector<string> v) {

	// already visited
	if (sol_mat[row][col] != -1) return sol_mat[row][col];

	int curr_pos_sol = 1;

	for (int i = 0; i < 8; ++i) {
		if (row + dx[i] < 0 || row + dx[i] >= m || col + dy[i] < 0 || col + dy [i]>= n) continue;


		if (v[row + dx[i]][col + dy[i]] == letter) {
			curr_pos_sol =  max(curr_pos_sol, 1 + dfs(row + dx[i], col + dy[i], letter + 1, v));
		}


	}
	// update into solution table for memoziation
	sol_mat[row][col] = curr_pos_sol;
	return curr_pos_sol;
}

int main() {

	fastIO

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int _case = 1;
	while (cin >> m >> n) {

		if(!m && !n) return 0;
		vector<string> v(m);
		int ans = 0;

		memset(sol_mat,-1,sizeof sol_mat);
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		// PNF(v,m,n)

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != 'A') continue;

				ans = max(ans, dfs(i, j, 'A' + 1,v));

			}
		}

		cout<<"Case "<<_case<<": "<<ans<<endl;
		_case++;

	}



	return 0;
}

