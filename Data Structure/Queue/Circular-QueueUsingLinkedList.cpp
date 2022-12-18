#include <iostream>
using namespace std;

class node
{
public:
int data;
node *next;

node(int value){
  data = value;
  next = NULL;
}
};

class queue{
private :
node *front;
node *rear;

public:
queue(){
  front = NULL;
  rear = NULL;
}

void push(int x);
void pop();
int Front();
int Rear();
bool isEmpty();
void display();
};

void queue :: push(int x)
{
  node* n = new node(x);
  if(isEmpty()){
    rear = n;
    front = n;
    return ;
  }
  rear->next = n;
  rear = n;
  rear->next = front;
}

void queue::pop(){
  if(isEmpty()){
    cout<<"Queue UnderFlow\n";
    return ;
  }
  node* toDelete = front;
  if(front == rear)
  {
    front = NULL;
    rear = NULL;
    delete toDelete;
    return ;
  }

  front = front->next;
  delete toDelete;
}

int queue::Front()
{
  if(isEmpty()){
    cout<<"Queue UnderFlow\n";
    return -1 ;
  }
  return front->data;
}

int queue::Rear()
{
  if(isEmpty()){
    cout<<"Queue UnderFlow\n";
    return -1 ;
  }
  return rear->data;
}

bool queue::isEmpty()
{
  if(rear == NULL && front == NULL){
    return true;
  }
  return false;
}

void queue::display()
{
  if(isEmpty()){
    cout<<"Queue UnderFlow\n";
    return ;
  }

  node* temp = front;
  do{
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }while(temp!=front);
  cout<<'\n';
}


int main() {
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.display();
  q.pop();
  q.push(7);
  q.display();
  cout<<"Front : "<<q.Front()<<'\n';
  cout<<"Rear : "<<q.Rear()<<'\n';
}