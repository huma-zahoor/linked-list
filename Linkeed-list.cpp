#include<iostream>
using namespace std;
struct node
{
    /* data */
    int data;
    node* next;

};
    node* nn;
    node* temp;
    node* head=NULL;
void insertnode(int d)
{
    struct node* nn = new node;
    nn->data = d;
    temp = nn;
    head = nn;
    //cout << nn->data;
}
void insertnodefromfront(int d)
    {
        struct node* nn = new node;
        nn->data = d;
        temp->next = nn;
        temp = nn;
//cout << nn->data;

    }
void showlist()
{
    node* ptr;
    ptr =head;
    cout << "Linked List"<<endl;
    while(ptr!=NULL)
    {
        cout << ptr->data << "->";
        ptr =ptr->next;
    }
    cout << endl;
}

void deletefromthelist( int pos)
{
    node* pre = head;
    node* cur = head;
    if (head== NULL)
    {
        cout << " List is empty" << endl;

    }
    else if(pos == 1)
    {
        head = cur->next;
        delete cur;
        cur = NULL;
    }
    else
    {
        while (pos!=1)
        {
            pre =cur;
            cur = cur->next;
            pos --;

        }
    pre->next = cur->next;
    delete cur;
    cur = NULL;
    }
}
int main()
{
    int n, position;
    int num, num1;
    cout << "*********Linked List*********"<<endl;
    cout << "How many numbers of linked list you want to enter! "<<endl;
    cin >> n;
    cout <<"INSERT NODES"<<endl;
    cin >>num;
    insertnode(num);
for (int i=1;i<n;i++)
    {
        cin >> num1;
        insertnodefromfront(num1);
    }

    
    showlist();
    cout<<"Which position you want delete"<< endl;
    cin >> position;
    deletefromthelist(position);
    showlist();
return 0;
}
