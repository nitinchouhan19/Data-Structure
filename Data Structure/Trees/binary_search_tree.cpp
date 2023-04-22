#include <iostream>
using namespace std;

class Node{
  public:
  int data ;
  Node *left;
  Node *right;
  Node(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

void Insert(Node* &root,int data){
  Node* newNode = new Node(data);
  if(root == NULL)
  {
    root = newNode;
    return ;
  }
  if(data < root->data)
  {
    return Insert(root->left,data);
  }else{
    return Insert(root->right,data);
  }
}
Node* createBinaryTree()
{
  Node* root = NULL;
  cout<<"Enter the Number of values to be Inserted: ";
  int number_of_values;
  cin>>number_of_values;
  cout<<"\nEnter the values: ";
  for(int i=0;i<number_of_values;i++)
    {
      int value;
      cin>>value;
      Insert(root,value);
    }
  return root;
}

bool Search(Node* root,int key)
{
  if(root == NULL ){
    return false;
  }
  if( root->data == key)
  {
    return true;
  }
  if(root->data > key )
  {
    return Search(root->left,key);
  }
  else{
    return Search(root->right,key);
  }
}
void preorder(Node* root)
{
  if(root == NULL) return ;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root)
{
  if(root == NULL) return ;
  
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

Node* InorderSucc(Node* root)
{
  Node* temp = root;
  while(temp && temp->left!=NULL)
    {
      temp = temp->left;
    }
  return temp;
}

Node* Delete(Node* root,int key)
{
  if(key < root->data)
  {
    root->left = Delete(root->left,key);
  }
  else if (key > root->data )
  {
    root->right = Delete(root->right,key);
  }
  else
  {
    if(root->left == NULL)
    {
      Node* newRoot = root->right;
      delete(root);
      return newRoot;
    }
    else if(root->right == NULL)
    {
      Node* newRoot = root->left;
      delete(root);
      return newRoot;
    }
    else
    {
      Node* temp = InorderSucc(root->right);
      root->data = temp->data;
      root->right = Delete(root->right , temp->data);
    }
    
  }
  return root;
}


void inorder(Node* root)
{
  if(root == NULL) return ;
  
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void printTree(Node* node, int level = 0) {
    if (node != NULL) {
        printTree(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        cout << "|-- " << node->data << endl;
        printTree(node->left, level + 1);
    }
}

int main() {
  Node* root = createBinaryTree();
  cout<<'\n';
  printTree(root);
  if( Search(root,2) == true) cout<<"Key Exits\n";
  else cout<<"Key Doesn't Exist\n";
  Delete(root , 2);
  printTree(root);
  // cout<<"PREORDER: ";
  // preorder(root);
  // cout<<"\nINORDER: ";
  // inorder(root);
  // cout<<"\nPOSTORDER: ";
  // postorder(root);
  // cout<<'\n';
  // printTree(root);
}