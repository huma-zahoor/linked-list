#include<iostream>
#include <iomanip>
#include <bits/stdc++.h> 
#include <sstream>
#include <fstream>
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
/*void DeleteFromHead(node* &head)
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
}*/
void DeletionByName(node* &head,string pos)
{
   
  if(head==NULL)
{
    cout<< " List is empty!!!!"<<endl;

}
else if(head!=NULL)
{
    
    if(head->data == pos)
    {
        node* temp = head; 
        head = head->next;
        delete temp;
        return;

    }
    else

    {
         node* tem =head;
         node* prev = NULL;
        
        while(tem!=NULL)
        {
           
            if(tem->data==pos)
            {
                
                prev->next =tem->next;
                
                delete tem;
                return;

            }
            else
            {
                prev =tem;
                tem =tem->next;
                
            }

        }
        if(tem->data ==pos)
        {
            prev->next =NULL;
            delete tem;
        }
    }

    }}
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
 bool SearchByName(node* &head,string val)
    {
      node* temp = head;
      while(temp != NULL)
      {
        if (temp->data == val)
        {
            cout<<val<<" is found!!"<<endl;
          return true;
        }
        temp = temp->next;
      }
      cout<<val<<" is not found!!"<<endl;
      return false;
    }
    void WriteDataInTheFile(node* head)
  {
    ofstream file("List.txt");
    node * temp = head;
      //to print the key and data of every node in the list
      while (temp != NULL)
      {
        file << temp -> data << setw(15) <<  temp -> data2;
        temp = temp -> next;
        file << endl;
      }
      cout << "----- Linked list backed up successfully -----" << endl << endl;

  }
  void ReadDataFreomFile(node* head)
  {
    ifstream file ;
    file.open("List.txt",ios::in);
    if(!file)
    {
        cout<<"File Dosen't exist!!!"<<endl;
    }
    else
    {
        
        file.seekg(0, ios::beg);
        string line;
        string n1;
        string d1;

        while(file)
        {
            getline(file,line);
          //  cout <<line<<endl;
            stringstream obj_ss(line);
     // getline() function to go through source string until it is finished.
 
    getline(obj_ss, n1, ',');
    
    cout << n1 << endl;
        int pos = line.find(",");
        d1 = line.substr(pos+1);
        cout << d1<< endl;
        InsertAtTail(head,n1,d1);
     //InsertAtHead(head,n1,d1);
            if(file.eof())
            {
                break; 
            }



        }
DisplayLinkedList(head);
    }
    file.close();

  }
int main()
{
    node* head =NULL;
    string num2,num3,pos1,pos2;
    int num ,pos;
    cout<<"******Linked List******"<<endl;
    while (1)
    {   
    cout << "******Menu******"<< endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at Tail" << endl;
    cout << "3. Insert at any position" << endl;
    //cout << "4. Delete from Head" << endl;
    //cout << "5. Delete from Tails" << endl;
    cout << "4. Deletion by name" << endl;
    cout << "5. Show Linked List" << endl;
    cout << "6. Searching the list by name!!!" << endl;
    cout << "7. Write data in the file"<<endl;
    cout << "8. Read from file and write in the linked list"<<endl;
    cout << "9. EXIT" <<endl; 
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
   /*case 4:
        
        DeleteFromHead(head);
        break;
    case 5:
        
        DeleteFromTail(head);
        break;*/

    case 4:
        cout << "Enter Name which you want to remove From the List"<<endl;
        getline(cin >> ws,pos1);//cin >> pos1;
        DeletionByName(head,pos1);
        cout << pos1 <<" is Deleted"<<endl;
        break;
    case 5:
         DisplayLinkedList(head);
         break;
    case 6:
    cout << "Enter Name which you want to Search From the List"<<endl;
        getline(cin >> ws,pos2);//cin >> pos1;
        SearchByName(head,pos2);
        break;
         
    case 7:
        WriteDataInTheFile(head);
        break;
    case 8:
    ReadDataFreomFile(head);
    break;

  case 9:
  exit(0);
      break;    
   }
 }

    return 0;

}