#include <iostream>
using namespace std;
struct node
{
    node *lchild;
    int data;
    node *rchild;
} *root = NULL;
struct Queue
{
    node *q;
    Queue *next;
} *front = NULL, *rear = NULL;

struct stack
{
    node *node;
    stack *next;
}*top=NULL;

void push(node *t)
{  stack *st=new stack();
    st->node=t;
    st->next=NULL;
    if(top==NULL)
    {
        top=st;
    }

    else
    {
        st->next=top;
        top=st;
    }
}

node * pop()
{ node *t=NULL;
 stack *st=NULL;
    if(top!=NULL)
    {
       t=top->node;
       st=top;
       top=top->next;
       delete(st);
    }

    return(t);
}

int isempty()
{
    if(top==NULL)
        return 1;
    else
    return 0;
}

void enqueue(node *x)
{
    Queue *t = new Queue();
    t->q = x;
    t->next = NULL;
    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

node *dequeue()
{
    node *x = NULL;
    Queue *t = NULL;
    if (front == NULL)
        cout << "Queue is empty";

    else
    {
        t = front;
        x = front->q;
        front = front->next;
        delete (t);
    }
    return x;
}

void Display()
{
    Queue *t = front;

    while (t)
    {
        cout << t->q <<" ";
        t = t->next;
    }
}
int isEmpty()
{
    if (front == NULL)
        return 1;

    else
        return 0;
}
void Treecreate()
{
    node *p, *t;
    int x;
    Queue *q;

    cout << "Enter root value ";
    cin >> x;
    root = new node();
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(root);

    while (!isEmpty())
    {
        p = dequeue();
        cout << "Enter left child of (-1 if not) " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        cout << "Enter Right child of (-1 if not) " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}

void Preorder(node *t)
{   cout<<"\n";
    while(t!=NULL||!isempty())
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            push(t);
            t=t->lchild;
        }

        else
        {
            t=pop();
            t=t->rchild;
        }
    }
}
void Inorder(node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
void preorder(node *p)
{
    if (p)
    {
        cout << p->data <<" ";
        Inorder(p->lchild);
        Inorder(p->rchild);
    }
}
void postorder(node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        Inorder(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    Treecreate();
    Inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    Preorder(root);
    
}