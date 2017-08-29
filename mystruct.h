#ifndef MY_STRUCT_H
#define MY_STRUCT_H

typedef struct node
{
	char *word;
	int count;
	struct node* left;
	struct node* right;

}*ptnode, tnode;

typedef struct flags
{
	unsigned int is_keyword : 1;
	unsigned int is_extern : 1;
	unsigned int is_static : 1;
}*pflags, flags_t;


ptnode
addtree(ptnode, char *);

void printtree(ptnode);

ptnode
talloc(void);

char *
my_strdup(char *);

#endif