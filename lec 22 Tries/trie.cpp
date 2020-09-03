//trie.cpp
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
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007

class node{

	public:
	char data;
	unordered_map<char,node*> h;
	bool isTerminal;
	node(char c){
		data = c;
		isTerminal = false; 
	}

};

class trie{
	node *root;
public:
	trie(){
		root = new node('\0');
	}

	void insert(char *word){
		node *temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			// LETTER exist
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}
			else{
				temp->h[ch]= new node(ch);
				temp = temp->h[ch];

			}
		}
		temp->isTerminal = true;
	}

	bool search(char *word){
		node *temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch  = word[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}
			else{
				return false;
			}
		}
		return temp->isTerminal;
	}

};

int main(){
	
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	trie t;

	char words[][10] = {
		"Hello",
		"Hell",
		"Coding",
		"Code"
	};

	for(int i=0;i<4;i++){
		t.insert(words[i]);
	}
	
	cout<<t.search("Coding");
	cout<<t.search("Hell");
	cout<<t.search("hell");
	


	return 0;
}
