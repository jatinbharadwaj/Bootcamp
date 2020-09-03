#include <iostream>
using namespace std;


int main()
{
    string s,ans;
    cin>>s;

    int count=0;

    for(int i=0;s[i];i++){
        if(s[i]=='1')
         count++;
        else
            ans+=s[i];
    }
    

    int i=0;

    while(s[i] && ans[i]=='0'){ i++; }

    ans.insert(i,count,'1');
    cout<<ans;

}

