#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr *,int);
int deletefromfirst(nodeptr *);
void displaylist(nodeptr);

int main()
{
	nodeptr list;
	list=NULL;
	insertatfirst(&list,5);
	insertatfirst(&list,6);
	printf("ITEM DELETED: %d\n",deletefromfirst(&list));
	printf("ITEM DELETED: %d\n",deletefromfirst(&list));
	printf("ITEM DELETED: %d\n",deletefromfirst(&list));
	printf("ITEM DELETED: %d\n",deletefromfirst(&list));
	printf("ITEM DELETED: %d\n",deletefromfirst(&list));
	displaylist(list);
}

nodeptr getnode()
{
return (nodeptr) malloc(sizeof(struct node));	
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr *p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	while(p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->next;
	}
}

int deletefromfirst(nodeptr *p)
{
int x;	
nodeptr q;
q=*p;
if(q==NULL)
{
	printf("\n underflow!!!!!!!!!\n");
	exit(1);
}
else
{
x=q->info;
*p=q->next;
free(q);
return (x);
}
}

