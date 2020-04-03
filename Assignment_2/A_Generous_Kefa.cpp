#include <bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    string s;
    if(m<=n)
    {
        cout<<"YES";
        return 0;
     }
    cin>>s;
    int c[26];
    memset(c,0,sizeof(c));
    for(int i=0;i<m;i++)
    {   int tmp=s[i]-'a';
        ++c[tmp];
        if(c[tmp]>n)
        {
            cout<<"NO";    return 0;
        }
    }
    cout<<"YES";
}
