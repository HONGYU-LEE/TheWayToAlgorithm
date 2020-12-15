typedef int DataType;
typedef struct {
    DataType* queue;
    int front;
    int rear;
    int length;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->queue = (int*)malloc((k + 1) * sizeof(int));
    cq->front = 0;
    cq->rear = 0;
    cq->length = k + 1;
    return cq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if((obj->rear + 1) % obj->length == obj->front)
        return false;
    obj->queue[obj->rear++] = value;
    if(obj->rear == obj->length)
        obj->rear = 0;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return false;;
    
    ++obj->front;
    if(obj->front == obj->length)
        obj->front == 0;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return -1;
    else    
        return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return -1;
    else if(obj->rear == 0)
        return obj->queue[obj->length - 1];
    else
        return obj->queue[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->rear == obj->front)
        return true;
    else    
        return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->rear + 1) % obj->length == obj->front)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    obj->queue = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
