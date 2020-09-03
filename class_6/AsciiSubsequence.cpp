#include <bits/stdc++.h>

using namespace std;
vector<string> Out;
int Count=0;


void subsequnce(string In,string out,vector<string> s,int i){

    if(In[i]=='\0'){
       // out[j]='\0';
		cout<<out<<' ';
		Count++;
        return;

    }
    subsequnce(In,out,s,i+1);

    for(int k=0;k<2;k++)
    {  // subsequnce(In,out,s,i+1);
        if(k==0)
        { 
            out.push_back(In[i]);
            subsequnce(In,out,s,i+1); 
            out.pop_back();
        }
        
        if(k==1){
              
              out+=s[i];
              subsequnce(In,out,s,i+1); 
            } 
       // subsequnce(In,out,s,i+1); 
    }
}
int main(){
    vector<string> s;
    for(int i=0;i<27;i++)
        s.push_back(to_string(97+i));
   
    string In,out;
    cin>>In;
    subsequnce(In,out,s,0);
	
	cout<<endl<<Count;
}

