#include <iostream>
using namespace std;
int solve(int a[],int n,int t)
{
    int s=0,e=0,ml=0,cs=0,l=0;
    for(int i=0;i<n;i++){
   
        cs=cs+a[i];
        
        if(cs>t)
        {  
            
            cs=cs-a[s];
            s++;
    
        }
        l=i-s+1;
        if(ml<l)
            ml=l; 
    }
    return ml;
}
int main() 
{
   int n,t;
   cin>>n>>t;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   } 
   cout<<solve(a,n,t);
}

