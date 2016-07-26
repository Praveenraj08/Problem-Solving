//============================================================================
// Name        : Stringto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct node
{
	char data;
	struct node *next=NULL;
};

struct node *newNode(char ch)
{
	struct node *temp=new node();
	temp->data=ch;

	return temp;
}

struct node *convert(struct node *head,string s)
{
	if(s.length()<=0)
		return NULL;

	head=newNode(s[0]);

	head->next=convert(head,s.substr(1));

	return head;

}

void toLL(string s)
{
	struct node *head=newNode(-1);

	head->next=convert(head,s);
	head=head->next;
	while(head)
	{
		cout<<head->data;
		head=head->next;
	}
}


int main() {

	string s="Hello";

	toLL(s);

}
