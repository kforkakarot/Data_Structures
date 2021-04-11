#include<iostream>
#include <stdio.h>
using namespace std;

struct Node
{   Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;


struct Queue
{
    Node *q;
    Queue *next;
}*front=NULL,*rear=NULL;

void enqueue(Node *m)
{  
  Queue *t =new Queue();
  t->q=m;
  t->next=NULL;
    if(rear==NULL)
    {
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}

Node * dequeue()
{  Node *t=NULL;
   
    if(front==NULL){
        cout<<"Queue is empty";
        return t;
    }
    
    else{
        Queue *k=front;
        front=front->next;
        t=k->q;
        delete(k);
        return t;
    }
}

int isEmpty()
{
    if(front==rear)
     return 1;
     
    else
    return 0;
}

void Treecreate()
{
  Node *p,*t;
  int x;
  Queue *q;
  //create(&q,100);
 
 cout<<"Enter root value ";
 cin>>x;
    root=new Node();
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(root);
 
 while(!isEmpty())
   {
        p=dequeue();
        cout<<"Enter left child of "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(t);
        }
       cout<<"Enter Right child of "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(t);
        }
    }
}


int main()
{  
   
   Treecreate();

    return 0;
}