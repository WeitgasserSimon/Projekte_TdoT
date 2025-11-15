#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 64


struct data{
  char name[MAX_SIZE];
  char interpret[MAX_SIZE];
  char dauer[MAX_SIZE];
};
typedef struct song{
  struct data* data;
  struct song* next;
}song_t;


song_t* add(song_t** head);

void show();
void delete();
void search();


int main(){
  char select;
  song_t* head = NULL;
  do{
    printf("ADD [1]\n");
    printf("SHOW [2]\n");
    printf("DELETE [3]\n");
    printf("SEARCH [4]\n");
    printf("END [5]\n");

    switch (select){
      case '1':
        add();
        break;
      case '2':
      show();
        break;
      case '3':
      delete();
        break;
      case '4':
      search();
        break;
      case '5':
        break;
        default:
        printf("NICHT");
    }
  }while(select != '5');
  
  return EXIT_SUCCESS;
}

void add(song_t** head, struct data* data){
  
  song->data->name = "10min";
  song->data->interpret
  int index = 1;
  printf("%i. Songname:",index);
  scanf("%c",);
}