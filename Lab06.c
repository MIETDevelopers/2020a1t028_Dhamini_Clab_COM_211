 #include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for INT_MIN
struct Queue{
	int *data;                //the array which has items
	int maxCapacity;         // maximum capacity of the queue
	int front;              //index of the front item
	int rear;              //index of the rear item
};

int noOfItems(struct Queue *queue){     //function for no of items
	if (queue->rear == -1 && queue->front==-1) //checking queue is empty or not
	{
		return 0;
	} else if (queue->rear >= queue->front){
		return (queue->rear - queue->front)+1; //it will tell no of items
	} else{
		return (((queue->maxCapacity - 1) - queue->front) + 1) + (queue->rear + 1);
	}
}

int isFull(struct Queue *queue)
{
	if (noOfItems(queue) == queue->maxCapacity){ //if queue is full it returns 1 else 0
		return 1;
	} else{
		return 0;
	}
}

int enQueue(struct Queue *queue, int item){  //item is for adding numbers
	printf("enQueue %d:\n", item);
	if (isFull(queue) == 0){           //it will check queue is full or not
		if (noOfItems(queue) == 0)    //queue is empty
		{
			// by default front = -1
			// we have to make it zero as we are going to add an element

			queue->front = 0;
		}
		queue->rear = (queue->rear + 1)%(queue->maxCapacity);  // incrementing the rear circularly
		queue->data[queue->rear] = item; //adding item at rear
		return 1;
	} else{
		return 0;
	}
}

int deQueue(struct Queue *queue)
{
	printf("\n\tInside the dequeue function\n\n");
	if (noOfItems(queue) != 0){      
		// creating a variable temp
		int temp = queue->data[queue->front];  //temp = front
		if (queue->front == queue->rear) // if there is only one element inside queue
		{
			queue->front = -1;
			queue->rear	 = -1;
		} else{
			queue->front = (queue->front + 1)%(queue->maxCapacity);  //front is incremented in a circular way
		}
		// return the variable (temp)
		return temp;
	} else{
		return INT_MIN; //when there is no elemnt inside queue
	}
}

void printQueueDetails(struct Queue *queue){
    printf("Number of elements:%d\n", noOfItems(queue));
	printf("maxCapacity=%d  front=%d  rear=%d \n", queue->maxCapacity, queue->front, queue->rear);
}

void printQueue(struct Queue *queue){
	int i;
	printf("queue: ");
	i = queue->front;  //i equal to front
	if (noOfItems(queue) != 0)
	{
		do
	    {
	        printf("data[%d]= %d ", i, queue->data[i]);
	        i = (i + 1) % (queue->maxCapacity);
	    } while (i != (queue->rear + 1) % queue->maxCapacity);
		printf("\n");
	}else{
		printf("The queue is empty\n\n");
	}
}

int main()
{
	int value, choice, var;
	struct Queue queueA;
	queueA.front=-1;     
	queueA.rear=-1;     
	printf("enter the maximum size of the queue:\n");
	scanf("%d", &queueA.maxCapacity);
	queueA.data = (int *)malloc(queueA.maxCapacity*sizeof(int));   //memory allocation for the queue
	do
	{
	printf("enter the operation you want to perform:\n");
	printf("1. enQueue\n");
	printf("2. deQueue\n");
	printf("3. printQueue\n");
	printf("4. exit\n");
	scanf("%d", &choice);
	switch(choice)
    {
		case 1:
		printf("enter the number you want to enqueue:\n");
		scanf("%d", &var);
		enQueue(&queueA, var);
		printf("The number %d enQueued successfully\n\n");
		break;
		case 2:
		value = deQueue(&queueA);
	    if (value != INT_MIN)  
	    {
		  printf("\n%d is removed\n\n", value);
	    } else{
		  printf("Queue was empty and could not remove any item!\n\n");
	    }
	    break;
	    case 3:
	    printQueueDetails(&queueA);
	    printQueue(&queueA);
	    break;
	    case 4:
	    printf("Exiting the program\n");
	    exit(0);
	    break;
	    default:
	    printf("enter the correct option\n\n");
	    break;
   }
   }while(1);

	return 0;
}

