// WilliamTheorem.cpp

#include <iostream>
using namespace std;

//Fast Modulo Exponentation
#define ll long long 
ll fastModExp(ll a,ll b,ll m){

	ll res = 1;
	while(b>0){
		if(b&1){
			res = (res*a)%m;
		}
		a = (a*a)%m;
		b = b>>1;
	}
	return res;
}

ll solve(ll n,ll p){
	ll ans = -1;
	for(ll i=(n+1);i<=(p-1);i++){
		ll temp = fastModExp(i,p-2,p);
		ans = (ans*temp)%p;
	}
	return (ans+p);
}

int main() {
	ll t,n,p;
	cin>>t;

	while(t--){
		cin>>n>>p;
		if(n>=p){
			cout<<"0"<<endl;
		}
		else{
			cout<<solve(n,p)<<endl;
		}

	}

	return 0;
}