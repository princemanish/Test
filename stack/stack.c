#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 6

struct stack
{
   int *arr;
   int top;
   int size;
};

int IsStackEmpty(struct stack *ptr)
{
   return (ptr->top == -1);
}

int IsStackFull(struct stack *ptr)
{
   return((ptr->top+1) == ptr->size);
}

void Push(struct stack *ptr, int data)
{
   if(IsStackFull(ptr))
   printf("Stack is full\n");
   else
   {
    ptr->top= ptr->top + 1;
    ptr->arr[ptr->top]=data;
   }
}
void StackPop(struct stack *ptr, int *data)
{
   if(IsStackEmpty(ptr))
    printf("Stack is Empty\n");
   else
   {
    *data = ptr->top;
     ptr->top = ptr->top -1;
   }
}
void StackPrint(struct stack *ptr)
{
   int i=0;
   for(i=ptr->top;i>=0;i--)
   printf("index is %d and data is %d\n",i,ptr->arr[i]);
}

void FreeStack(struct stack *ptr)
{
   free(ptr->arr);
   free(ptr);
}

int main()
{ 
   int data;
   struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
   ptr->size=STACK_SIZE;
   ptr->arr=(int*)malloc(ptr->size * sizeof(int));
   ptr->top=-1;
   StackPop(ptr,&data);
   Push(ptr,2); 
   Push(ptr,4); 
   Push(ptr,6);
   Push(ptr,8);
   Push(ptr,10);
   Push(ptr,12);
   Push(ptr,14);
   StackPrint(ptr); 
   StackPop(ptr,&data);
   StackPop(ptr,&data);
   StackPop(ptr,&data);
   StackPop(ptr,&data);
   StackPop(ptr,&data);
   StackPop(ptr,&data);
   StackPrint(ptr); 
   FreeStack(ptr);
  return 0;
}
