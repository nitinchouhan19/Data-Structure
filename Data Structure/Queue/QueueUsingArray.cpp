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
  if(rear == M-1)
  {
    cout<<"Queue Overflow\n";
    return;
  }
  ++rear;
  if(rear == 0){
     ++front;
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
  ++front;
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
  cout<<"Queue : ";
  for(int i = front ;i<=rear;i++){
    cout<<arr[i]<<" ";
  }
  cout<<'\n';
}


int main() {
  queue q;
  if(q.isEmpty()){
    cout<<"Queue is Empty\n";
  }
  q.push(1);
  q.push(2);
  q.push(3);
  q.pop();
  q.display();
}