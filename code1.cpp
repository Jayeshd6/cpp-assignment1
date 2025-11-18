// Singly linked list Code
#include<iostream>                  //header file
using namespace std;
class Node{                         //node class
    private:
    int data;
    Node* next;
               
    Node(int val){
        data=val;
        next=NULL;
    }
    public:
    friend class SLL;
    
};
class SLL{               //Singly linked list class
    private:
        Node* head=NULL;                 //head pointer

    public:
        void insert_front(int val){      //insert front method
                if(head==NULL){         //linked list is empty
                    head=new Node(val);
                   
                } 
                else{                    //linked list is not empty
                    Node* temp=new Node(val);
                    temp->next=head;
                    head=temp;
                }
                cout<<"Node with data is inserted in linked list"<<endl;
        }
        void insert_back(int val){      //insert at end method
                 if(head==NULL){         //linked list is empty
                    head=new Node(val);
               
                } 
                else{                    //linked list is not empty
                    Node* temp=new Node(val);
                    Node* curr=head;
                    while(curr->next!=NULL){
                        curr=curr->next;
                    }
                    curr->next=temp;
                    
                }    
        }
        void delete_value(int val){   //deletion for given value
                if(head==NULL) cout<<"The linked list is empty"<<endl;
                else if(head->data==val) {  //Node to be deleted is head;
                    Node* temp=head;
                    head=head->next;
                    delete temp;
                    cout<<"The node with value"<<val<<"is deleted from linked list"<<endl;
                }
                else{
                    Node* curr=head;
                    while(curr->next!=NULL && curr->next->data==val){
                        curr=curr->next;
                    }
                }
                
            

        }

         



};
int main(){
    cout<<"HELLO";
    return 0;


}