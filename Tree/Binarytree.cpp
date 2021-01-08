 
#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d):data(d),left(NULL),right(NULL){}
};

node* buildTree(){
	int d;
	//cout<<"Enter data";
	cin>>d;

	if(d==-1){
		return NULL;
	}
	else{
		node* n = new node(d);
		n->left = buildTree();
		n->right = buildTree();
		return n;
	}
}

node* buildLevelWise(){

	cout<<"Enter root data";
	int d;
	cin>>d;


	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		cout<<"Enter children of "<<temp->data;
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			temp->left = new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right = new node(c2);
			q.push(temp->right);
		}
	}
	return root;
}

// preorder Root Left Right :Top Down
void print1(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	print1(root->left);
	print1(root->right);

}
// Inorder Left Root Right 
void print2(node*root){
	if(root==NULL){
		return;
	}

	print2(root->left);
	cout<<root->data<<" ";
	print2(root->right);
	
}
// PostOrder left Right Root :Bottom up
void print3(node*root){
	if(root==NULL){
		return;
	}

	print3(root->left);
	print3(root->right);
	cout<<root->data<<" ";
	
}
/*
	void levelOrderPrint(node*root){
	 queue<node*> q;
	 q.push(root);
	 while(!q.empty()){
		node* f = q.front();
		cout<<(f->data)<<" ";
		q.pop();

		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f.right);
		}
	 }
	 return;
	}


*/

// O(N)
void levelOrderPrint(node*root){
	queue<node*> q;


	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();

		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		
		else{
			q.pop();
			cout<<temp->data<<" ";
			
			//Push the children
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
// O(N)
int countNodes(node*root){
	if(root==NULL){
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

//O(N)
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);

	return max(h1,h2) + 1;
}
class Pair{
public:
	int diameter;
	int height;
};

//This works in O(N)
Pair fastDiameter(node*root){
	Pair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height,right.height) + 1;

	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;

	p.diameter = max(op1,max(op2,op3));
	return p;
}

//O(N^2)
int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1,max(op2,op3));
}

int index=0;
int n;

node*makeTree(int *pre,int *in,int s,int e){
	if(s>e){
		return NULL;
	}

	int d = pre[index];
	node* root = new node(d);
	index++;

	int k=-1;
	
	for(int j=s;j<=e;j++){
		if(in[j]==d){
			k = j;
			break;
		}
	}

	root->left = makeTree(pre,in,s,k-1);
	root->right = makeTree(pre,in,k+1,e);
	return root;
}

void mirror(node *root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

HBPair isHeightBalance(node *root){
    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recurisve Case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = max(left.height,right.height) + 1;

    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

node* lca(node*root, int a, int b) {

if (root == NULL) { return NULL;}

if (root->data == a or root->data =b) { return root; }

node *leftans = lca(root->left,a,b);
node *rightans = lca(root->right, a, b);

if (leftans != NULL and rightans != NULL) { return root;}

if (leftans != NULL) {

return leftans;

}

return rightans;

}

// pair{ int branchsum; int maxsum;}

Pair maxSumPath(node* root)
{
			Pair p;

			if (root = NULL) { 

			return P;
			}

			Pair left = maxSumPath(root->left); 
			Pair right = maxSumPath(root->right);

			//construct two values int opl = root->data;
			int op1 = root->data;


			int op2 = left.branchSum + root->data; 
			int op3 = right.branchSum + root->data;
			int op4 = left.branchSum + right.branchSum + root->data;

			int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

			//branch sum of the current root

			p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
			 p.maxSum = max(left.maxsum, max(right.maxSum, current_ans_through_root));
			return p;
}



int main(){
	int pre[] = {1,2,4,5,3,7,6,8};
	int in[] = {4,5,2,1,7,3,8,6};

	//node*root = buildTree();
	n = sizeof(in)/sizeof(int);
	int s= 0;
	int e = n -1;
	node* root  = makeTree(pre,in,s,e);
	// node*root = buildLevelWise();
	//mirror(root);
	cout<<"preorder: ";
	print1(root);
	cout<<endl<<"Inorder: ";

	print2(root);

	cout<<endl<<"PostOrder: ";

	print3(root);
	cout<<endl<<"level Order Print: "<<endl;

	levelOrderPrint(root);

	cout<<"Count is "<<countNodes(root)<<endl;
	cout<<"Height is "<<height(root)<<endl;
	cout<<"Diameter is "<<diameter(root)<<endl;




return 0;
}
