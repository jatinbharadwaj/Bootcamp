
#include<iostream>
using namespace std;
#define MAX 100005
 
int arr[MAX], t[MAX], m,n;
 
bool canClear(int mid){
    int exam = m;
    int total_req_time=0;
    bool flag[MAX]={0};
    
    for(int i=mid; i>=1; i--){
        if(arr[i] && !flag[arr[i]]){
            total_req_time += t[arr[i]];
            exam--;
            flag[arr[i]] = true;
        }
        else{
            if(total_req_time>0) total_req_time--;
        }
    }
    
    if(total_req_time>0 || exam>0) return false;
    return true;
}
 
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int j=1; j<=m; j++){
        cin>>t[j];
    }
    
    int ans=0, s=0, e=n;
    while(s<=e){
        int mid = (s+e)/2;
        if(canClear(mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    if(!ans)cout<<"-1\n";
    else cout<<ans<<endl;
}
