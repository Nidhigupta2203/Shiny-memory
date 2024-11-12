#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    //constuctor
    node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    //destructor
    ~node(){
        int val=this->data;
    if(this->next!=NULL){
      delete next;
      this->next=NULL;
    }
    cout<<"deleted value is :"<<val<<endl;
    }

};
void insertathead(node* & head ,int d){
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
 void insertattail(node* & tail,int d){
  node* temp=new node(d);
  tail->next=temp;
  temp->prev=tail;
  tail=temp;
 }
 void insertatpos(node* &head ,node* &tail ,int d ,int pos){
    node* temp=head;
    if(pos==1){
     insertathead(head,d);
     return;
    }
    int c=1;
    while(c < pos-1){
    temp=temp->next;
    c++;
    }
    if(temp->next==NULL){
         insertattail(tail,d);
         return;
    }
    node* ptr=new node(d);
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next->prev=ptr;
     temp->next=ptr;
     
 }
 node* reverse(node* &head,node* &tail){
    if(head==NULL || head->next==NULL){
        return head;
    }
    tail=head;
    node* temp=head;
    node* ptr=NULL;
    while(temp!=NULL){
        ptr=temp->prev;
        temp->prev=temp->next;
        temp->next=ptr;
        temp=temp->prev;
    }
     head=ptr->prev;
     return head;
 }
 void deleteatany(node* &head ,node* &tail ,int pos){
    if(pos==1){
     node* temp=head;
     head=head->next;
     temp->next=NULL;
     delete temp;
    }
    else{
        int c=1;
        node* curr=head;
        node* prev=NULL;
        while(c < pos){
            prev=curr;
            curr=curr->next;
            c++;
        }
        prev->next=curr->next;
        if(curr->next==NULL){
            tail=prev;
        }
        else{
            curr->next=NULL;
        }
        delete curr;
    }

 }
 void print(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }
int main(){
  node* head=new node(5);
   node* tail=head;
    print(head);
    cout<<endl;
   insertathead(head,4);
   print(head);
   cout<<endl;
    insertattail(tail,6);
    print(head);
    cout<<endl;
     insertatpos(head,tail,3,4);
     print(head);
     cout<<endl;
     reverse(head,tail);
      print(head);
     cout<<endl;
      return 0;
}