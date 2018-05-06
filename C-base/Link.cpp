/*************************************************************************
	> File Name: link.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Sat May  5 09:36:49 2018
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

using namespace std;

typedef int ListItem ;

typedef struct node *link ;
typedef struct node{
    ListItem element ;
    link next=NULL;
}Node;

link newlink(){
    link p;
    if((p = (link) malloc(sizeof(Node)))==0) perror("Exhausted memory");
    else return p;
}

typedef struct llist * List;
typedef struct llist{
    link first;

}Llist;

List ListInit(){
    List L = (List)malloc(sizeof(Llist)) ;
    L->first = 0;
    return L ;
}

int ListLength(List L){
    int len = 0;
    link p = L->first ;
    while(p){
        ++len;
        p = p->next ;
    }
    return len ;
}

int ListEmpty(List L){
    return L->first==0;
}

ListItem ListRetrieve(int k,List L){
    if(k<1) perror("out of bounds");
    link p = L->first ;
    while(--k&&p){p = p->next;}
    return p->element ;
    
}

void ListInsert(int k,ListItem x, List L){
    
    if(k<0) perror("out of bounds");
    link p = L->first ;
    int i = k;
    while(--i&&p){p = p->next;}
    
    link newP = newlink();
    newP->element = x ;
    if(k==0){
        newP->next = L->first ;
        L->first = newP ;
    }
    else{
        newP->next = p->next ;
        p->next = newP ;
    }
}

int main(){
    List L = ListInit() ;
    link p1 = newlink();
    p1->element = 1;
    L->first = p1 ;

    link p2 = newlink();
    p2->element = 2;
    p1->next = p2 ;
    
    link p3 = newlink();
    p3->element = 3;
    p2->next = p3 ;

    printf("the 2rd value is :%d\n",L->first->next->next->element) ;
    printf("the list is empty: %s\n",ListEmpty(L)?"True":"False");
    printf("the length of L is : %d\n",ListLength(L));
    printf("the %d element is %d\n",3,ListRetrieve(3,L));
    ListInsert(0,10,L);
    printf("the %d element is %d\n",1,ListRetrieve(1,L));
    return 0;

}
