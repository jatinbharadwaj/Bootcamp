#include<bits/stdc++.h>
#define ll long long 
#define f(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}
using namespace std;

int main()
{
    string s, p="bear";
    cin>>s;
    ll ls=s.length(),i=0,j=0;
    vector<ll> pos;
    while(i<ls){
        //cout<<s[i];
        if(s[i]!=p[j]){    j=0;  } 

        if(s[i]==p[j]){   j++;    }
         
        i++;
        //cout<<j<<' ';
        if(j==4){
            //<<i-2<<' ';
            j=0;
            pos.push_back(i-3);
        } 
    }
    for(int i=0;i<ls-3;i++){

    }
    //cout<<endl;
    //f(pos,pos.size());

    if(pos.empty())
    {
        cout<<0<<endl;
        return 0;
    }
    int sum=0;
    
    for(ll i=0;i<pos.size();i++)
    {
        if(i==0)
            sum+=pos[0]*(ls-pos[0]-2);
        else
            sum += (pos[i]-pos[i-1])*(ls-pos[i]-2);
    }
    cout<<endl<<sum;
    return 0;
}
