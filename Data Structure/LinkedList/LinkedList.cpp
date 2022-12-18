#include <iostream>
#include <limits.h>
using namespace std;

class node{
  public:
  int data ;
  node* next;
  node(int val){
    data = val;
    next = NULL;
  }
};

void insert_at_tail(node* &head,int val)
{
  node* n = new node(val);
  node* temp = head;
  if(head == NULL)
  {
    head= n;
    return;
  }
  while(temp->next!=NULL)
  {
    temp =temp->next;
  }
  temp->next=n;
  n->next = NULL;
}

void insert_at_head(node* &head,int val)
{
  node* n = new node(val);
  n->next=head;
  head=n;
}

void insert(node* &head,int val,int key)
{
  node* n = new node(val);
  node* temp = head;
  while(temp->data!=key)
  {
    if(temp ->next == NULL)
    {
      cout<<"Key not found"<<'\n';
      return;
    }
    temp = temp->next;
  }
  n->next = temp->next ;
  temp->next = n;
}

void del_te(node* &head,int key)
{
  node* temp = head;
  node* toDelete ;
  if(temp == head && temp->data==key)
  {
    toDelete = head;
    head = head->next;
    delete toDelete;
    return ;
  }
  
  while(temp->next->data!=key)
  {
    if(temp ->next == NULL){
      cout<<"Key not found"<<'\n';
      return;
    }
    temp = temp->next;
  }
  temp->next = toDelete;
  temp->next = temp->next->next;
  delete toDelete;
}

int countnode(node* head)
{
  node* temp = head;
  int count = 0;
  while(temp!=NULL)
  {
    count++;
    temp =temp->next;
  }
  return count ;
}

void loop_detect(node* head)
{
  node* slow = head;
  node* fast = head;
  
  //Floyd's Algorithm

  while(fast!= NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow ==fast)
    {
      cout<<"Loop is found.\n";
      return;
    }
  }
  cout<<"Loop not found.\n";
}

void node_in_cycle(node* head )
{
  node* slow = head;
  node* fast = head;
  int nodecount=0;
  int count = 0;
  while(count < 2  )
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow ==fast)
    {
      count++;
    }
    if(count == 1)
    {
      nodecount++;
    }
    //Traverse list for two times one to get loop detect and
    // second time to count nodes
  }
  cout<<"Number of nodes in cycle : "<<nodecount<<'\n';
}

int sum(node* head)
{
  node* temp = head;
  int sum = 0 ;
  while(temp != NULL)
  {
    sum += temp->data;
    temp = temp->next;
  }
  return sum;
}

void find(node* head,int key)
{
  node* temp =head ;
  int count = 1 ;

  while(temp->data != key)
  {
    if(temp->next == NULL && temp->data != key)
    {
      cout<<key <<" is not in list"<<'\n';
      return;
    }

    temp =temp->next;
    count++;
  }
  cout<<key<<" is at node "<<count<<'\n';
}

void findRecursive(node* head ,int key,int count,int frequency)
{
  
  if(head == NULL)
  {
    return;
  }

  if(head->data == key)
  {
    cout<<key <<" is at node "<<count<<'\n';
    frequency++;
    cout<<"Frequency of "<<key << "till node "<<count<<" is " <<frequency<<'\n';
  }
  count++;
  
  return findRecursive(head->next , key , count , frequency);
  
}

node* reverse(node* &head)
{
  node* prev = NULL;
  node* current = head;
  node* nextptr;

  while(current!=NULL)
  {
    nextptr= current->next;
    current->next = prev;
    prev = current ;
    current = nextptr;
    
  }
  return prev;
}

node* reverseRecursive( node* &head )
{
  if(head == NULL || head->next == NULL)
  {
    return head;
  }
  
  node* recursivehead = reverseRecursive(head->next);
  head->next->next = head ;
  head->next = NULL ;
  
  return recursivehead;
}

node* reccursiveReverse(node* head , node* nxthead)
{
    node* newhead ;
    if(head->next!=NULL)
    {
        reccursiveReverse(head, head->next);
        head->next = nxthead;
    }
    else
        newhead = nxthead;
  return newhead;
}

void max_min(node* head)
{
  node* temp = head;
  int max = INT_MIN;
  int min = INT_MAX;
  while(temp != NULL)
    {
      if(temp->data > max)
      {
        max = temp->data;
      }
      if(temp->data < min)
      {
        min = temp->data;
      }
      temp = temp->next;
    }
  cout<<"Maximum : "<<min<<'\n';
  cout<<"Minimum : "<<max<<'\n';
}

bool isSorted(node* head)
{
  node* temp = head;

  while(temp->next != NULL)
  {
    if(temp->data > temp->next->data)
    {
      return false;
    }
    temp = temp->next;
  }
  return true;
}

void getnthnode(node* head ,int n)
{
  node* temp = head;
  int count = 1;
  int totalnodes = countnode(head);

  if(head == NULL)
  {
    cout<<"Linked list is empty"<<'\n';
    return;
  }

  if(n > totalnodes || n < 1)
  {
    cout<<"Enter a valid node "<<'\n';
    return;
  }

  while(temp!= NULL)
  {
    if(n == count)
    {
      cout<<"Data at "<<n<<"th node is "<<temp->data<<'\n';
    }
    temp = temp->next;
    count++;
  }
}

