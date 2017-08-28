#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	int count;
	struct node *left;
	struct node *right;
} TreeNode, *pTreeNode;


pTreeNode createNode(int value);
void insertNode(pTreeNode tree, int value);
void printTreeInOrder(pTreeNode tree);
void deleteNode(pTreeNode tree, int value);


int my_random(int bound)
{
	return rand()%bound;
}



// generate random array with given size and range
int* generate_random_array(int size, int max)
{
	if (size < 1)
	{
		printf("size error\n");
		return NULL;
	}
	int *array = (int*)malloc(size*sizeof(int));
	int i;
	for(i = 0; i < size; i++)
	{
		array[i] = my_random(max);
	}
	return array;
}


pTreeNode createNode(int value)
{
	pTreeNode node;
	if ((node = (pTreeNode)malloc(sizeof(TreeNode))) == NULL)
	{
		printf("crate node error\n");
		return NULL;
	}

	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insertNode(pTreeNode tree, int value)
{
	pTreeNode node = createNode(value);
	pTreeNode pre = NULL;
	pTreeNode s = tree;
	while (s)
	{
		if (s->value == value)
		{
			free(node);
			return;
		}
		else if (value < s->value)
		{
			pre = s;
			s = s->left;
		}
		else
		{
			pre = s;
			s = s->right;
		}
	}

	if (value < pre->value)
	{
		pre->left = node;
	}
	else
	{
		pre->right = node;
	}

}


void printTreeInOrder(pTreeNode tree)
{
	if (tree != NULL)
	{
		printTreeInOrder(tree->left);
		printf("%d,", tree->value);
		printTreeInOrder(tree->right);
	}
}

pTreeNode searchTree(pTreeNode tree, int value)
{
	pTreeNode cur = tree;
	while(cur)
	{
		if(cur->value == value)
			return cur;
		else if(cur->value > value)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return NULL;
}


int main()
{
	pTreeNode tree = createNode(30);
	int i;
	for(i = 0;i<100;i++)
	{
		int temp = my_random(100);
		printf("insert node:%d\n", temp);
		insertNode(tree, temp);
	}

	printTreeInOrder(tree);
}
