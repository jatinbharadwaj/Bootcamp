#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;s1[i];i++){
        if(isupper(s1[i]))
        {
            s1[i]+=32;
        }   
        if(isupper(s2[i])){
            s2[i]+=32;
        }     
    }
    if(s1>s2)
    {
        cout<<1;

    }
    else if(s1==s2){
        cout<<0;
    }
    else 
        cout<<-1;
    return 0;
}

