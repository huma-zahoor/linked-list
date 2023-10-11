#include<iostream>
using namespace std;
class node
{
    public:
    string data;
    string data2;
    node* next;
    node(string val,string val2)
    {
        data =val;
        data2 =val2;
        next = NULL;
    }
};
void InsertAtTail(node* &head, string val, string val2)
{
    node* nn = new node(val,val2);
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
void InsertAtHead(node* &head,string val,string val2)
{
    
    node* nn =new node(val,val2);
    if(head==NULL)
    {
        head =nn;
        return;   
    }
    nn->next = head;
    head = nn;
}
void InsertAtMiddle(node* &head,string val,string val2,int p)
{
  
    node* nn =new node(val,val2);
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
void DeleteFromMiddle(node* head,string pos)
{
    node* temp =head;
    node* prev = NULL;
   if (head->data==pos) 
    {
        node* tem =head;
        //head->data= head->next->data;
      //  head->data2=head->data2;
        head =tem->next;
        delete tem;

    }
    else
    {
        while(temp->next !=NULL)
        {
            if(temp->data==pos)
            {
                prev->next =temp->next;
                delete temp;
                return;

            }
            else
            {
                prev =temp;
                temp =temp->next;
                
            }

        }
        if(temp->data ==pos)
        {
            prev->next =NULL;
            delete temp;
        }
    }}
/*for(int i=2; i< pos; i++) {
  if(temp->next!=NULL) {
    temp = temp->next;
  }
}*/
//int i=1;
//while (temp->next !=NULL)
//{
    /* code 
    cout<<" hi"<<endl;
    if (temp->data==pos)
    { 
        cout<<"hello"<< endl;
        temp->next = temp->next->next;
        cout << "kkk"<< endl;
        //break;
    }
    else
   { 
    cout<< "jjj"<<endl;
    temp = temp->next;
   }
   // i++;
}

if (temp->data==pos)
{

temp->next = temp->next->next;
}*/
//}

void DisplayLinkedList(node* head) 
{
     node* temp = head;
     cout << "LinkedList"<<endl;
     while(temp!=NULL)
     {
        cout << temp->data<<","<< temp->data2<< "->";
        temp = temp->next;
     }
     cout << "NULL"<<endl;
}
int main()
{
    node* head =NULL;
    string num2,num3,pos1;
    int num ,pos;
    cout<<"******Linked List******"<<endl;
    while (1)
    {  
    cout << "******Menu******"<< endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at Tail" << endl;
    cout << "3. Insert at any position" << endl;
    cout << "4. Delete from Head" << endl;
    cout << "5. Delete from Tails" << endl;
    cout << "6. Deletion by name" << endl;
    cout << "7. Show Linked List" << endl;
    cout << "8. EXIT" <<endl; 
    cout << "Choose number from the above menu"<< endl;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "Enter Full Name in the node"<<endl;
        getline(cin >> ws,num2);
        cout << "Enter Date of Birth in the node"<<endl;
        getline(cin >> ws,num3);
        //cin >> num2;
        InsertAtHead(head,num2,num3);
        break;
    case 2:
        cout << "Enter Full Name in the node"<<endl;
        getline(cin >>ws,num2); //cin >> num2;
        cout << "Enter Date of Birth in the node"<<endl;
        getline(cin >> ws,num3);
        InsertAtTail(head,num2,num3);
        break;
    case 3:
        cout << "Enter Full Name in the node"<<endl;
        getline(cin >>ws, num2);//cin >> num2;
        cout << "Enter Date of Birth in the node"<<endl;
        getline(cin >> ws,num3);
        cout << "Enter position where you want to add the node"<<endl;
        cin >> pos;
        InsertAtMiddle(head,num2,num3,pos);
        break;
    case 4:
        
        DeleteFromHead(head);
        break;
    case 5:
        
        DeleteFromTail(head);
        break;
    case 6:
        cout << "Enter Name which you want to remove From the List"<<endl;
        getline(cin >> ws,pos1);//cin >> pos1;
        DeleteFromMiddle(head,pos1);
        cout << pos1 <<"is Deleted"<<endl;
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