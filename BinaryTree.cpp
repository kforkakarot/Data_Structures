#include <iostream>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;

void insert(Node *t, int key)
{
    

    if (t == NULL)
    {
        Node *p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
    }
    else
    {
        Node *r = NULL;
        while (t != NULL)
        {
            r = t;
            if (key == t->data)
                return;
            if (key < t->data)
                t = t->lchild;
            else if (key > t->data)
                t = t->rchild;
        }

        Node *p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;

        if (key < r->data)
            r->lchild = p;

        else if (key > r->data)
            r->rchild = p;
    }
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
int main()
{
    char ch = 'y';
    int x;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter Value ";
        cin >> x;
        insert(root, x);
        cout << "\nWant to enter more :";
        cin >> ch;
    }

    
    cout<<endl;

    Inorder(root);
}