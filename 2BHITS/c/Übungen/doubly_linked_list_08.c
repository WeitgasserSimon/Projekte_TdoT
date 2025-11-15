/**
 * @file:    doubly_linked_list_08.c
 * @brief    A doubly linked list
 * @author   Lothar Schäfer
 * @date     2023-11-12
 * @details  The seventh refinement includes
 *           - a function to delete a node in the list
 *
 * powershell: cls; gcc doubly_linked_list_08.c -o run.exe; .\run.exe
 * bash:       clear; gcc doubly_linked_list_08.c -o run.out; .\run.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORWARD  1
#define BACKWARD 0

// Definition of the data type for a node
typedef struct node
{
	char* value;
	struct node* prev;
	struct node* next;
} node_t;

// Definition of the data type for a list
typedef struct list
{
	int size;
	node_t* first;
	node_t* last;
} list_t;

list_t* createList();
node_t* createNode(char* value);
void insertAtBeginning(list_t** list, char* value);
void insertAtEnd(list_t** list, char* value);
node_t* searchNode(list_t* list, char* value);
void deleteNode(list_t* list, char* value);
void printList(list_t* list, int direction);

int main()
{
	list_t* list = NULL;
	node_t* found = NULL;

	// Assigning the payload
	insertAtEnd(&list, "Det");
	insertAtEnd(&list, "Berti");
	insertAtEnd(&list, "Conni");
	insertAtEnd(&list, "Anton");
	insertAtEnd(&list, "Edi");

	// Print the doubly linked list
	printList(list, FORWARD);
	printList(list, BACKWARD);

	// Search the node Bert
	found = searchNode(list, "Bert");
	if (found == NULL)
	{
		printf("Node Bert not found!\n");
	} else
	{
		printf("Node Bert is in the list.\n");
	}

	// Search the node Berti
	found = searchNode(list, "Berti");
	if (found == NULL)
	{
		printf("Node Berti not found!\n");
	} else
	{
		printf("Node Berti is in the list.\n");
	}

	// Delete the node Berti
	deleteNode(list, "Berti");
	deleteNode(list, "Edi");
	deleteNode(list, "Anton");
	deleteNode(list, "Conni");
	deleteNode(list, "Det");

	// Print the doubly linked list
	printList(list, FORWARD);

	return EXIT_SUCCESS;
}

// A function to create a list.
// The function returns a list pointer.
list_t* createList()
{
	list_t* newList = malloc(sizeof(list_t));
	if (NULL != newList)
	{
		newList->size = 0;
		newList->first = NULL;
		newList->last = NULL;
	}
	return newList;
}

// A function to create a node.
// The function requires a text and returns a node pointer.
node_t* createNode(char* value)
{
	node_t* newNode = malloc(sizeof(node_t));
	if (NULL != newNode)
	{
		newNode->value = value;
		newNode->prev = NULL;
		newNode->next = NULL;
	}
	return newNode;
}

// A function to insert a node at the beginning of the list.
// The function requires a double pointer to the list and a value to insert.
void insertAtBeginning(list_t** list, char* value)
{
	// The list does not exist
	if (*list == NULL)
	{
		*list = createList();
		if (*list == NULL)
		{
			printf("Could not create list!");
			return;
		}
	}

	// Create a new node
	node_t* newNode = createNode(value);
	if (newNode == NULL)
	{
		printf("Could not create node!");
		return;
	}

	// The list is not empty
	if ((*list)->first != NULL)
	{
		(*list)->first->prev = newNode;
		newNode->next = (*list)->first;
		(*list)->first = newNode;
	} else
	{
		(*list)->first = newNode;
		(*list)->last = newNode;
	}
}

// A function to insert a node at the end of the list.
// The function requires a double pointer to the list and a value to insert.
void insertAtEnd(list_t** list, char* value)
{
	// The list does not exist
	if (*list == NULL)
	{
		*list = createList();
		if (*list == NULL)
		{
			printf("Could not create list!");
			return;
		}
	}

	// Create a new node
	node_t* newNode = createNode(value);
	if (newNode == NULL)
	{
		printf("Could not create node!");
		return;
	}

	// The list is not empty
	if ((*list)->first != NULL)
	{
		(*list)->last->next = newNode;
		newNode->prev = (*list)->last;
		(*list)->last = newNode;
	} else
	{
		(*list)->first = newNode;
		(*list)->last = newNode;
	}
}

// A function to search for a node by its value.
// The function requires a text and returns a node pointer.
node_t* searchNode(list_t* list, char* value)
{
	node_t* current = NULL;
	if (list != NULL)	
	{
		current = list->first;
		while (current != NULL)
		{
			if (strcmp(current->value, value) == 0) {
				break;
			}
			current = current->next;
		}
	}
	return current;
}

// A function to delete a node from the list.
// The function requires the pointer to the list and a value to delete.
void deleteNode(list_t* list, char* value)
{
	if (list != NULL)
	{
		node_t* node = searchNode(list, value);
		if (node != NULL)
		{
			if (node->prev == NULL && node->next == NULL)
			{
				// The node is the only node in the list (no predecessor, no successor)
				list->first = NULL;
				list->last = NULL;
			} else
			if (node->prev == NULL)
			{
				// The node is the first node in the list (no predecessor)
				node->next->prev == NULL;
				list->first = node->next;
			} else
			if (node->next == NULL)
			{
				// The node is the last node in the list (no successor)
				node->prev->next = NULL;
				list->last = node->prev;
			} else
			{
				// The node is a node between the first and the last node in the list
				node->prev->next = node->next;
				node->next->prev = node->prev;
			}
			free(node);
		}
	}
}

// A function to print the doubly linked list.
// The function requires the pointer to the list and the direction.
void printList(list_t* list, int direction)
{
	if (list != NULL)
	{
		if (direction == BACKWARD)
		{
			node_t* current = list->last;
			printf("NULL <- ");
			while (current != NULL)
			{
				printf("%s", current->value);
				if (current->prev != NULL) {
					printf(" <-> ");
				}
				current = current->prev;
			}
			printf(" -> NULL\n");
		} else
		{
			node_t* current = list->first;
			printf("NULL <- ");
			while (current != NULL)
			{
				printf("%s", current->value);
				if (current->next != NULL)
				{
					printf(" <-> ");
				}
				current = current->next;
			}
			printf(" -> NULL\n");
		}
	}
}
