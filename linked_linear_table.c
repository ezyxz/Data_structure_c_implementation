#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    int age;
    char *name;
} ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

void ListPrintAll_L(LinkedList head);
LinkedList InitList_L();
void ListAppend_L(LinkedList head, int code, int age, char *name);
ElemType *ListGetElem_L(LinkedList head, int code);
ElemType *ListGetElem_L2(LinkedList head, char *name);
void ElemPrintAll_L(ElemType *e);
void ListInsert_L(LinkedList head, int i, ElemType *e);
ElemType ListDelete_L(LinkedList head,int i);
LinkedList MergeList_L(LinkedList La,LinkedList Lb);

int main(int argc, char *argv[])
{
    LinkedList head1 = InitList_L();
    LinkedList head2 = InitList_L();
    //////////////////////////////////////////
    ListAppend_L(head1, 1, 11, "steve");
    ListAppend_L(head1, 3, 22, "mask");
    ListAppend_L(head1, 5, 33, "jack");
    ListAppend_L(head1, 7, 44, "tom");
    ListAppend_L(head1, 9, 109, "black");
    //////////////////////////////////////////
    ListAppend_L(head2, 2, 11, "steve2");
    ListAppend_L(head2, 4, 22, "mask2");
    ListAppend_L(head2, 6, 33, "jack2");
    ListAppend_L(head2, 8, 44, "tom2");
    ListAppend_L(head2, 10, 109, "black2"); 
    ListAppend_L(head2, 12, 109, "hello");    
   
    LinkedList t =MergeList_L(head1,head2);
    printf("hello");
    ListPrintAll_L(t);
    //printf("%d",t->next->data.code);
   
   
    // //test
    // ElemType* e =(ElemType*)malloc(sizeof(ElemType));
    // e->age=999;
    // e->code=999;
    // e->name = (char*)malloc(strlen("test")*sizeof(char));
    // strcpy(e->name,"test");
    // //test.end
    // ListInsert_L(head,4,e); 

    // // ListPrintAll_L(head);
    // // ElemType* t = ListGetElem_L(head,3);
    // // ElemPrintAll_L(ListGetElem_L2(head, "steve"));
    // ListPrintAll_L(head);

    //  ElemType e1 = (ListDelete_L(head,4));
    //  ListPrintAll_L(head);
    //  //printf("%s\n",e1.name);
    //  ElemPrintAll_L(&e1);
    return 0;
}

void ListPrintAll_L(LinkedList head)
{
    LinkedList L = head->next;

    while (head->next)
    {
        printf("===========================\n");
        printf("Code is %d\n", head->next->data.code);
        printf("Name is %s\n", head->next->data.name);
        printf("Age  is %d\n", head->next->data.age);
        head->next = head->next->next;
    }
    head->next = L;
}

LinkedList InitList_L()
{
    LinkedList head = (LinkedList)malloc(sizeof(LNode));
    if (!head)
    {
        printf("fail to initialize !\n");
        return NULL;
    }
    head->next = NULL;
    head->data.code = -1;
    head->data.age = -1;
    head->data.name = NULL;

    return head;
}

void ListAppend_L(LinkedList head, int code, int age, char *name)
{
    LinkedList q = (LinkedList)malloc(sizeof(LNode));
    q->data.name = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(q->data.name, name);
    q->data.age = age;
    q->data.code = code;
    q->next = NULL;
    if (!head->next)
    {
        head->next = q;
        // printf("%d\n", code);
    }
    else
    {
        LinkedList L = head->next;
        while (head->next->next)
        {
            head->next = head->next->next;
        }
        head->next->next = q;
        head->next = L;
        // printf("%d\n", code);
    }
}

ElemType *ListGetElem_L(LinkedList head, int code)
{
    LinkedList L = head->next;
    ElemType *q = NULL;
    while (head->next)
    {
        if (head->next->data.code == code)
        {
            q = &(head->next->data);
            break;
        }
        head->next = head->next->next;
    }
    head->next = L;
    return q;
}

void ElemPrintAll_L(ElemType *e)
{
    if (!e)
    {
        printf("Null Pointer!");
        return;
    }
    else
    {
        printf("=================\n");
        printf("Code is %d\n", e->code);
        printf("Name is %s\n", e->name);
        printf("Age  is %d\n", e->age);
    }
}

ElemType *ListGetElem_L2(LinkedList head, char *name)
{
    LinkedList L = head->next;
    ElemType *q = NULL;
    while (head->next)
    {
        if (strcmp(head->next->data.name, name) == 0)
        {
            q = &(head->next->data);
            break;
        }
        head->next = head->next->next;
    }
    head->next = L;
    return q;
}

void ListInsert_L(LinkedList head, int i, ElemType *e)
{
    LinkedList L = head;
    int j = 0;
    while (head && j<i-1)
    {
        head=head->next;
        j++;
    }
    if (!head||j>i-1)
    {
        printf("Error!\n");
    }
    LinkedList s =(LinkedList)malloc(sizeof(LNode));
    s->data=*e;
    s->next=head->next;
    head->next=s;
    head=L;
    
}


ElemType ListDelete_L(LinkedList head,int i){
    LinkedList L = head;
    ElemType  e ;
    int j=0;
    while (head->next && j<i-1)
    {
        head=head->next;
        j++;
    }
    if (!(head->next)||j>i-1)
    {
        printf("error!\n"); 

    }
    LinkedList q = head->next;
    head->next=q->next;
    e = q->data;
    free(q);
    return e;
}

LinkedList MergeList_L(LinkedList La,LinkedList Lb){
    LinkedList e = InitList_L();
    LinkedList temp = e;

    while (La->next && Lb->next)
    {
        if (La->next->data.code<=Lb->next->data.code)
        {
            e->next=La->next;
            e=La->next;
            La->next=La->next->next;        
        }else
        {
            e->next=Lb->next;
            e=Lb->next;
            Lb->next=Lb->next->next; 
        }
        
    }
    e->next = La->next ? La->next:Lb->next;
    e=temp;

    free(Lb);
    free(La);
    return e;
}
