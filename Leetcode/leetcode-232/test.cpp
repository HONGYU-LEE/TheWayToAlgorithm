class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> pops;
    stack<int> pushs;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        pushs.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(pops.empty())
        {
            while(!pushs.empty())
            {
                pops.push(pushs.top());
                pushs.pop();
            }
        }

        int ret = pops.top();
        pops.pop();

        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(pops.empty())
        {
            while(!pushs.empty())
            {
                pops.push(pushs.top());
                pushs.pop();
            }
        }
        return pops.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushs.empty() && pops.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#define STACKSIZE 100
typedef int DataType;
typedef struct Stack
{
	DataType* data;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack;

typedef struct {
    Stack pops;;
    Stack pushs;
} MyQueue;

/** Initialize your data structure here. */
void ChackCapacity(Stack* ps)
{
	if (ps->top >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->data = (DataType*)realloc(ps->data, ps->capacity * sizeof(DataType));

	}
}
void StackInit(Stack* ps)
{
	ps->data = (DataType*)malloc(STACKSIZE * sizeof(DataType));
	ps->top = 0;
	ps->capacity = STACKSIZE;
}

// 入栈 
void StackPush(Stack* ps, DataType data)
{
	ChackCapacity(ps);
	ps->data[ps->top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	if (0 == ps->top)
		return;
	ps->top--;
}

// 获取栈顶元素 
DataType StackTop(Stack* ps)
{
	if (0 == ps->top)
		return (DataType)0;
	return ps->data[ps->top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->top;
}

// 检测栈是否为空，如果为空返回非零(1)，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->top == 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->pushs);
    StackInit(&q->pops);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushs, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(StackEmpty(&obj->pops))
    {
        while(!StackEmpty(&obj->pushs))
        {
            StackPush( &obj->pops, StackTop(&obj->pushs));
            StackPop(&obj->pushs);
        }
    }

    int ret = StackTop(&obj->pops);
    StackPop(&obj->pops);

    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int top;
    if(StackEmpty(&obj->pops))
    {
        while(!StackEmpty(&obj->pushs))
        {
            StackPush( &obj->pops, StackTop(&obj->pushs));
            StackPop(&obj->pushs);
        }
    }

    top = StackTop(&obj->pops);

    return top;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(StackEmpty(&obj->pops) && StackEmpty(&obj->pushs))
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->pushs);
    StackDestroy(&obj->pops);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
