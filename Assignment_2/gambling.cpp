
using namespace std;
#define ll long long
int main() {
    
    ll n;
    cin>>n;
    ll a[n],b[n];
    bool flag=false;
 
    for(int i=0;i<n;i++) {cin>>a[i];}
    for(int i=0;i<n;i++) {cin>>b[i];}
 
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
 
    ll sum=0,j=0,k=0,i=0;
 
    while(j<n || k<n)
    {
        //cout<<a[j]<<" "<<b[k]<<endl;
        if(i%2==0)
        {
            //(cB>=n || a[cA]>=b[cB])
            if( j<n && (k>=n || a[j]>=b[k])){
                sum+=a[j];
                ++j;    }
                
            else{   ++k;    }
        }
        
        else if(i%2==1)
        {    
            //cB<n && (cA>=n || a[cA]<=b[cB])
            if( k<n &&(j>=n || a[j]<=b[k])){
                sum-=b[k];   
                ++k;    }
            
            else{
                
                ++j;    }
        }
        ++i;
        
    }
   // cout<<sum<<' '<<k<<' '<<j<<' '<<i;
  /*  if(i%2==0)
        flag=true;
    else
        flag=false;
        
    
    while(j>=n && k<n)
    {
        if(k<n-1 && flag) sum-=a[k+1];
        
        else if(!flag) sum-=a[k];
        k=k+2;
    }
    
    while(k>=n && j<n){
        if(flag){  sum+=a[j];    }
        else if(!flag && j<n-1){  sum+=a[j+1];  }
        j=j+2;
    }*/
 
    cout<<sum;
    return 0;
}

