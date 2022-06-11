#define QUEUE_SIZE 20
typedef bnode_t* QType;
QType QUEUE_EMPTY = NULL;

typedef struct
{
	int front, rear, counter;
	QType Data[QUEUE_SIZE];

}queue_t;

void InitializeQ(queue_t * q)
{
	q->front = 0;
	q->rear = -1;
	q->counter = 0;

}

int isEmptyQ(queue_t* q)
{

	if (q->counter == 0)
	{
		return 1;
	}
	return 0;
}

int isFullQ(queue_t* q)
{


	if (q->counter == QUEUE_SIZE)
	{
		return 1;
	}

	return 0;
}

void insert(queue_t* q, QType item)
{
	if (isFullQ(q))
	{
		printf("\nQUEUE IS FULL!\n");
	}
	else
	{
		q->rear = (q->rear + 1) % QUEUE_SIZE;
		q->Data[q->rear] = item;
		q->counter++;


	}

}
QType remove(queue_t* q)
{
	QType item;
	if (isEmptyQ(q))
	{
		printf("\nQUEUE IS EMPTY!\n");
		item = QUEUE_EMPTY;

	}
	else
	{
		item = q->Data[q->front];
		q->front=(q->front+1) % QUEUE_SIZE;
		q->counter--;



	}
	return item;
}