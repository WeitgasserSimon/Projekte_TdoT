/**
* @brief    Objekte in C
* @author   Simon Weitgasser & Ammar Djulic
* Objekt Rechteck
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct infos { 
    int width;
    int height;
    int area;
    int circumference;
} info_t;

typedef struct object {
    info_t* infos;

    // Setter-wMethoden
    void (*setWidth)(struct object*, int x);
    void (*setHeight)(struct object*, int y);
    
    // Getter-Methoden
    int (*getArea)(struct object*);
    int (*getCircumference)(struct object*); 
    //Sonstige Methoden
     char* (*toString)(struct object*);
} object_t;

void setObjectHeight(struct object* obj, int h) {
    obj->infos->height = h;
    
}

void setObjectWidth(struct object* obj, int w){
    obj->infos->width = w;
}

int getObjectArea(struct object* obj){
    obj->infos->area = obj->infos->width * obj->infos->height;
    return obj->infos->area;
}

int getObjectCircumference(struct object* obj){
    return 2*obj->infos->width + 2*obj->infos->height;
}
char* toString(object_t* obj){
    printf("Das Objekt ist %i hoch und %i breit, es ist %i groß und n",obj->infos->height,obj->infos->width,obj->infos->area,obj->infos->circumference);
}
object_t* createObject(){
    object_t* obj = malloc(sizeof(object_t));
    if(NULL == obj){
        printf("malloc failed for object_t");
        return NULL;
    }
    obj->infos = malloc(sizeof(info_t));
    if(NULL == obj->infos){
        printf("malloc failed for infos_t");
        return NULL;
    }
    obj->infos->height = 0;
    obj->infos->width = 0;
    obj->infos->area = 0;
    obj->infos->circumference = 0;
    
    obj->setHeight = &setObjectHeight;
    obj->setWidth = &setObjectWidth;
    obj->getArea = &getObjectArea;
    obj->getCircumference = &getObjectCircumference;

    return obj;
}

int main() {
    object_t* obj = createObject();

    obj->setHeight(obj, 4);
    obj->setWidth(obj, 6);
    obj->getArea(obj);
    obj->getCircumference(obj);

    printf("%i\n",obj->getArea(obj));
    printf("%i\n",obj->getCircumference(obj));
    printf("%s\n",obj->toString(obj));
    return 0;
}