#include <bits/stdc++.h>
using namespace std;
string solve(string s)
{
    int n=s.size();
    bool c[26];
    memset(c,false,sizeof(c));
    string str;
    
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        if(s[i]==s[j] && c[s[i]-97]!=true)
        { 
            c[s[i]-97]=false;
            i+=1;
        }
        else 
            {   c[s[i]-97]=true;    }
    }
   
    for(int i=0;i<26;i++)
    {   
        if(c[i]==true)
        {
            
            str+=i+97;
        }  
    }
    return str;
}

int main(){
    int n;
    cin>>n;
  
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
    
}
