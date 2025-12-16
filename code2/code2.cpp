//Circular Queue Using Array
#include<iostream>
using namespace std;
class circular_queue{
    private:
    int *arr;
    int rear;
    int front;
    int capcity;
    public:
    circular_queue(int cap){        //constructor 
        arr=new int[cap];
        front=-1;
        capcity=cap;
        rear=-1;
    }
    bool is_empty(){                             //check --->empty function
        if(front==-1) return true;
        return false;

    }
    bool is_full(){                               //check ---->full function 
        if(rear+1==front || (rear=capcity-1 && front==0)) return true;
        else return false;

    }
    void enqueue(int val){                                 //enqueue function
        if(is_full()) {cout<<"Overflow--The queue is full"<<endl; return;}      //overlflow condition
        else if(front==-1){
            front=0;
            rear=0;
        }
        else if(rear==capcity-1){
            rear=0;
        }
        else rear++;
        arr[rear]=val;
        cout<<"The element with value "<<val<<"is added in the queue"<<endl;
    }
    void dequeue(){                                //dequeue function
        if(is_empty()){cout<<"Underflow--The queue is empty"<<endl; return ;}
        int ele=arr[front];
        if(rear==front){
            rear=-1;
            front=-1;
        }
        else if(front==capcity-1){
            front=0;

        }
        cout<<"The elemnt with value-- "<<ele<<" is removed from circular queue"<<endl;

    }
    void getpeek(){      // get peek form circular queue
        if(is_empty()) {cout<<"The Circular queue is empty"<<endl;} 
        else cout<<"The element in the fornt is "<<arr[front]<<endl;

    }
    void printqueue(){    //printing the circular queue
        if(is_empty()) {cout<<"The Circular queue is empty"<<endl; return;}
        else {
            cout<<"The circular queue---"<<endl;
            int i=front;
            do{
                cout<<arr[i];
                i=(i+1)%capcity;
            }while(i!=rear);
        }  
    }


 
};
int main(){
    cout<<"Enter the capcity of circular queue"<<endl;
    int capacity;
    cin>>capacity;
    circular_queue q(capacity);
    int choice;
    do{
        cout<<"The choices are--"<<endl;
        cout<<"1.To enqueue the element in circualr queue"<<endl;
        cout<<"2.To dequeue the element from circular queue"<<endl;
        cout<<"3.To get the peek(front) element"<<endl;
        cout<<"4.To print the elements of circualr queue"<<endl;
        cout<<"5.To quit"<<endl;
        cout<<"Enter the choice";
        cin>>choice;
        if(choice==1){
            cout<<"Enter the element to insert in the queue";
            int element;
            cin>>element;
            q.enqueue(element);

        }
        else if(choice==2){
            q.dequeue();
        }
        else if(choice==3){
            q.getpeek();
        }
        else if(choice==4){
            q.printqueue();
        }
        else if(choice==5){
            cout<<"quitted"<<endl;
            break;

        }
        else{
            cout<<"Enter the valid choice"<<endl;
        }


    }while(choice!=5);

}