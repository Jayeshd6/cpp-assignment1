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
        if(is_empty()){cout<<"Underflow--The queue is empty";}

    }

 
};
int main(){
    cout<<"hello";
}