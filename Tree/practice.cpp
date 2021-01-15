#include<iostream>
#include<queue>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

class node{

	
public:
	int val;
	node *left=NULL;
	node *right=NULL;

	node(int d):val(d),left(NULL),right(NULL){}

};

node* makeTree(){
	int d;	
	cin>>d;

	if(d==-1) return NULL;

	else{
		node* n = new node(d);
		n->left = makeTree();
		n->right = makeTree();
		return n;
	}

}

void preorder(node* root){
	if(root==NULL){
		return ;
	}

	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
void Inorder(node* root){
	if(root==NULL){
		return ;
	}

	Inorder(root->left);
	cout<<root->val<<" ";
	Inorder(root->right);
}

void postorder(node *root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";

}

int main(){
		
	fastIO

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int pre[] = {1,2,4,5,3,7,6,8};
	int in[] = {4,5,2,1,7,3,8,6};

	node* root = makeTree();

	preorder(root);
	cout<<endl;
	Inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;


	return 0;

}

