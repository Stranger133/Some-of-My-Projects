#include <stdio.h>
#include <stdlib.h>


typedef struct element{
  char name[10];
  int rank;
  struct element *suiv;
}element;

typedef struct list{
  element *head;
}list;

void addTail(list *l) {

  element *newhorse = (element*)malloc(sizeof(element));
  newhorse->suiv = NULL;
  printf("donner le nom:\n");
  scanf("%s",newhorse->name);
  printf("donner le rank:\n");
  scanf("%d",&newhorse->rank);

  if(l->head == NULL){
    newhorse->suiv = l->head;
    l->head = newhorse;
    return;
  }
  else{
    element *tmp = l->head;
    while (tmp->suiv != NULL) {
      tmp = tmp->suiv;
    }
    tmp->suiv = newhorse;
  }
}

list createlist(int n){

  list *l = (list*)malloc(sizeof(list));
  l->head = NULL;
  for(int i = 0;i<n;i++){
    addTail(l);
  }
  return *l;

}


element maxrank(list l){

  int i = 0;
  element *tmp = l.head;
  while (tmp != NULL) {
    if (tmp->rank > i) {
      i = tmp->rank;
    }
    tmp = tmp->suiv;
  }
  tmp = l.head;
  while (tmp != NULL) {
    if (tmp->rank == i) {
      return *tmp;
    }
    tmp = tmp->suiv;
  }
}

void supprimermax(list *l) {
    element max = maxrank(*l);
    if(l == NULL){return;}
    if(l->head->rank == max.rank){
        element *t = l->head;
        l->head = l->head->suiv;
        free(t);
        t = NULL;
    }

  element *tmp = l->head;
  while (tmp->suiv!=NULL && tmp->suiv->rank != max.rank) {
    tmp = tmp->suiv;
    }
    if(tmp->suiv == NULL)return;
    element *t = tmp->suiv;
    tmp->suiv = tmp->suiv->suiv;
    free(t);
    t=NULL;
}

void print(list l) {
  element *tmp = l.head;
  while (tmp != NULL) {
    printf("Horse %s has the Rank %d\n",tmp->name,tmp->rank);
    tmp = tmp->suiv;
  }
}

void main() {
  struct list l = createlist(3);
  print(l);
  printf("the max rank is %d \n",maxrank(l).rank);
  printf("***********apres supression*************\n");
  supprimermax(&l);
  print(l);
}
