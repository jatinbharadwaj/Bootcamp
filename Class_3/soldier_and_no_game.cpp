#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 5000005

bool isPrime[MAX];
ll total_factors[MAX]={0}, divisors[MAX]={0}, ct_factors[MAX]={0};

void CalculateAllPrime(){
    memset(isPrime, true, sizeof(isPrime));
    for(ll i=2; i*i<MAX; i++){
        if(isPrime[i]){
            for(ll j=2*i; j<MAX; j+=i){
                isPrime[j]=false;
                divisors[j]=i;
            }
        }
    }
}

void CalculateAllFactors(){
    for(ll i=2; i<MAX; i++){
        if(isPrime[i]){
            total_factors[i]=1;
        }
        else{
            // ll t = i/divisors[i];
            total_factors[i] = total_factors[i/divisors[i]] + 1;
        }
        ct_factors[i] = ct_factors[i]+ct_factors[i-1]+total_factors[i];
        cout<<divisors[i]<<' ';
    }
}

int main(){
    fstIO;
    CalculateAllPrime();
    CalculateAllFactors();
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<ct_factors[a]-ct_factors[b]<<"\n";
    }
    return 0;
}
