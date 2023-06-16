#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int length = 0;
	while(head){
		length++;
		head = head->next;
	}
	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
		int len = length(head);
		char* str = malloc(len + 1);
		int i = 0;
		while(head){
			str[i++] = head->letter;
			head = head->next;
		}
		str[i] = '\0';
		return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* insertChar = malloc(sizeof(node));
	insertChar->letter =c;
	insertChar->next = NULL;
	if(*pHead == NULL){
		*pHead = insertChar;
		return;
	}
	node* curr = *pHead;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = insertChar;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* inserted = *pHead;
	while(inserted){
		node* next = inserted->next;
		free(inserted);
		inserted = next;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
