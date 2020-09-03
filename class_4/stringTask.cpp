#include <bits/stdc++.h>
using namespace std;
int main() {
   string str,s;
   cin>>str;
   for(int i=0;str[i];i++){
       if(isupper(str[i]))
        str[i]+=32;
       if(!(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='y' )) 
        s=s + "." + str[i];
   }
   cout<<s;
   return 0;
}

