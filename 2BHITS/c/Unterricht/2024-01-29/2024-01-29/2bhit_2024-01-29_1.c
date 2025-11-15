/**
 * Datentypen
 * Datenstrukturen
 * Objekte
 *
 * Erstellen eines Listenobjekts
*/

struct node {
	int data;
	struct node* next;
};

typedef struct node node_t;

struct list {
	node_t* first;
	int length;
	struct node*(*createNode)(int);
	void(*append)(struct list*, int);
	void(*print)(struct list*);
	int(*getLength)(struct list*);
};

typedef struct list list_o;