#include <bits/stdc++.h>
#define M 1000
using namespace std;

class stack{
private :
string s[M];
int top ;
public:
stack(){
  top = -1;
}
void push(string a);
void pop();
string Top();
bool isempty();
};

void stack::push(string a){
  if( top == M-1){
    cout<<"Stack Overflow"<<'\n';
    return ;
  }
  top++;
  s[top] = a;
}

void stack::pop(){
  if(top == -1){
    cout<<"Stack Underflow"<<'\n';
    return;
  }
  top--;
}

string stack::Top(){
  if(top == -1){
    cout<<"No element in stack"<<'\n';
    return "";
  }
  return s[top];
}

bool stack :: isempty(){
  return top == -1;
}

int main(){
    stack s;
    s.push("Stack");
    s.pop();
    s.Top();
    s.isempty();
    return 0;
}