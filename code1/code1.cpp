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
                    if(curr->next==NULL) cout<<"The Node with value-"<<val<<" is not present in the list"<<endl;   
                    else {
                        Node* temp=curr->next;
                        curr->next=curr->next->next;
                        cout<<"The node with value"<<val<<"is deleted from linked list"<<endl;
                        

                    }
                }
        }
        void search_value(int val){        //search the value is present in the list
            Node* curr=head;
            while(curr!=NULL && curr->data!=val){
                curr=curr->next;
            }
            if(curr!=NULL) cout<<"The Node with the value "<<val<<" is present in the linked list"<<endl;
            else  cout<<"The Node with value-"<<val<<" is not present in the list"<<endl;   
        }
        void print_list(){                 //print the linked list
            if(head==NULL){ cout<<"The linked list is empty"<<endl; return;}
            cout<<"<----The Linked list---->"<<endl;
            Node* curr=head;
            while(curr!=NULL){
                cout<<curr->data;
                if(curr->next!=NULL) cout<<"--->";
                curr=curr->next;
            }
            cout<<endl;

        }
        void reverse_list(){       //reverse the linked list
            Node* prev=NULL;
            Node* curr=head;
            while(curr!=NULL){
                Node* temp=curr->next;
                curr->next = prev;
                prev=curr;
                curr=temp;
            }
            head=prev;
        }
};
int main(){                     //main function
    cout<<"<--------The singly linked list--------->"<<endl;
    SLL list;                      //object of SLL
    int ch;
    do{
        cout<<"The options are::"<<endl;
        cout<<"1.To print th linked list"<<endl;
        cout<<"2.To insert at front of linked list"<<endl;
        cout<<"3.To insert at end of linked list"<<endl;
        cout<<"4.To Delete node by value"<<endl;
        cout<<"5.To search the node is present in linked list"<<endl;
        cout<<"6.To reverse the linked list"<<endl;
        cout<<"7.To quit"<<endl<<endl;
        cout<<"Enter the choice::";
        cin>>ch;
        cout<<endl;
        if(ch==1){
            list.print_list();
        }
        else if(ch==2){
            int val;
            cout<<"Enter the value to be inserted in front";
            cin>>val;                                
            list.insert_front(val);
        }
        else if(ch==3){
            int val;
            cout<<"Enter the value to be inserted in back";
            cin>>val;                                
            list.insert_back(val);
        }
        else if(ch==4){
            int val;
            cout<<"Enter the value to  delete ";
            cin>>val;                                
            list.delete_value(val);
        }
        else if(ch==5){
            int val;
            cout<<"Enter the value to search ";
            cin>>val;                                
            list.delete_value(val);
        }
        else if(ch==6){
            list.reverse_list();
        }
        else if(ch==7) break;
        else {
            cout<<"Enter the correct choices";
        }
        cout<<endl;
    }while(ch!=7);
    
    return 0;


}