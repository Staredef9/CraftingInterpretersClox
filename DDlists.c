#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ddlist{
	char		*string;
	struct ddlist	*prev;
	struct ddlist	*next;
}ddlist;

int	ddlist_insert(char *string, ddlist **list)
{
	ddlist *add = malloc(sizeof(ddlist));
	ddlist *head = *list;
	if (!add){
		printf("error in alloc new node\n");
		return -1;
	}
	int len = strlen(string);
	add->string = malloc(sizeof(char)*len+1);
	if(!add->string)
	{
		printf("error in alloc new string\n");
		return -1;
	}
	strcpy(add->string, string);
	if (head){
		add->prev = NULL;
		add->next = head; 	
		head->prev = add;
		*list = add;
	} else{
		add->next = NULL;
		add->prev = NULL;
		*list = add;
	}
	return 0;
}

int	ddlist_delete(char *string, ddlist **list)
{
	ddlist *head = *list;
	while(head)
	{
		if (strcmp(head->string, string) == 0)
		{
			if(head->prev){
				head->prev->next = head->next;
			} else{
				*list = head->next;
			}
			
			if (head->next) {
				head->next->prev = head->prev;
			}

			free(head->string);	
			free(head);
			return 0;
		}
		head = head->next;
	}
	return 1;
}

ddlist	*ddlist_retrieve(char *string, ddlist **list)
{
	ddlist *head = *list;
	while(head)
	{
		if (strcmp(head->string, string) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void	ddlist_print(ddlist *list)
{
	ddlist *head = list;
	while (head)
	{
		printf("%s -> ", head->string);
		head = head->next;
	}
	printf("NULL\n");
}

void	ddlist_rev_print(ddlist *list)
{
	ddlist *head = list;
	while (head->next)
	{
		head = head->next;
	}
	while(head)
	{
		printf("%s -> ", head->string);
		head = head->prev;
	}
	printf("NULL\n");
}

int	ddlist_clean(ddlist **list)
{
	return 1;
}

int main(){
	printf("hello lists!\n");

	ddlist *mylst = NULL;
	ddlist_insert("ziopera", &mylst);	
	ddlist_insert("ziomela", &mylst);	
	ddlist_insert("ziofa", &mylst);	
	ddlist_print(mylst);	
	
	printf("Retrieving item: %s\n", ddlist_retrieve("ziopera",&mylst)->string);
	
	ddlist_delete("ziofa", &mylst);	
	ddlist_rev_print(mylst);
	ddlist_delete("ziopera", &mylst);	
	ddlist_delete("ziomela", &mylst);	
		
	return 0;
}
