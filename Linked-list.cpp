#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data =val;
        next = NULL;
    }
};

void newFunction(){
    int alpha1 = 10;
    int alpha2 = 20;
    int c = alpha1+alpha2;
    cout << "c =" << c <<endl;
    return;
}


void InsertAtTail(node* &head, int val)
{
    node* nn = new node(val);
     nn->next = NULL;
    if(head==NULL)
    {
        head =nn;
        return; 
    }
    node* temp1 = head;
    while(temp1->next!= NULL)
    {
        temp1 =temp1->next;
    }
    temp1->next = nn;
}
void InsertAtHead(node* &head,int val)
{
    
    node* nn =new node(val);
    if(head==NULL)
    {
        head =nn;
        return;   
    }
    nn->next = head;
    head = nn;
}
void InsertAtMiddle(node* &head,int val,int p)
{
  
    node* nn =new node(val);
    if(head==NULL)
    {
        head =nn;
        return;   
    }
    node* temp = head;
    for(int i=2; i < p; i++) {
  if(temp->next != NULL) {
    temp = temp->next;
  }
}
nn->next = temp->next;
temp->next = nn;
}
void DeleteFromHead(node* &head)
{
    head = head->next;
}
void DeleteFromTail(node* &head)
{
    node* temp = head;
    while (temp->next->next!=NULL)
    {
        temp =temp->next;
    }
    temp->next =NULL;   
}
void DeleteFromMiddle(node* head,int pos)
{
    node* temp =head;
for(int i=2; i< pos; i++) {
  if(temp->next!=NULL) {
    temp = temp->next;
  }
}

temp->next = temp->next->next;
}
void DisplayLinkedList(node* head) 
{
     node* temp = head;
     cout << "LinkedList"<<endl;
     while(temp!=NULL)
     {
        cout << temp->data<< "->";
        temp = temp->next;
     }
     cout << "NULL"<<endl;
}
int main()
{
    node* head =NULL;
    int num ,num2, pos,pos1;
    cout<<"******Linked List******"<<endl;
    while (1)
    {  
    cout << "******Menu******"<< endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at Tail" << endl;
    cout << "3. Insert at any position" << endl;
    cout << "4. Delete from Head" << endl;
    cout << "5. Delete from Tail" << endl;
    cout << "6. Delete from any position" << endl;
    cout << "7. Show Linked List" << endl;
    cout << "8. EXIT" <<endl; 
    cout << "Choose number from the above menu"<< endl;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "Enter data in the node"<<endl;
        cin >> num2;
        InsertAtHead(head,num2);
        break;
    case 2:
        cout << "Enter data in the node"<<endl;
        cin >> num2;
        InsertAtTail(head,num2);
        break;
    case 3:
        cout << "Enter data in the node"<<endl;
        cin >> num2;
        cout << "Enter position where you want to add the node"<<endl;
        cin >> pos;
        InsertAtMiddle(head,num2,pos);
        break;
    case 4:
        
        DeleteFromHead(head);
        break;
    case 5:
        
        DeleteFromTail(head);
        break;
    case 6:
        cout << "Enter position where you want to remove the node"<<endl;
        cin >> pos1;
        DeleteFromMiddle(head,pos1);
        break;
    case 7:
         DisplayLinkedList(head);
         break;
  case 8:
  exit(0);
      break;    
   }
 }

    return 0;

}