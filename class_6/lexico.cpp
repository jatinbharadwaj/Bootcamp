#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

void lexico(int lex,int n)
{
	//base condition
	if(lex>n) return;
	v.push_back(lex);
	lexico(lex*10,n);
	if(lex%10!=9) lexico(lex+1,n);
}

int main() 
{
	int n;
	cin>>n;
	lexico(1,n);
	for(auto x:v)
		cout<<x<<" ";
	return 0;
}
