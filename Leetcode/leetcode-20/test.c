#define STACKSIZE 10000
typedef char DataType;
typedef struct Stack
{
	DataType* data;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack;

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
    if(0 == ps->top)
        return;
	ps->top--;
}

// 获取栈顶元素 
DataType StackTop(Stack* ps)
{
    if(0 == ps->top)
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


bool isValid(char * s){
    Stack s1;
    StackInit(&s1);
    int i, j;
    char symbol[3][2] = {
        {'(',')'},
        {'{','}'},
        {'[',']'}
    };

    while(*s)
    {
        for(i = 0; i < 3; i++)
        {
            if(*s == symbol[i][0])
            {
                StackPush(&s1, *s);
                s++;
                break;
            }
        }

        if(i == 3)
        {
            char top = StackTop(&s1);
            for(j = 0; j < 3; j++)
            {
                if(*s == symbol[j][1])
                {
                    if(top == symbol[j][0])
                    {
                        s++;
                        StackPop(&s1);
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    if(StackEmpty(&s1))
        return true;
    else
        return false;

    
}
