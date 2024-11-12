#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* next;
    //constuctor
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    //destructor
    ~node(){
        int val=this->data;
    if(this->next!=NULL){
      delete next;
      this->next=NULL;
    }
    // cout<<"deleted value is :"<<val<<endl;
    }

};
void insertathead(node* & head ,int d){
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}
 void insertattail(node* & tail,int d){
  node* temp=new node(d);
  tail->next=temp;
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
     temp->next=ptr;
     
 }

 void removeDuplicates(node* &head)
{  
    if(head == NULL){
        return;
    }
         map<int,bool>vist;
          node* curr = head;
            node* temp = head;
          while(curr !=NULL){
              if(vist[curr -> data] == true){
                  temp -> next = curr ->next;
                  delete curr;

              } else {
                 vist[curr -> data] = true;
                 temp = curr;
                 curr = curr->next;
              }
              curr=temp->next;
          }

       return;
}
//  void deleteatany(node* &head ,node* &tail ,int pos){
//     if(pos==1){
//      node* temp=head;
//      head=head->next;
//      temp->next=NULL;
//      delete temp;
//     }
//     else{
//         int c=1;
//         node* curr=head;
//         node* prev=NULL;
//         while(c < pos){
//             prev=curr;
//             curr=curr->next;
//             c++;
//         }
//         prev->next=curr->next;
//         if(curr->next==NULL){
//             tail=prev;
//         }
//         else{
//             curr->next=NULL;
//         }
//         delete curr;
//     }

//  }
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
    insertathead(head,4);
    insertattail(tail,6);
    print(head);
    cout<<endl;
     insertatpos(head,tail,3,4);
       insertattail(tail,6);
         insertattail(tail,5);
     print(head);
     cout<<endl;
     removeDuplicates(head);
     cout<<"unique elements";
      print(head);
     cout<<endl;

    //  cout<<"element after deletion :"<<endl;
    // deleteatany(head,tail,1);
    //  print(head);
    //  cout<<endl;
    //   deleteatany(head,tail,2);
    //  print(head);
    //  cout<<endl;
    //   deleteatany(head,tail,2);
    //  print(head);
    //  cout<<endl;

return 0;
}