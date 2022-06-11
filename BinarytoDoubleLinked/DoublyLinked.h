#pragma once
typedef int LType;
typedef struct node_s
{

	LType data;
	node_s* next;
	node_s* prev;
}node_t;

node_t* getNode(void)
{
	node_t* hp;
	hp = (node_t*)malloc(sizeof(node_t));
	hp->next = NULL;
	hp->prev = NULL;
	return hp;
}

node_t* AddBeginning(node_t* hp, LType data)
{
	node_t* tp;
	tp = getNode();
	tp->data = data;
	tp->next = hp;
	return tp;
}
void AddAfter(node_t* hp, LType data)
{
	node_t* tp;
	tp = getNode();
	tp->next = hp->next;
	hp->next = tp;
	tp->prev = hp;
	tp->data = data;

}