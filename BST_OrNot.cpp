//============================================================================
// Name        : BST_OrNot.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *left=NULL;
	struct node *right=NULL;
};

struct node *newNode(int data)
{
	struct node *temp=new node();
	temp->data=data;

	return temp;
}

void insert(struct node *&root,int data)
{
	if(!root)
	{
		root=newNode(data);
		return;
	}

	if(data<root->data)
		insert(root->left,data);
	else if(data>root->data)
		insert(root->right,data);

	return;

}

void display(struct node *root)
{
	if(!root)
		return;


	// in-order traversal
	display(root->left);
	cout<<root->data<<endl;
	display(root->right);

}

bool BstCheck(struct node *root,struct node *min,struct node *max)
{
	if(!root)
		return true;
	if(min && root->data<=min->data || max && root->data>=max->data)
		return false;

	return (BstCheck(root->left,min,root) && BstCheck(root->right,root,max));
}


bool BST(struct node *root)
{
	return BstCheck(root,NULL,NULL);
}

int main() {
	struct node *root=NULL;

		insert(root, 50);
	    insert(root, 30);
	    insert(root, 20);
	    insert(root, 40);
	    insert(root, 70);
	    insert(root, 60);
	    insert(root, 80);

	    display(root);
	    cout<<endl;
	    bool bst=BST(root);
	    if(bst)
	    	cout<<"Yes it is a BST";
	    else
	    	cout<<"No it is not a BST";
}
