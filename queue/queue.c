#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 6

struct queue
{
   int *arr;
   int front, rear;
   int queue_size;
};

int IsQueueEmpty(struct queue *ptr)
{
   return (ptr->front==-1);
   
}

int IsQueueFull(struct queue *ptr)
{
   //printf("ptr->rear is %d\n",ptr->rear);
   //printf("ptr->front is %d\n",ptr->front);
   //printf("ptr->rear+1 % /ptr->queue_size  is %d\n",(ptr->rear+1) % (ptr->queue_size));
   return ((ptr->rear+1) % (ptr->queue_size) == ptr->front);
}

void print_queue(struct queue *ptr)
{
   int i=0;
   for(i=0;i <= ptr->rear; i++)
   {
    printf("queue index is %d and data stored is %d\n",i,ptr->arr[i]);
   }
}


void enqueue(struct queue *ptr, int data)
{
   if(IsQueueFull(ptr))
   {
    printf("Queue is full\n");
   }
   else
   {
   ptr->rear=(ptr->rear+1) % (ptr->queue_size);
   ptr->arr[ptr->rear]=data;
   if(ptr->front==-1)
   {
    ptr->front=ptr->rear;
   }
   }
}


void Dequeue(struct queue *ptr,int *data)
{
//   printf("ptr->front is %d\n",ptr->front);
   if(IsQueueEmpty(ptr))
   {
    printf("Queue is empty\n");
   }
   else
   {
   *data=ptr->arr[ptr->front];
   ptr->front=ptr->front + 1 % ptr->queue_size;
   }
}

void QueueDelete(struct queue *ptr)
{
   printf("Deleting Queue\n");
   free(ptr->arr);
   free(ptr);
}
int main()
{
   int data=0;
   struct queue *ptr=(struct queue *) malloc(sizeof(struct queue));
   ptr->queue_size=MAX_SIZE;
   ptr->front=ptr->rear= -1;
   ptr->arr=(int *) malloc(ptr->queue_size * sizeof(int));
   Dequeue(ptr, &data);
   enqueue(ptr, 2);
   enqueue(ptr, 4);
   enqueue(ptr, 6);
   enqueue(ptr, 8);
   enqueue(ptr, 10);
   enqueue(ptr, 12);
   enqueue(ptr, 14);
   print_queue(ptr);
   Dequeue(ptr, &data);
   printf("dequeued data is %d\n",data);
   Dequeue(ptr, &data);
   printf("dequeued data is %d\n",data);
   Dequeue(ptr, &data);
   printf("dequeued data is %d\n",data);
   QueueDelete(ptr);
return 0;
}
