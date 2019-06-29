#include<stdio.h>
#include<stdlib.h>

struct LL
{
   struct LL *prev;
   struct LL *next;
   int data;
};

struct LL *start=NULL;

void AddNode(int data, int pos)
{
   int k=1;
   struct LL *p,*q;
   struct LL *tmp=(struct LL*)malloc(sizeof(struct LL));
   tmp->next=NULL;
   tmp->prev=NULL;
   tmp->data=data;
   p=start;
   if(pos==1)
   {
     tmp->next=start;
     tmp->prev=NULL;
     if(p)
     {
       p->prev=tmp;
     }
     start=tmp;
   }
   else
   {
     while(p->next != NULL && k<pos)
      {
        k++;
        p=p->next;
      }
      if(p->next==NULL)
      {
      p->next=tmp;
      tmp->prev=p;
      }
      else
      {
      tmp->prev=p->prev;
      p->prev->next=tmp;
      tmp->next=p;
      p->prev=tmp;
      }
   }

}

void PrintNode()
{
   struct LL *tmp;
   tmp=start;
   while(tmp != NULL)
   {
    printf("%d->",tmp->data);
    tmp=tmp->next;
   }

}

void DeleteNode(int pos)
{
   int k=1;
   struct LL *p=start;
   if(pos == 1)
   {
    start=start->next;
    if(start != NULL)
     start->prev=NULL;
    free(p);
   }
   else
   {
    while(p->next != NULL && k < pos)
     {
      k++;
      p=p->next;
     }
     if(p->next == NULL)
     {
      p->prev->next=NULL;
      free(p);
     }
     else
     {
     p->prev->next=p->next;
     p->next->prev=p->prev;
     free(p);
     }
   }
}


int main()
{
void (*fun_ptr)(int,int)=AddNode;
(*fun_ptr)(2,1);
(*fun_ptr)(4,2);
(*fun_ptr)(6,3);
(*fun_ptr)(8,4);
AddNode(10,3);
//AddNode(10,3);
   PrintNode();  
   printf("\n");
DeleteNode(1);
   PrintNode();  
   printf("\n");
DeleteNode(2);
   PrintNode();  
   printf("\n");
DeleteNode(3);
   PrintNode();  
   printf("\n");
  return 0;
}















