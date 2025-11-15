/*
*   Datentypen
*   Datenstrukturen
*   Objekte
*   Erstellen eines Listenobjekts
*/
struct node {
    int data;
    struct node* next;
}typedef node_t;    // eif andere schreibweise

struct list {
    node_t* first;
    int length;
    struct node*(*createNode)(int data);    // Bei allen vier wird nur der datentyp benötigt, variablen name ist egal
    void(*append)(struct list*, int data);
    void(*print)(struct list*);
    int(*getLength)(struct list*);
};

typedef struct list list_o;