#pragma once
typedef int BType;
typedef struct bnode_s
{
	BType data;
	bnode_s* right;
	bnode_s* left;

}bnode_t;

bnode_t* getBinaryNode(BType data)
{
	bnode_t* root;
	root = (bnode_t*)malloc(sizeof(bnode_t));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;

}