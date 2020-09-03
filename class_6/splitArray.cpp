#include <bits/stdc++.h>
using namespace std;
int Count=0;
void splitArray(int *a,int target,int sum,vector<int>v,vector<int>iv,int i,int n)
{
    if(target==sum && i==n){
        for(auto x:v)
            cout<<x<<" ";
        cout<<"and ";
        for(auto x:iv)
            cout<<x<<" ";
        cout<<endl;    
        Count++;    
        return;    
    }

    if(i==n || sum>target)
        return;

    v.push_back(a[i]);
    if(sum<target)
    splitArray(a,target,sum+a[i],v,iv,i+1,n);
    v.pop_back();
    iv.push_back(a[i]); 
    splitArray(a,target,sum,v,iv,i+1,n);
    iv.pop_back();  
}


int main() {
    int n;
    cin>>n;
    int a[100];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<int> b,c;
    if(sum%2!=0)
        cout<<0;
    else    
        splitArray(a,sum/2,0,b,c,0,n);
    cout<<Count;    
}

