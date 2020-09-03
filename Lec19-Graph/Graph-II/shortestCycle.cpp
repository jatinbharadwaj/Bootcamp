//shortestCycle.cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main()
{
	ll x=0,n,t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t!=0)a[++x]=t;
	}
	if(x>128)
	{
		cout<<3;
		return 0;
	}
	int l[150][150],d[150][150];
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			l[i][j]=200;
			if((a[i]&a[j])!=0)
			{
				l[i][j]=1;
			}
			d[i][j]=l[i][j];
		}
	}
	int ans=200;
	for(int k=1;k<=x;k++)
		for(int i=1;i<=x;i++)
			for(int j=1;j<=x;j++)
				if(i!=j&&i!=k&&j!=k)
				{
					ans=min(ans,l[i][j]+d[i][k]+d[k][j]);
					l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
				}	
	if(ans==200)
	cout<<-1;
	else 
	cout<<ans;
}