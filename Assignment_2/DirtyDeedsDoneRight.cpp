#include <bits/stdc++.h>
#define ll long long
#define f(a,b) for(int i=0;i<n;i++){ cout<<a[i]<<' ';   }
using namespace std;


int main() {
   
    ll n;
    cin>>n;
    vector<pair<ll,ll>> A,B;
    
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b)
        {
            A.push_back(make_pair(b,i+1));
        }
        else
            B.push_back(make_pair(-b,i+1));   
    }

    if(A.size()>B.size())
        sort(A.begin(),A.end());
    else
        sort(B.begin(),B.end());

    if(A.size()>B.size()) {
        cout<<A.size()<<endl;
        for(int i=0;i<A.size();i++){
            cout<<A[i].second<<' ';
        }
    }   
    else{
         
        cout<<B.size()<<endl;
        for(int i=0;i<B.size();i++){
            cout<<B[i].second<<' ';
        }
    }

    return 0;
}

