#include<bits/stdc++.h>
using namespace std;
int Count=0;
void subsetsum(int *a,vector<int> b,int target,int n,int sum,int i){


    //base case
    if(target==sum){
        for(int k=0;k<b.size();k++)
        cout<<b[k]<<" ";
        cout<<" ";
        Count++;
        return;
    }

    if(i>=n || sum>target)
        return;
    b.push_back(a[i]);
    subsetsum(a,b,target,n,sum+a[i],i+1);
    b.pop_back();
    subsetsum(a,b,target,n,sum,i+1);
    //b.push_back(a[i]);
    //subsetsum(a,b,target,n,sum+a[i],i+1);
}
void printsubset(int *a,int target,int n){
    vector<int> ans;
    subsetsum(a,ans,target,n,0,0);

}


int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int target;
    cin>>target;
    printsubset(a,target,n);
    if(Count!=0)
    cout<<endl<<Count;
    else
        cout<<0;

}
