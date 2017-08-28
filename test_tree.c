/*
* @Author: root
* @Date:   2017-03-31 15:24:37
* @Last Modified by:   root
* @Last Modified time: 2017-03-31 18:14:55
*/

#include <stdlib.h>
#include "include/mylib.h"
#include "include/mystruct.h"

#ifdef MY_STRUCT
int main() {

	ptnode p;
	p = addtree(p, "i");
	p = addtree(p, "am");
	p = addtree(p, "good");
	p = addtree(p, "i");
	p = addtree(p, "bad");
	p = addtree(p, "am");
	p = addtree(p, "he");
	p = addtree(p, "char");
	p = addtree(p, "single");
	p = addtree(p, "man");
	printtree(p);
	return 0;
}
#endif

ptnode
addtree(ptnode p, char *w){
	int cond;
	if (p == NULL)
	{
		p = talloc();
		p->word = my_strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = my_strcmp(p->word, w)) == 0)
		p->count++;
	else if (cond > 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void printtree(ptnode p){
	if (p != NULL)
	{
		printtree(p->left);
		printf("word: %s, count: %d\n", p->word, p->count);
		printtree(p->right);
	}
}

ptnode
talloc(void){
	return (ptnode)malloc(sizeof(tnode));
}

char *
my_strdup(char *s){
	char *p;
	p = (char *)malloc(strlen(s)+1);
	if (p != NULL)
		my_strcpy(p, s);
	return p;
}