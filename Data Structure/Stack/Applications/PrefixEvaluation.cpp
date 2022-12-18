#include <iostream>
using namespace std;
#define M 1000

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

int prefix_evalutation(string s) {
  stack st;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] >= '0' && s[i] <= '9') {
      st.push(s[i] - '0');
    } else {
      int op1 = st.Top();
      st.pop();
      int op2 = st.Top();
      st.pop();
      int result;
      switch (s[i]) {
      case '+': {
        result = (op1 + op2);
        break;
      }
      case '-': {
        result = (op2 - op1);
        break;
      }
      case '*': {
        result = (op1 * op2);
        break;
      }
      case '/': {
        result = (op2 / op1);
        break;
      }
      }
      st.push(result);
    }
  }
  return st.Top();
}

int main() {

  string s;
  cin >> s;
  cout << prefix_evalutation(s)<<'\n';
}