#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
};
struct node *start=NULL;

void traverse()
{
    if(start==NULL)
    {
        printf("\nList is empty\n");
    }
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("--->=%d",temp->data);
        temp=temp->next;
    }
}

void insertatbeg()
{

int data;
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the element to be inserted:\n");
scanf("%d",&data);
temp->data=data;
temp->prev=NULL;
temp->next=start;
start=temp;
printf("\n%d is inserted\n",data);
}

void insertatend()
{
    int data;
    struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->data = data;
	temp->next = NULL;
	trav = start;

	if(start==NULL)
	{
        start=temp;
	}

	else
    {
        while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
    }
}
void insertatpos()
{
    int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;

	printf("\nEnter position : ");
	scanf("%d", &pos);
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->data = data;
	temp = start;

	if (start == NULL)
    {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else if (pos == 1)
    {
		newnode->next = start;
		newnode->next->prev = newnode;
		newnode->prev = NULL;
		start = newnode;
	}
	else
    {
		while (i < pos - 1)
		{
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

void deleteatbeg()
{
    struct node *temp;
    if(start==NULL)
    {
         printf("\nlist is empty\n");
    }
    else
    {
        temp=start;
        start=start->next;
        if(start!=NULL)
        {
            start->prev=NULL;
        }
        free(temp);
    }
}

void deleteatend()
{
    struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

void deleteatpos()
{
    int pos,i=1;
    struct node *temp,*position;
    temp=start;
    if(start==NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter the position:");
        scanf("%d",&pos);
        if(pos==1)
        {
            position=start;
            start=start->next;
            if(start!=NULL)
            {
                start->prev=NULL;
            }
            free(position);
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }

            position=temp->next;
            if(position->next!=NULL)
                position->next->prev=temp;
            temp->next=position->next;
            free(position);
        }
    }
}


void traverse();
void insertatbeg();
void insertatend();
void insertatpos();
void deleteatbeg();
void deleteatend();
void deleteatpos();


int main()
{

    int choice;
    printf("\n---Doubly linked List---\n");
    while(1)
    {
        printf("\n1. Traverse\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Pos\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Pos\n8.  Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            traverse();
            break;

        case 2:
            insertatbeg();
            break;

        case 3:
            insertatend();
            break;

        case 4:
            insertatpos();
            break;

        case 5:
            deleteatbeg();
            break;

        case 6:
            deleteatend();
            break;

        case 7:
            deleteatpos();
            break;


        case 8:
            exit(0);


        default:
            printf("\nWrong Choice\n");

        }
    }
}
