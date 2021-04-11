#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *first = NULL, *second = NULL, *third = NULL,*last=NULL;
void insertEnd(node *p, int ele)
{
    node *n = new node();
    n->data = ele;
    n->next = NULL;

    if (!p)
        first = n;

    else
    {
        while (p->next)
        {
            p = p->next;
        }

        p->next = n;
    }
}
void insertEnd2(node *p, int ele)
{
    node *n = new node();
    n->data = ele;
    n->next = NULL;

    if (!p)
        second = n;

    else
    {
        while (p->next)
        {
            p = p->next;
        }

        p->next = n;
    }
}

void Display(node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void merge(node *p, node *q)
{
    
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    if (p->data > q->data)
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else 
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p != NULL)
    {
        last->next = p;
    }

    if (q != NULL)
    {
        last->next = q;
    }
}
int main()
{
    char ch = 'y';
    int x;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter Element to be inserted: ";
        cin >> x;
        insertEnd(first, x);
        cout << "\n Enter more(Y/N) ";
        cin >> ch;
    }

    Display(first);
    ch = 'y';
    cout << "\n Enter for second linked list \n";
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter Element to be inserted: ";
        cin >> x;
        insertEnd2(second, x);
        cout << "\n Enter more(Y/N) ";
        cin >> ch;
    }

    Display(second);

    merge(first, second);
    Display(third);
}