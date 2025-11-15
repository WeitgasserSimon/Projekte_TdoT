/**
 * @brief	Eine einfach verkettete Liste
 * @author  Simon Weitgasser 
 * @date	2023-10-23
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 // Definition des Listenelements (Knoten)
 // Eine Liste besteht aus mehreren Listenelementen
 struct node {
 	char* payload;
 	struct node* next;
 };
void insertTail(struct node* head, char* name); // Am Ende dazufügen
void printList(struct node* current); // Liste ausgeben

 int main(){
 	// Erzeugen einer Liste bestehend aus
 	//einzelnen Knoten
 	struct node n1, n2, n3, n4, n5;
 	struct node* head = NULL;
 	
 	
 	n1.payload = "Detlev";
 	n2.payload = "Berti";
 	n3.payload = "Conny";
 	n4.payload = "Anton";
 	n5.payload = "Edi";
 	
 	head = &n4; 
 	n4.next = &n2;
 	n2.next = &n3;
 	n3.next = &n1;
 	n1.next = &n5;
 	n5.next = NULL;	// WICHTIG!	
 	
 	insertTail(head, "Fritz");
 	printList(head);
 	

	return EXIT_SUCCESS;
 }
 void insertTail(struct node* head, char* name){
 	// Neues Listenelement erzeugen
 	struct node *tail = malloc(sizeof(struct node));
	strcpy(tail->payload, name);
	tail->next = NULL; //WICHTIG
 	// Ist die Liste leer?
 	if (NULL == head){
 		head = tail;
 		return;
	 }
	 // Das letzte Element bestimmen
	 struct node* current = head;
 		while (current->next != NULL) {
			current = current->next;
	}
	// Das Listenelement an der letzten Stelle hinzufügen
	current->next = tail;
 }
 void printList(struct node* current){	 	
	while (current != NULL) {
		printf("%s -> ", current->payload);
		current = current->next;
	}
 	printf("NULL\n");
 }
 
