#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
	int data;
	struct sNode* next;
}Node, *pNode;

Node* Merge (Node* head1, Node* head2)
{
	/* parameters check */
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	/* decide the head */
	Node* head, *curr, *curr1, *curr2;
	if (head1->data <= head2->data)
	{
		head = head1;
		curr1 = head1->next;
		curr2 = head2;
	}
	else
	{
		head = head2;
		curr1 = head1;
		curr2 = head2->next;
	}
	curr = head;

	/* iter over two lists */
	while(curr1 != NULL && curr2 != NULL)
	{
		if(curr1->data <= curr2->data)
		{
			curr->next = curr1;
			curr1 = curr1->next;
		}
		else
		{
			curr->next = curr2;
			curr2 = curr2->next;
		}
		curr = curr->next;
	}

	/* handle the rest */
	if(curr1 == NULL)
		curr->next = curr2;
	else
		curr->next = curr1;

	return head;
}
void print(Node* head)
{
	Node* curr = head;
	while(curr != NULL)
	{
		printf("%d->",curr->data);
		curr = curr->next;
	}
	printf("\n");

}

Node* newNode(int data)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}
void insert(Node* head, int data)
{
	Node* node = newNode(data);
	Node* curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = node;
}
int main()
{
	Node* head1 = newNode(2);
	insert(head1, 4);
	insert(head1, 9);
	insert(head1, 11);
	print(head1);
	Node* head2 = newNode(5);
	insert(head2, 6);
	insert(head2, 7);
	insert(head2, 9);
	insert(head2, 12);
	insert(head2, 13);
	print(head2);
	Node* head3 = NULL;
	Node* merged = Merge(head1, head2);
	print(merged);
	return 0;
}
