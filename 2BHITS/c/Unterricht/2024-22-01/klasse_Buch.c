#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 64

struct book{
    // Attribute
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    int number;

    // Setter-Methoden
    void (*setObjectAuthor)(struct book* book, char* author);
    void (*setObjectTitle)(struct book* book, char* title);
    // Getter-Methoden
    char* (*getObjectAuthor)(struct book* book);
    char* (*getObjectTitle)(struct book* book);
    // Sonstige Fuktionen
    char* (*rentObject)(struct book* book);
    char* (*returnObject)(struct book* book);
};

// Setter
void setAuthor(struct book* book, char* author){
    for(int i = 0; i < MAX_SIZE; i++){
        book->author[i] = author[i];
    }
}
void setTitle(struct book* book, char* title){
    for(int i = 0; i < MAX_SIZE; i++){
        book->title[i] = title[i];
    }
}
// Getter
char* getAuthor(struct book* book){
    return book->author;
}
char* getTitle(struct book* book){
    return book->title;
}
// Sonstige
char* rent(){

}

char* returnBook(){
    
}
int main(){
// Drei bücher leihe Sie aus und gib sie zrk. Lasse dabei jeweils die anzahl der bücher ausgeben
    return 0;
}