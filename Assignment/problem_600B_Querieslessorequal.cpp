#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long;
int solve(vector<ll> a,ll b,int m){

    int s=0,e=m-1;
    if(a[0]>b)
        return 0;
    if(a[e]<=b)   
        return m;

    while(s<e){

        int m=(s+e)/2;
        int um=m+1,lm=m-1;
        
        if( a[m]>b && a[lm]<b)
            return m;

        if( a[m]<=b && a[um]>b )
            return m+1; 
        
        if(a[m]>b)
             e=m;
        else if(a[m]<=b)
             s=m+1;


    }
return 0;
   
}


int main()
 {
    int m,n;
    cin>>m>>n;
    vector<ll> a,b; 

    for(int i=0;i<m;i++) {   ll tmp=0; cin>>tmp; a.push_back(tmp);    } 
    for(int i=0;i<n;i++) {   ll tmp=0; cin>>tmp; b.push_back(tmp);    }

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){   cout<<solve(a,b[i],m)<<' ';    }
    //solve(a,b);

    return 0;
}

