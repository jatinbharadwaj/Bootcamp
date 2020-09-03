#include<bits/stdc++.h>
#define f(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++) {cout<<a[i][j];} }
using namespace std;

bool found=false;
bool find_path(char maze[10][10],char path[10][10],int i,int j,int m,int n)
{
    if(i==m && j==n)
    {   path[m][n]='1';  
        for(i=0;i<m+1;i++){
            for( j=0;j<n+1;j++){
                cout<<path[i][j]<<' ';
            }
            cout<<endl;
        }
    
        found=true;
        
        return true;
    }

    if(i>m || j>n || i<0 || j<0 || path[i][j]=='1') 
        return false;

    if(maze[i][j]=='X')
        return false; 

    path[i][j]='1';
    bool up=find_path(maze,path,i,j-1,m,n);
    bool right=  find_path(maze,path,i,j+1,m,n);
    bool down= find_path(maze,path,i+1,j,m,n);    
    bool left= find_path(maze,path,i-1,j,m,n);
    
    path[i][j]='0';

    if(right || down || up || right)
        return true;
   // cout<<"HERE";
    return false;

}

int main(){
    
    int n,m;
    cin>>m>>n;
    char maze[10][10];
    char path[10][10];
    memset(path,'0',sizeof(path));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }

    bool pathhai=find_path(maze,path,0,0,m-1,n-1);
    if(!found)
        cout<<"NO PATH FOUND";
   
    return 0;   

}
