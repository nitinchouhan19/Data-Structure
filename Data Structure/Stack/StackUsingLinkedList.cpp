#include <iostream>
using namespace std;

class node{
public:
int data;
node *next;

node(int data){
  this->data = data;
  next = NULL;
}
};

class stack{
private:
node *top;

public:
stack(){
  top = NULL;
}
void push(int x);
void pop();
int Top();
bool isEmpty();
void display();
};

void stack :: push(int x){
  node* n = new node(x);

  if(!n){
    cout<<"Stack Overflow\n";
  }

  if(top == NULL)
  {
    top = n;
    return ;
  }
  n->next = top;
  top = n; 
}

void stack :: pop()
{

  if(top == NULL)
  {
    cout<<"Stack Underflow\n" ;
    return ;
  }
  
  node* toDelete = top;
  top = top->next;
  delete toDelete;
}

int stack :: Top(){
  if(top == NULL){
    return -1;
  }
  return top->data;
}

bool stack :: isEmpty(){
  return top == NULL;
}

void stack :: display(){
  if(!top)
    {
        cout << "Stack is Empty\n";
    }
    node *temp = top;
    while(temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
  stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  (s.Top() == -1)? cout<<"Stack Underflow\n" : cout<<"Top Data : "<<s.Top()<<'\n';
  // if(s.isEmpty()){
  //   cout<<"Stack Underflow\n";
  // }
  
  s.display();
  s.pop();
  s.display();

}