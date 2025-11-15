#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 64

typedef struct info { // info/data
    int salary;
    char name[MAX_SIZE];
    char department[MAX_SIZE];
} info_t;

typedef struct worker { // node
    info_t infos;
    struct worker* next;
    struct worker* prev;
} worker_t;

typedef struct company { // list
    int size;
    worker_t* first;
    worker_t* last;
} company_t;

// Prototypen
company_t* newCompany();
worker_t* newWorker(info_t* infos);
company_t* insertHead(company_t* c, info_t* infos);
company_t* insertTail(company_t* c, info_t* infos);
worker_t* searchWorker(company_t* c, char* name);
company_t* fireWorker(company_t* c, char* name);
void showCompany(company_t c);

int main() {
    // Eine neue Firma erstellen
    company_t* myCompany = newCompany();

    // Mitarbeiter hinzufügen
    info_t employee1 = {50000, "John Doe", "Engineering"};
    info_t employee2 = {60000, "Jane Smith", "Marketing"};

    myCompany = insertHead(myCompany, &employee1);
    myCompany = insertTail(myCompany, &employee2);

    // Mitarbeiter suchen
    printf("Searching for employee Jane Smith...\n");
    worker_t* foundEmployee = searchWorker(myCompany, "Jane Smith");
    if (foundEmployee != NULL) {
        printf("Employee found: %s, Department: %s, Salary: %d\n", 
               foundEmployee->infos.name, 
               foundEmployee->infos.department, 
               foundEmployee->infos.salary);
    } else {
        printf("Employee not found.\n");
    }

    // Firma anzeigen
    showCompany(*myCompany);

    // Mitarbeiter entlassen
    myCompany = fireWorker(myCompany, "John Doe");

    // Firma erneut anzeigen
    showCompany(*myCompany);

    // Speicher freigeben
    // Hier müssen Sie den Speicher freigeben, um Speicherlecks zu vermeiden

    return 0;
}

company_t* newCompany() {
    company_t* c = malloc(sizeof(company_t));
    if (c == NULL) {
        printf("Allocation of new company failed!\n");
        return NULL;
    }

    c->first = NULL;
    c->last = NULL;
    c->size = 0;

    return c;
}

worker_t* newWorker(info_t* infos) {
    worker_t* nw = malloc(sizeof(worker_t));
    if (nw == NULL) {
        printf("Allocation of new worker failed!\n");
        return NULL;
    }

    // Setzen der Informationen des neuen Mitarbeiters
    nw->infos.salary = infos->salary;
    strcpy(nw->infos.name, infos->name);
    strcpy(nw->infos.department, infos->department);

    // Initialisierung von next und prev auf NULL
    nw->next = NULL;
    nw->prev = NULL;

    return nw;
}

company_t* insertHead(company_t* c, info_t* infos) {
    worker_t* nw = newWorker(infos);
    if (nw == NULL) {
        return c;
    }

    if (c->first == NULL) { // Liste ist leer
        c->first = nw;
        c->last = nw;
    } else {
        nw->next = c->first;
        c->first->prev = nw;
        c->first = nw;
    }
    c->size++;
    return c;
}

company_t* insertTail(company_t* c, info_t* infos) {
    worker_t* nw = newWorker(infos);
    if (nw == NULL) {
        return c;
    }

    if (c->first == NULL) { // Liste ist leer
        c->first = nw;
        c->last = nw;
    } else {
        nw->prev = c->last;
        c->last->next = nw;
        c->last = nw;
    }
    c->size++;
    return c;  
}

worker_t* searchWorker(company_t* c, char* name) {
    worker_t* currentWorker = c->first;

    // Durchlaufen der Mitarbeiterliste
    while (currentWorker != NULL) {
        // Vergleich des Namens des aktuellen Mitarbeiters mit dem gesuchten Namen
        if (strcmp(currentWorker->infos.name, name) == 0) {
            // Mitarbeiter mit dem gesuchten Namen gefunden
            return currentWorker;
        }
        // Bewegen zum nächsten Mitarbeiter
        currentWorker = currentWorker->next;
    }

    // Mitarbeiter mit dem gesuchten Namen wurde nicht gefunden
    return NULL;
}

company_t* fireWorker(company_t* c, char* name) {
    worker_t* toBeFired = searchWorker(c, name);
    if (toBeFired == NULL) {
        printf("Employee %s not found.\n", name);
        return c;
    }

    if (toBeFired == c->first && toBeFired == c->last) { // Einziger Mitarbeiter in der Liste
        c->first = NULL;
        c->last = NULL;
    } else if (toBeFired == c->first) { // Mitarbeiter ist am Anfang der Liste
        c->first = toBeFired->next;
        c->first->prev = NULL;
    } else if (toBeFired == c->last) { // Mitarbeiter ist am Ende der Liste
        c->last = toBeFired->prev;
        c->last->next = NULL;
    } else { // Mitarbeiter ist in der Mitte der Liste
        toBeFired->prev->next = toBeFired->next;
        toBeFired->next->prev = toBeFired->prev;
    }

    free(toBeFired); // Speicher des entlassenen Mitarbeiters freigeben
    c->size--;
    return c;
}

void showCompany(company_t c) {
    printf("Company Size: %d\n", c.size);
    printf("Workers:\n");
    worker_t* currentWorker = c.first;
    while (currentWorker != NULL) {
        printf("Name: %s, Department: %s, Salary: %d\n", 
               currentWorker->infos.name, 
               currentWorker->infos.department, 
               currentWorker->infos.salary);
        currentWorker = currentWorker->next;
    }
}
