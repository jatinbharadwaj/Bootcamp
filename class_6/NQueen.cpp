#include<bits/stdc++.h>
using namespace std;

int ans=0;
bitset<30> col,ld,rd;
vector<int> v;

void NQueen(int i,int n){

    if(i==n){
        ans++;
        for(int l=0;l<v.size();l++){
            cout<<"{"<<l+1<<"-"<<v[l]<<"}"<<" ";
        }
        cout<<" ";
        return; 
    }

    for(int j=0;j<n;j++){

        if(!col[j] && !rd[i+j] && !ld[j-i+n-1] )
        {
            col[j]=rd[i+j]=ld[j-i+n-1]=1;
            v.push_back(j+1);
            NQueen(i+1,n);
            v.pop_back();
            col[j]=rd[i+j]=ld[j-i+n-1]=0;
        }
        
    }


}

int main(){
    int n;
    cin>>n;
    NQueen(0,n);
    cout<<endl<<ans;
    return 0;
}
