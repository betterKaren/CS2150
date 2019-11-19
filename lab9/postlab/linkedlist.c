/*
* Yu Du, yd2am
* linkedlist.c
* 2019.11.19
*/

#include <stdio.h>
#include <stdlib.h>

/* build structs for list and listNode */
struct list {
	struct list_node *dummyHead;
};

struct list_node {
	struct list_node *next;
	int value;
};

int main() {
	int n;
	printf("Enter how many values to input: ");
	scanf("%d", &n);

	/* create a new linked list whose dummy head is null */
	struct list *myList = (struct list *)malloc(sizeof(struct list));
	myList->dummyHead = (struct list_node *)malloc(sizeof(struct list_node));
	myList->dummyHead->value = 0;		/* seems cannot = NULL here!!?? */
	myList->dummyHead->next = NULL;

	/* store the original dummyHead because will iterate */
	struct list_node *head = myList->dummyHead;

	/* put use inputs into the linked list */
	for(int i=1; i<=n; i++) {
		int val;
		printf("Enter value %d: ", i);
		scanf("%d", &val);

		struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
		node->value = val;
		/* store backward */
		node->next = head->next;
		head->next = node;
		/* do not free node!*/
	}

	/* print out, start with head->next */
	struct list_node *itr = head->next;
	for(int i=0; i<n; i++) {
		printf("%d\n", itr->value);
		itr = itr->next;
	}

	free(myList);
	/* It will free dummyHead as well ? */
	return 0;
}
