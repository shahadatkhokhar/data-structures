#include <iostream>
#include "QueueCpp.h"
#include <stdio.h>
#include <stack>
using namespace std;

class Tree
{
public:
    Node *root;
    Tree()
    {
        root=NULL;
    }
    void CreateTree();
    void preOrder(Node* p);
    void postOrder(Node* p);
    void InOrder(Node *p);
    void LevelOrder(Node *p);
    void height(Node* p);
    void Levelorder()
    {
        Levelorder(root);
    }
    void Levelorder(Node *p);
    int Height()
    {
        return Height(root);
    }
    int Height(Node *root);
    void iterativePreorder(Node *p);
    void iterativeInorder(Node *p);
    void iterativePostorder(Node *p);
    void ILevelOrder(Node *root);
    int Count(Node *root);
    int height2(Node *root);
};

void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    printf("Enter root Value:");;
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("Enter left child of %d:",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter Right child of %d:",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::InOrder(Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        printf("%d ",p->data);
        InOrder(p->rchild);
    }
}


void Tree::preOrder(Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p)
{
    if(p)
    {

        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ",p->data);
    }
}

void Tree::Levelorder(Node *p)
{
    Queue q(100);
    printf("%d ",root->data);
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    int x=0,y=0;
    if(root==0) return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)return x+1;
    else return y+1;
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}
void Tree::iterativePostorder(Node *p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

void Tree::ILevelOrder(Node *root)
{
    Queue q(100);
    printf("%d",root->data);
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }

}

int Tree::Count(Node *root)
{
    if(root)
        return Count(root->lchild) +Count(root->rchild)+1;
    else
        return 0;
}

int Tree::height2(Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height2(root->lchild);
    y=height2(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;

}
int main()
{
    Tree t;
    t.CreateTree();
    printf("Count: %d",t.Count(t.root));
    printf("Height: %d",t.height2(t.root));

    return 0;
}
