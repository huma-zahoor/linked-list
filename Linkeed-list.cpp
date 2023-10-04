#include <iostream>>
using namespace std;
struct node
{
    /* data */
    int data;
    node* next;
};
struct Node* head = NULL;
void insertnode(int nodedata,node* hn)
{
    struct node* nn = new node;
    nn->data = nodedata;
    nn->next = hn->next;
    
}
