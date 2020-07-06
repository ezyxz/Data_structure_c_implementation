#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100 //list inittal alloceted space
#define LISTINCREMENT  10  

typedef struct 
{
    int   code;
    int   age;
    char *name;
}ElemType;


typedef struct 
{
    ElemType    *elem;
    int        length;
    int        listsize;
}SqlList;

ElemType* Init_Elem(char * chr, int age, int code){
     ElemType * e = (ElemType *)malloc(sizeof(ElemType));
     e->age=age;
     e->code=code;
     e->name = (char *)malloc(strlen(chr)*sizeof(char));
     strcpy(e->name,chr);
     return e;
}

SqlList* Init_List(){
    SqlList * list = (SqlList*)malloc(sizeof(SqlList));
    if(!list){
        printf("fail to allocate memory to SqlList type!\n");
        return NULL;
    }else{
        return list;
    }
    
    
}

void InitList_Sq(SqlList *L){
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem){
        printf("fail to allocate memory to ElemType type!\n");
        exit;
    }else{
        L->length = 0;
        L->listsize=LIST_INIT_SIZE;
    }
}    
void ListAppend_Sq(SqlList *L,char *chr ,int age){
    int pos = L->length;
    L->elem[pos].code = pos+1;
    L->elem[pos].age =  age;
    L->elem[pos].name = (char *)malloc(strlen(chr)*sizeof(char));
    strcpy(L->elem[pos].name,chr);
    L->length++;

}
void ListPrintAll_Sq(SqlList *L){
     printf("SqlList length is %d\n",L->length);

    for (int i = 0; i < L->length; i++)
    {
     printf("=========================\n");
     printf("Code is %d\n",L->elem[i].code);
     printf("Name is %s\n",L->elem[i].name);  
     printf("Age  is %d\n",L->elem[i].age);
    }
    
}

void ListInsert_Sq(SqlList *L,int i ,ElemType *e){
    if (i<1||i>L->length+1)
        return ;
    if (L->length>=L->listsize)
    {
       ElemType *newbase = (ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
       if (!newbase)
           exit;
        L->elem = newbase;
        L->listsize+=LISTINCREMENT;
    }
    ElemType *q = &(L->elem[i-1]);
    for (ElemType *p = &(L->elem[L->length-1]); p>=q; --p)
    {
      *(p+1)=*p;  
    }
    
     *q = *e ;  
      
    //*q = e;
     L->length++;
     
}    
 

int main( int argc , char ** argv){
     SqlList  *list=Init_List();
     InitList_Sq(list);
     ListAppend_Sq(list,"jack",23);
     ListAppend_Sq(list,"tom",33);
     ListAppend_Sq(list,"black",44);

     ElemType * e = Init_Elem("mask",33,4);
     
     ListInsert_Sq(list,2,Init_Elem("mask",33,4));
    
     ListPrintAll_Sq(list);

    return 0;

    
}

