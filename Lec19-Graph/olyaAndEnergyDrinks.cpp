#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cassert>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 1005
#define inf 99999999

/*
Logic: Used Dijikstra
Find the shortest dist from source row, source col to dest row, dest col
*/

int n,m,k,sr,sc,dr,dc;
string arr[MAX];
ll dist[MAX][MAX];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isValid(int i, int j){
    if(i<0||j<0||i>=n||j>=m||arr[i][j]=='#')return false;
    return true;
}

void solve(){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j]=INT_MAX;
        }
    }

    dist[sr][sc] = 0;

    queue<pair<int, int> >q;
    q.push({sr,sc});


    while(!q.empty()){
        pair<int, int>front = q.front();
        q.pop();

        int old_x =front.first;
        int old_y = front.second;
        ll parent_dist = dist[old_x][old_y];

        for(int i=0; i<4; i++){
            for(int j=1; j<=k; j++){
                int new_x = old_x+(dx[i]*j);
                int new_y = old_y+(dy[i]*j);

                if(!isValid(new_x, new_y))break;// if we get a invalid cell
                //we break as it is impossible to get a new valid cell in the same direction.

                assert(new_x<n && new_y<m);
            
                if(dist[new_x][new_y]>parent_dist+1){
                    
                    dist[new_x][new_y] = parent_dist+1;
                    q.push({new_x, new_y});

                    if(new_x==dr && new_y==dc){
                        cout<<dist[new_x][new_y]<<endl;
                        return;
                    }
                }
            }
        }
    }

    if(dist[dr][dc] == INT_MAX){
        cout<<"-1\n";
    }
    else cout<<dist[dr][dc]<<endl;
}

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cin>>sr>>sc>>dr>>dc;
    sr--; sc--;
    dr--; dc--;
    
    solve();
    return 0;
}