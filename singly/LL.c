#include<stdio.h>
#include<stdlib.h>

struct LL
{
   struct LL *next;
   int data;
};

struct LL *start=NULL;

void AddNode(int data,int pos)
{
   int k=1;
   struct LL *p,*q;
   struct LL *tmp=(struct LL*)malloc(sizeof(struct LL));
   tmp->next=NULL;
   tmp->data=data;
   p=start;
   if(pos == 1)
   {
    printf("Adding at first position  in LL\n");
    tmp->next=p;
    start=tmp;
   }
   else
   {
    while(p != NULL && k < pos)
     { 
       k++;
       q=p;
       p=p->next;
     }
    q->next=tmp;
    tmp->next=p;
   }
}

void DeleteNode(int pos)
{
   struct LL *p, *q;
   int k=1;   
   p=start;
   if(p == NULL)
   {
    printf("LL is empty\n");
   }  
   else if(pos ==1)
   {
    start = p->next;
    free(p);
   }
   else
   {
    while(p != NULL && k < pos)
     {
       k++;
       q=p;
       p=p->next;
     }
     q->next=p->next;
     free(p);
   }
}
  
void PrintLl()
{
   struct LL *ptr=start;
   while(ptr != NULL)
    {
      printf("%d->",ptr->data);
      ptr=ptr->next;
    }
}
   
int main()
{
   void (*fun_ptr)(int,int)=AddNode;
   void (*fun_ptr1)(int)=DeleteNode;
   (*fun_ptr)(2,1);
   (*fun_ptr)(4,2);
   (*fun_ptr)(6,3);
   (*fun_ptr)(8,4);
   (*fun_ptr)(10,5);
   (*fun_ptr)(12,6);
   (*fun_ptr)(7,4);
   PrintLl();
   printf("\n");
   (*fun_ptr1)(1);
   PrintLl();
   printf("\n");
   (*fun_ptr1)(2);
   (*fun_ptr1)(5);
   PrintLl();
   printf("\n");

return 0;
}
