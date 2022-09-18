#include<iostream>
using namespace std;
class queue{
    int sizeQueue;
    int front;
    int rear;
    int* array;
public:
    queue(int length){
        sizeQueue=length;
        front=-1;
        rear=-1;
        array=new int[length];
    }
    void enqueue(int item){
        if(front==0 and rear==sizeQueue){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        if(front==-1){
            front=0;
            rear=0;
        }else if(rear==sizeQueue){
            rear=0;
        }else{
            rear+=1;
        }
        array[rear]=item;
    }
    int dequeue(void){
        if(front==-1){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        int item=array[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }else if(front==sizeQueue){
            front=0;
        }else{
            front+=1;
        }
        return item;
    }
    void print(void){
        int temp=front;
        if(temp==rear){
            cout<<array[temp]<<" "<<endl;
        }else if(temp<rear){
            for(int i=front;i<=rear;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
            return;
        }else if(temp>rear){
            for(int i=front;i<=sizeQueue;i++){
                cout<<array[i]<<" ";
            }
            for(int j=0;j<=rear;j++){
                cout<<array[j]<<" ";
            }
        }
    }
};
int main(void){
    int del,size,selector=1,num;
    cout<<"Enter the size of the queue : ";
    cin>>size;
    queue Q(size);
    while(selector>0 and selector<3){
        cout<<">> 1 for enqueue\n>> 2 for dequeue\n>> Any other keys to EXIT "<<endl;
        cin>>selector;
        if(selector==1){
            cout<<"Enter the number to be enqueued : ";
            cin>>num;
            Q.enqueue(num);
            cout<<"After enqueuing : ";
            Q.print();
        }else if(selector==2){
            del=Q.dequeue();
            cout<< "  " <<del<<" dequed "<<endl;
            cout<<"After dequeuing : ";
            Q.print();
        }else{
            break;
        }
    }
    return 0;
}