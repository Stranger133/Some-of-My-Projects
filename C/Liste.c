#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Infos{
  int val;
}Infos;

typedef struct Element{
  Infos data;
  struct Element* suiv;
}Element;

typedef struct Liste{
  Element* tete;
}Liste;

Liste creerListe(){
  Liste *l = (Liste*)malloc(sizeof(Liste));
  l->tete = NULL;
  return *l;
}
bool estVide(Liste l){
  if(l.tete == NULL)return true;
  return false;
}
void ajouterTete(Liste *l,Infos d){
  Element *e = (Element*)malloc(sizeof(Element));
  e->data = d;
  e->suiv = l->tete;
  l->tete= e;
}

void supprimerTete(Liste *l) {
  if(l->tete == NULL) return;
  Element *t = l->tete;
  l->tete = l->tete->suiv;
  free(t);
  t=NULL;
}

void afficherInfos(Infos d){
printf("Value:%d\n",d.val);
}

void afficherListe(Liste l){
  Element *temp = l.tete;
  while (temp != NULL) {
    afficherInfos(temp->data);
    temp=temp->suiv;
  }
}

void ajouterFin(Liste *l,Infos d){
  if(l->tete == NULL){
    ajouterTete(l,d);
    return;
  }
  Element *e=(Element*)malloc(sizeof(Element));
  e->data = d;
  e->suiv = NULL;

  Element *tmp = l->tete;
  while (tmp->suiv!=NULL){
    tmp = tmp->suiv;
    }
    tmp->suiv = e;
}

void supprimerFin(Liste *l){
  if(l->tete == NULL)return;
  if(l->tete->suiv == NULL){
    supprimerTete(l);
    return;
  }
  Element *tmp = l->tete;
  while(tmp->suiv->suiv != NULL){
    tmp = tmp->suiv;
  }
  Element *t = tmp->suiv;
  tmp->suiv = NULL;
  free(t);
}

int nombreElements(Liste l){
  int nb = 0;
  Element *temp = l.tete;
  while (temp != NULL) {
    nb++;
    temp = temp->suiv;
  }
  return nb;
}

int nombreOccurence(Liste l,int v){
  int nb=0;
  Element *tmp = l.tete;
  while(tmp != NULL){
    if (tmp->data.val == v) {
      nb++;
    }
    tmp=tmp->suiv;
  }
  return nb;
}

void supprimerValeur(Liste *l,int v){
  if(estVide(*l))return;
  if(l->tete->data.val == v){
    supprimerTete(l);
  }
  Element *tmp = l->tete;
  while (tmp->suiv != NULL && tmp->suiv->data.val != v) {
    tmp = tmp->suiv;
  }
  if (tmp->suiv == NULL) return;
  Element *t = tmp->suiv;
  tmp->suiv = tmp->suiv->suiv;
  free(t);
  t = NULL;
}
Element* adresseValeur(Liste l,int val){
  Element* tmp = l.tete;
  while(tmp != NULL){
    if (tmp->data.val == val) {
      return tmp;
    }
    tmp = tmp->suiv;
  }
  return NULL;
}

void main(){
  Liste l;
  l=creerListe();
  Infos a;
  int n;
  int i;
  int v;
  printf("How many ? ") ;
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    printf("Donner la valeur a ajouter: ");
    scanf("%d",&a.val);
    ajouterFin(&l,a);
  }

  afficherListe(l);
  printf("Le Nombre d'elements est: %d\n",nombreElements(l));
  printf("**********************\n");
  printf("Apres suppression tete: \n");
  supprimerTete(&l);
  afficherListe(l);
  printf("**********************\n");
  printf("Apres suppression Fin: \n");
  supprimerFin(&l);
  afficherListe(l);
  printf("**********************\n");
  printf("Le Nombre d'elements apres tout suppression est: %d\n",nombreElements(l));
  printf("Search for: \n");
  scanf("%d",&v);
  printf("Cette valeur est reppeter %d fois; \n",nombreOccurence(l,v));
  printf("**********************\n");
  printf("Supprimer: \n");
  scanf("%d",&v);
  printf("Apres suppression de %d ; \n",v);
  supprimerValeur(&l,v);
  afficherListe(l);
  printf("**********************\n");
  printf("Donner ta valeur; \n");
  scanf("%d",&v);
  Element*t=adresseValeur(l,v);
  if(t!=NULL)printf("\nLa valeur est %d",t->data.val);
  else printf("\nLa valeur n'existe pas!!!\n");
  printf("**********************\n");



}
