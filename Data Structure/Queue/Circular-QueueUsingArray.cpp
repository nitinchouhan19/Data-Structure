#include <iostream>
#define M 1000
using namespace std;

class queue{
private :
int arr[M];
int front;
int rear;

public:
queue(){
  front = -1;
  rear = -1;
}

void push(int x);
void pop();
int Front();
int Rear();
bool isEmpty();
void display();
}; 

void queue::push(int x)
{
  rear = (rear+1) % M;
  if(rear == front)
  {
    cout<<"Queue Overflow\n";
    return;
  }
  if(rear == 0 && front == -1){
    front = (front+1) % M;
  }
  arr[rear] = x;
}

void queue::pop()
{
  if(front == -1)
  {
    cout<<"Queue Underflow\n";
    return;
  }
  
  if(front == rear){
    front = -1;
    rear = -1;
    return ;
  }
  front = (front+1) % M;
}

int queue :: Front()
{
  if(front == -1)
  {
    cout<<"Queue Underflow\n";
    return -1;
  }
  
  return arr[front];
}

int queue :: Rear()
{
  if(rear == -1)
  {
    cout<<"Queue Underflow\n";
    return -1;
  }
  
  return arr[rear];
}

bool queue :: isEmpty()
{
  if(front == rear && rear == -1)
    return true;
  return false;
}

void queue :: display()
{
  if(isEmpty()){
    cout<<"Queue is Empty\n";
    return;
  }
  
  int i=front;
  while(i != rear)
    {
      cout<<arr[i]<<" ";
      i = (i+1) % M ;
    }
  cout<<arr[i]<<'\n';
}


int main() {
  queue q;
  q.push(1);
  q.push(5);
  q.pop();
  q.push(6);
  q.pop();
  q.push(7);
  q.display();
}