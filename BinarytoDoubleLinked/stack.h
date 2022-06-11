#pragma once
#define STACK_SIZE 100
typedef bnode_t* Stype;  //int
Stype STACK_EMPTY = NULL; //garbage value for string

typedef struct
{
	Stype Data[STACK_SIZE];
	int top;
}stack_t; //initialization


void InitializeStack(stack_t* s)
{

	s->top = -1;
}

int isEmptyStack(stack_t* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	return 0;
}

int isFullStack(stack_t* s)
{

	if (s->top == STACK_SIZE - 1)
	{
		return 1;
	}

	return 0;
}

void Push(stack_t* s, Stype item)
{

	if (isFullStack(s))
	{
		printf("Error, stack is full!");

	}
	else
	{
		(s->top)++;  //incrementing the stack
		s->Data[s->top]=item;
			
	}

}

Stype pop(stack_t* s)  //pop for string
{
	Stype item;
	if (isEmptyStack(s))
	{
		printf("Error, stack is Empty");
		item= STACK_EMPTY;
		 //garbage value set 
	}
	else
	{
		item= s->Data[s->top];
		(s->top)--;//decrementing the stack
	}

	return item;

}
