#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Binary.h"
#include "DoublyLinked.h"
#include "stack.h"
#include "queue_int.h"
#define MAX 7
//spiral order (two stacks) first one left to right, second one right to left

bnode_t* createBinaryTree(BType data[])
{
	int counter = 0;
	int i;
	queue_t q;
	InitializeQ(&q);
	bnode_t* root=getBinaryNode(data[counter++]);
	i = root->data;
	bnode_t* temp = root;
	while (counter < MAX)
	{
		if (data[counter] == 2 * i)
		{
			temp->left = getBinaryNode(data[counter++]);
		}
		else if (data[counter] == 2 * i + 1)
		{
			temp->right = getBinaryNode(data[counter++]);

		}

		if (temp->left != NULL && temp->right != NULL)
		{
			insert(&q, temp->left);
			insert(&q, temp->right);
			temp = remove(&q);
			i = temp->data;

		}

	}

	return root;

}

void binaryTreetoDoubleLinkedList(bnode_t* root)  //using spiral order traversal with two stacks!
{
	//OMG I DID IT!!!! I FREAKING MADE THE SPIRAL ORDER TRAVERSAL (ITERATIVELY!))
	stack_t s1;
	stack_t s2;
	InitializeStack(&s1);
	InitializeStack(&s2);

	Push(&s1, root); //pushes the root
	node_t* doublyLinked = NULL;
	doublyLinked= AddBeginning(doublyLinked, root->data);
	node_t* tempLinked = doublyLinked;
	while (!isEmptyStack(&s1) || !isEmptyStack(&s2))  //if either of them is full!
	{

		while (!isEmptyStack(&s1))
		{
			bnode_t* temp = pop(&s1);
			if (doublyLinked->data != temp->data)
			{
				AddAfter(tempLinked, temp->data);
				tempLinked = tempLinked->next;
			}
			//printf("%d -> ", temp->data);
			if (temp->right != NULL && temp->left != NULL && temp!=NULL)
			{
				Push(&s2, temp->right);
				Push(&s2, temp->left);
			

			}
		

		}

		while (!isEmptyStack(&s2))
		{
			bnode_t* temp2 = pop(&s2);
			//printf("%d -> ", temp2->data);
			AddAfter(tempLinked, temp2->data);
			tempLinked = tempLinked->next;
			if (temp2->right != NULL && temp2->left != NULL && temp2!=NULL)
			{
				Push(&s1, temp2->left);
				Push(&s1, temp2->right);

			}
		
		}


	}

	tempLinked = doublyLinked;
	while (tempLinked != NULL)
	{
		printf("%d -> ", tempLinked->data);
		tempLinked = tempLinked->next;
	}
	printf("NULL\n");
	tempLinked = doublyLinked;
	while (tempLinked->next != NULL)
	{
		tempLinked = tempLinked->next;
	}
	while (tempLinked!= NULL)
	{
		printf("%d - >", tempLinked->data);
		tempLinked = tempLinked->prev;
	}
	printf("NULL\n");
}

void PreOrder(bnode_t* root)
{
	if (root != NULL)
	{
		printf("%d - >", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}


int main(void)
{
	printf("Enter 7 nums: ");
	BType data[MAX];
	for (int i = 0; i < MAX; i++)
		scanf("%d", &data[i]);
	bnode_t* root = createBinaryTree(data);
	PreOrder(root);
	printf("NULL\n");
	binaryTreetoDoubleLinkedList(root);
    
	return 0;
}