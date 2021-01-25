// PrimeCalculations.cpp

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define ppi pair<ll,ll>
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<i<<":"<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 1000001
#define mod 1000000007

int *prime;
ll *factor;
void primeprime() {
	prime = new int[1000005];
	factor = new ll[1000005];

	//N
	for (int i = 0; i < AS; i++) {
		prime[i] = 1;
		factor[i] = 0;
	}

	// root N
	prime[0] = prime[1] = 0;
	for (ll i = 2; i * i < AS; i++) {
		if (prime[i])
		{
			for (ll j = 2 * i; j < AS; j += i) {
				prime[j] = 0;
			}
		}
	}

	// root N
	for (int i = 2; i * i < AS; i++)
	{
		if (prime[i]) {
			factor[i] = 1;
			for (ll j = 2 * i; j < AS; j += i) {
				factor[j]++;
			}
		}

	}
}


int main() {


	fastIO

	primeprime();


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	int a[n];

	F(a, n);


	// P(prime, 15)
	// P(factor, 25)

	deque<int> Qi(k);



	int sum = 0,i=0;

	for (i = 0; i < k; i++) {
		while ((!Qi.empty()) && factor[a[i]] > factor[a[Qi.back()]])
             // Remove from rear
			Qi.pop_back();

        // Add new element at rear of queue
		Qi.push_back(i);
		
	}

	for (; i < n; ++i) 
	{

        // The element at the front of 
        // the queue is the largest element of
        // previous window, so print it
		cout << a[Qi.front()] << " ";
		sum= (sum%mod+a[Qi.front()]%mod)%mod;
        // Remove the elements which 
        // are out of this window
		while ((!Qi.empty()) && Qi.front() <= i - k)

            // Remove from front of queue
			Qi.pop_front(); 

        // Remove all elements 
        // smaller than the currently
        // being added element (remove 
        // useless elements)
		while ((!Qi.empty()) && factor[a[i]] > factor[a[Qi.back()]])
			Qi.pop_back();

        // Add current element at the rear of Qi
		Qi.push_back(i);
	}

    // Print the maximum element 
    // of last window
	cout << a[Qi.front()];
	sum= (sum%mod+a[Qi.front()]%mod)%mod;
	cout<<endl<<sum;

	return 0;
}

