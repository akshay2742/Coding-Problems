#include<iostream>
using namespace std;
/* Reverse a linked list using Recursion and With recursion */


struct node{
int data;
struct node*next;
};

struct node*newNode(int data){
struct node*temp = new struct node;
temp->data = data;
temp->next = NULL;
return temp;
}

void pushFront(struct node**head,int data){
struct node* first = newNode(data);

if(*head==NULL){
 *head = first;
}
else{
    first->next = (*head);
    *head = first;
    }
}

void print(struct node*head){
struct node*current = head;
while(current!=NULL){
 cout<<current->data<<"->";
 current=current->next;
    }
}

//-------------------------------------------------------Iterative Reverse
void itrReverse(struct node**head){
struct node*next ;
struct node*current = *head;
struct node* prev = NULL;

    while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev = current;
    current=next;
    }
    //Previous will be at last node , current will be at NULL
*head = prev;
}
//-------------------------------------------------Recursive Reverse
void recursiveReverse(struct node**head){
struct node*first = *head;
struct node*rest;
rest=first->next;
if(rest==NULL)
    return ;
recursiveReverse(&rest);
first->next->next = first;
first->next = NULL;

*head = rest;
}

int main(){
struct node*head1=NULL;
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,3);
pushFront(&head1,4);
struct node*head2=NULL;
pushFront(&head2,5);
pushFront(&head2,6);
pushFront(&head2,8);
print(head1);
itrReverse(&head1);
cout<<endl<<"REVERSE :";
print(head1);
recursiveReverse(&head1);
cout<<endl<<" Recursive REVERSE :";
print(head1);
return 0;
}



//cpp
//Program to create Single linked list and reverse its elements
#include<bits/stdc++.h>
using namespace std;

template <class t>
class IntSLLNode
{
public:
t info;
IntSLLNode*next;

IntSLLNode()
{
info = 0;
next = NULL;
}

IntSLLNode(t element)
{
info = element;
next = NULL;
}

};

template <class t>
class IntSLLList
{
public:
IntSLLNode<t> *head;
IntSLLNode<t> *tail;


IntSLLList()
{
head = NULL; // 0
tail = NULL; // 0
}

void insertatHead(t element)
{
IntSLLNode<t> * N = new IntSLLNode<t>(element);

if(head==NULL)
{
head = N;
tail = N;
}

else
{
N->next = head;
head = N;
}

}

void insertatTail(t element)
{
IntSLLNode<t>* N = new IntSLLNode<t>(element);

if(head==NULL)
{
head = N;
tail = N;
}

else
{

tail->next=N;
tail=N;

}
}

void traverse()
{

IntSLLNode<t> *temp;
temp =  head;
while(temp != NULL)
{
cout<<temp -> info <<"--> ";
temp = temp->next;
}
}


bool search(t element)
{
IntSLLNode<t> *temp;
temp = head;

while(temp!=NULL)
{
if(temp->info == element)
return true;
temp = temp->next;
}
return false;

}


void reverse()
{
IntSLLNode <t>*temp1 = head;
IntSLLNode <t>*temp2 = NULL;
IntSLLNode <t>*next = NULL;

while(temp1!=NULL)
{
next = temp1->next;
temp1->next = temp2;
temp2 = temp1;
temp1 = next;
}

head = temp2;
traverse();

}

void menu2(t element)
{
int option;
do
{
cout<<"\n\n****MENU****\n";
cout<<"Press 1. Inserting an element At Beginning\n";
cout<<"Press 2. Inserting an element At End\n";
cout<<"Press 3. For Traversing/Display of elements\n";
cout<<"Press 4. For Search\n";
cout<<"Press 5. For Reverse\n";
cout<<"Press 6. For Exit\n";

cout<<"Enter choice: ";
cin>>option;

switch(option)
{
case 1: cout<<"Enter an Element: ";
cin>>element;
insertatHead(element);
break;

case 2: cout<<"Enter an Element: ";
cin>>element;
insertatTail(element);
break;

case 3: traverse();
break;

case 4: cout<<"Element you want to find: ";
cin>>element;
if(search(element)==1)
{
cout<<"Element is Present in List\n";
}
else
cout<<"Element is not present in the List\n";
break;

case 5: cout<<"\nBefore Reverse: ";
traverse();
cout<<"\nAfter Reverse: ";
reverse();
break;
         
case 6: cout<<"\n\nExiting\n";
exit(0);

default:cout<<"\nInvalid input";
      break;

}

}while(option!=6);

}

};

void menu1()
{
cout<<"\n\n\tTYPES\n";
cout<<"1. Int \n";
cout<<"2. Char \n";
cout<<"3. Float\n";
cout<<"4. Long \n";
cout<<"Enter Choice: ";

}


int main()
{
int opt,me1;
char choice;

menu1();
cin>>me1;
cout<<endl;

if(me1 == 1)
{
int element;
IntSLLList < int > SL;
SL.menu2(element);
}

else if( me1 == 2)
{
char element;
IntSLLList <char> SL;
SL.menu2(element);
}

else if( me1 == 3)
{
float element;
IntSLLList < float > SL;
SL.menu2(element);
}

else if(me1 == 4)
{
long element;
IntSLLList <long> SL;
SL.menu2(element);
}

else
{
cout<<"\nInvalid input";
}


return 0;
}

