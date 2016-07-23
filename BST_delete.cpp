//============================================================================
// Name        : BST_delete.cpp
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


struct node *MinValue(struct node *root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}

	return root;
}

struct node *del(struct node *root,int data)
{
	if(!root)
		return NULL;

	if(data<root->data)
		root->left=del(root->left,data);
	else if(data>root->data)
		root->right=del(root->right,data);

	else
	{
		if(root->left==NULL)
		{
			struct node *temp=root->right;
			delete root;
			return temp;

		}
		else if(root->right==NULL)
		{
			struct node *temp=root->left;
			delete root;
			return temp;
		}

		struct node *temp=MinValue(root->right); //Minimum value of right sub-tree.
		root->data=temp->data;

		root->right=del(root->right,temp->data);


	}
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
	    del(root,50);
	    cout<<endl;
	    display(root);
}
