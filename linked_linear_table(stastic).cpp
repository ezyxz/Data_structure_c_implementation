#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000


typedef struct
{
    int code;
    int age;
    char *name;
} ElemType;
 typedef struct 
 {
     ElemType data;
     int cur;
 }component ,SLinkList[MAXSIZE];
 
void InitSpace_SL(SLinkList &space){
    for (int i = 0; i < MAXSIZE-1; i++)
    {
        space[i].cur = i+1;

    }
    space[MAXSIZE-1].cur = 0;
}

int main (int argc , char ** argv){
    SLinkList t;
    InitSpace_SL(t); 
    printf("%d\n",t[0].cur);
    
    printf("hello world!\n");
    
    return 0;
}