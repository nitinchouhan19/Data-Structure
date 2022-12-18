#include <bits/stdc++.h>
#define M 1000
using namespace std;

class stack {
private:
  char arr[M];
  char top;

public:
  stack() { top = -1; }
  void push(char x);
  void pop();
  char Top();
  bool isempty();
};

void stack::push(char x) {
  if (top == (M - 1)) {
    cout << "Stack Overflow." << '\n';
    return;
  }
  top++;
  arr[top] = x;
}

void stack ::pop() {
  if (top == -1) {
    std::cout << "Stack Underflow." << '\n';
    return;
  }
  top--;
}

char stack ::Top() {
  if (top == -1) {
    std::cout << "Stack is empty" << '\n';
    return -1;
  }
  return arr[top];
}

bool stack ::isempty() { return top == -1; }

int precedence(char c){
  if( c == '^'){
    return 3;
  }
  else if(c == '*' || c == '/'){
    return 2;
  }
  else if(c == '+' || c == '-'){
    return 1;
  }
  else{
    return -1;
  }
}

string infix_to_postfix(string s){
  stack<char> st;
  string ans ="";
  for(int i=0;i<s.length();i++){
    if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') ){
      ans.push_back(s[i]);
    }
    else if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      while(!st.empty() && st.top()!='('){
        ans.push_back(st.top());
        st.pop();
      }
      st.pop();
    }
    else{
      while(!st.empty() && precedence(st.top()) > precedence(s[i]) ){
        ans.push_back(st.top());
        st.pop();
      }
      st.push(s[i]);
    }
  }
  return ans;
}

string infix_to_prefix(string s){
  stack st;
  string ans ="";
  for(int i=0;i<s.length();i++){
    if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') ){
      ans.push_back(s[i]);
    }
    else if(s[i] == ')'){
      st.push(s[i]);
    }
    else if(s[i] == '('){
      while(!st.empty() && st.top()!=')'){
        ans.push_back(st.top());
        st.pop();
      }
      st.pop();
    }
    else{
      while(!st.empty() && precedence(st.top()) >= precedence(s[i]) ){
        ans.push_back(st.top());
        st.pop();
      }
      st.push(s[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  string s;
  cin>>s;
  cout<<infix_to_postfix(s)<<'\n';
  reverse(s.begin(), s.end());
  cout<<infix_to_prefix(s)<<'\n';
}