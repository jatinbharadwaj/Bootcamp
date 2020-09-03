#include<bits/stdc++.h>

using namespace std;

#define mp make_pair

typedef pair<long long, pair<int, int> > edge;

const int N = 200043;
//similar to power grid from lecture 21

int p[N];
long long a[N];

int get_leader(int x)
{
	return (x == p[x] ? x : (p[x] = get_leader(p[x])));
}

bool uninon_set(int x, int y)
{
	x = get_leader(x);
	y = get_leader(y);
	if(x == y) return false;
	p[x] = y;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
		cin>>a[i];

	vector<edge> es(m);

	for(int i = 0; i < m; i++)
	{
		cin>>es[i].second.first>>es[i].second.second>>es[i].first; 
		es[i].second.first--;
		es[i].second.second--;
	}

	int z = min_element(a, a + n) - a;


	for(int i = 0; i < n; i++)
		if(i != z)
			es.push_back(mp(a[i] + a[z], mp(i, z)));
	
	sort(es.begin(), es.end());

	long long ans = 0;
	for(int i = 0; i < n; i++)
		p[i] = i;
	for(auto e : es)
		if(uninon_set(e.second.first, e.second.second))
			ans += e.first;
	printf("%lld\n", ans);
	return 0;		
}