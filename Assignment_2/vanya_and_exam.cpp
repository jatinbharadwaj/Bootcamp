#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
bool sorting(const pair<ll,ll>&a, const pair<ll,ll>&b)
{
    return(a.second<b.second);
}
void print(vector<pair<ll,ll>>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }
}
 
int main() {
    ll n,r,avg;
    cin>>n>>r>>avg;
 
    vector<pair<ll,ll>> v;
    ll a,b,sum=0;
 
    for(int i=0;i<n;i++){
        cin>>a>>b;
        sum=sum+a;
        
        a=r-a;
        v.push_back(make_pair(a,b));
    }
    
 
    ll req= n*avg - sum;
    //cout<<req;
    ll es=0;
 
    if(req<=0){
        cout<<0;
        return 0;
    }
    //print(v);cout<<endl;
 
    sort(v.begin(),v.end(),sorting);    
    //print(v);
    //cout<<req<<endl<<v[0].first<<endl;
    for(int i=0;i<n && req>0;i++){
    
        //cout<<'t'<<tmp<<' ';
        if(req>v[i].first)
        { 
            req-=v[i].first;
            es+=v[i].first*v[i].second;
            //cout<<es;
        }
        else if(req==v[i].first){  es+=v[i].first*v[i].second;  req=0;  }
        else{
              
              es+=(req)*v[i].second;
              req=0;  
        }
        //cout<<es<<" r->"<<req<<' ';
    }
    cout<<es;
    return 0;
 
}