void lastnthnode(node* head , int n)
{
  node* temp = head;
  node* nthnode = head;
  
  int count = 1;
  int totalnodes = countnode(head);
  if(head == NULL)
  {
    cout<<"Linked list is empty"<<'\n';
    return;
  }
  if(n > totalnodes || n < 1)
  {
    cout<<"Enter a valid node "<<'\n';
    return;
  }
  while(temp != NULL)
  {
    if(count > n)
    {
      nthnode = nthnode->next;
    }
    temp = temp->next;
    count++;
  }
  cout<<"Data at "<<n<<"th node from last is "<<nthnode->data<<'\n';
}

void middle2ptr(node* &head)//find middle of list using slow and fast pointer
{
  node* slow = head;
  node* fast = head;
  int count= 0 ;

  while(fast!=NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    count++;
  }
  cout<<"Data at mid is "<<slow->data<<'\n';
}

void middle(node* head)
{
  int totalnodes = countnode(head);
  int middle = totalnodes/2;
  node* temp = head;
  int count = 1;

  while(count != middle )
  {
    temp = temp->next;
    count++;
  }

  if(totalnodes % 2 != 0)
  {
    cout<<"Data at mid is "<<temp->next->data<<'\n';
  }
  else{
    cout<<"Data at mid is "<<temp->data<< " and "<<temp->next->data<<'\n';
  }
}

void getinersection(node* head1 , node* head2)//return a node when two list intersect at any particular node
{
  int nodes1 = countnode(head1);
  int nodes2 = countnode(head2);
  node* temp1 = head1;
  node* temp2 = head2;
  int difference,count = 0;
  
  if(nodes1 >= nodes2)
  {
    difference = nodes1 - nodes2;

    while(count!=difference)
    {
      temp1=temp1->next;
      count++;
    }
  }
  else{
    difference = nodes2 - nodes1 ;

    while(count!=difference)
    {
      temp2=temp2->next;
      count++;
    }
  }
  while(temp1->next != NULL && temp2->next!= NULL)
  {
    if(temp1 == temp2)
    {
      cout<<"Data at intersection is "<<temp1->data<<'\n';
      return;
    }

    temp1=temp1->next;
    temp2=temp2->next;
  }
  cout<<"No intersection node "<<'\n';
}

void intersectionnodes(node* head1 , node* head2,node* &resulthead) 
{
  node* temp1 = head1;
  node* temp2 = head2;
  node* temp3 = resulthead;
  while(temp1!= NULL && temp2!=NULL)
  {
    
    if(temp1->data == temp2->data)
    {
      insert_at_tail(resulthead , temp1->data);
      temp1 = temp1->next;
      temp2 = temp2->next;
    }

    else if(temp1->data > temp2->data)
    {
      temp2 = temp2->next;
    }

    else
    {
      temp1 = temp1->next;
    }
  }
}

node* merge(node* head1 , node* head2)
{
  node*  temp1 =head1 ;
  node*  temp2 =head2 ;
  node* newhead;
  node* track;

  if(head1->data < head2->data)
  {
    newhead = head1;
    track = newhead;
    temp1=temp1->next;
  }

  else 
  {
    newhead = head2;
    track = newhead;
    temp2=temp2->next;
  }

  while((temp1 != NULL) && (temp2 != NULL))
  {
    if(temp1->data < temp2->data)
    {
      track->next=temp1;
      temp1=temp1->next;
      track=track->next;
    }
    else
    {
      track->next=temp2;
      temp2=temp2->next;
      track=track->next;
    }
  }
  if(temp2 != NULL)
  {
    while(temp2 != NULL)
    {
    track->next = temp2;
    temp2 = temp2->next;
    track = track->next;
    }
  }

  else
  {
    while(temp1 != NULL)
    {
    track->next = temp1;
    temp1 = temp1->next;
    track = track->next;
    }
  }
  return newhead;
}

void makeLoop(node* head,int n)
{
  node* temp = head;
  node* toloop = head;
  int count = 1;
  int totalnodes = countnode(head);
  if(n >= totalnodes || head == NULL || head->next == NULL)
  {
    cout<<"Making Loop not posible"<<'\n';
    return;
  }
  while(temp->next != NULL)
  {
    if(count < n)
    {
      toloop = toloop->next;
    }
    temp = temp->next;
    count++;
  }
  temp->next = toloop;
}

void sorted_Remove_Duplicate(node* head)
{
  node* temp = head;
  node* nxtptr = head->next;
  while(nxtptr->next != NULL)
  {
    if(temp->data == nxtptr->data)
    {
      node* toDelete = nxtptr;
      nxtptr = nxtptr->next;
      temp->next = nxtptr;
      delete toDelete;
    }
    temp = temp->next;
    nxtptr = nxtptr->next;
  }
  if(temp->data == nxtptr->data)
    {
      node* toDelete = nxtptr;
      temp->next = NULL;
      delete toDelete;
    }
}

void concatenate(node* head1 , node* head2)
{
  node* temp = head1;

  while(temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = head2;
}

void print(node* head)
{
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp =temp->next;
  }
  cout<<"NULL"<<'\n';
}

int main() 
{
    node* head = NULL;
    node* head  = NULL;
    return 0;
}