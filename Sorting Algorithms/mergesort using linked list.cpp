#include <iostream>

using namespace std;
class list{
public:
int data;
list * next;
list(int x)
{
    this->data=x;
    this->next=nullptr;
}
};
list * newnode(int x)
{
    list * n=new list(x);
    return n;
}
list *mid(list *head)
{
    list *fast,*slow;
    fast=head;
    slow=head;
    while(fast&&fast->next&&fast->next->next)
    {
        slow =slow ->next;
        fast=fast->next->next;
    }
    return slow;
}

list *mergelist(list *h1,list *h2)

{  int lc=0;
    list *h3=nullptr,*t3=nullptr;
if((!h1)||(!h2))
    return nullptr;
while(h2&&h1)
{
    if((h1->data<h2->data)&&lc==0)
   {

    list *temp=h1;
    h1=h1->next;
    temp->next=nullptr;
    h3=temp;
    t3=temp;
    lc++;

   }
   else if(h1->data<h2->data)
   {
       list *temp=h1;
       h1=h1->next;
       temp->next=nullptr;
       t3->next=temp;
       t3=t3->next;

   }
   else if((h2->data<h1->data)&&lc==0)
   {
      list *temp=h2;
    h2=h2->next;
    temp->next=nullptr;
    h3=temp;
    t3=temp;
    lc++;
   }
   else if(h2->data<h1->data)
    {
      list *temp=h2;
       h2=h2->next;
       temp->next=nullptr;
       t3->next=temp;
       t3=t3->next;

    }

   }
   while(h1)
   {
       t3->next=h1;
       h1=nullptr;
   }
   while(h2)
   {
       t3->next=h2;
       h2=nullptr;
   }
   return h3;


}

list *mergesort(list *head)
{   if(head==nullptr)
       return nullptr;
    if(head->next==nullptr)
        return head;
    else
        {
        list *m=mid(head);
        list *p=m->next;
        m->next=nullptr;
        list *s1=mergesort(head);
        list *s2=mergesort(p);
        list *s=mergelist(s1,s2);
        return s;
        }
}
int main()
{
    int n;
    cout<<"enter how many elements you want in your linked list";
    cin>>n;
    int b;
    list *head,*tail;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {   cin>>b;
            head=newnode(b);
            tail=head;
        }
        else
            {
                cin>>b;
                tail->next=newnode(b);
                tail=tail->next;
        }
    }
        list *temp=head;
        while(temp!=nullptr)
        {
         cout<<temp->data<<" ";
         temp=temp->next;
        }
        list *head2=mergesort(head);
        list *temp2=head2;
        cout<<endl;
        while(temp2)
        {
            cout<<temp2->data<<" ";
            temp2=temp2->next;
        }



    return 0;
}
