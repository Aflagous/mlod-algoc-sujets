#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

bool estVide(Liste l) {
	return l == NULL;
}

Liste creer(Element v){
    Liste nouvelleListe = (Liste)malloc(sizeof(Cellule));
	nouvelleListe->val = v;
	nouvelleListe->suiv = NULL;
    return nouvelleListe;
}

Liste ajoutTete(Element v, Liste l){
    Liste nouvelleListe = creer(v);
	nouvelleListe->suiv = l;
    return nouvelleListe;
}

void afficheElement(Element e){
	printf("%d ",e);
}

void afficheListe_i(Liste l){
	Liste p = l;
    while (!estVide(p)) {
       	afficheElement(p->val);
        p = p->suiv;
    }
    printf("Fin de la liste\n");
}

void afficheListe_r(Liste l){
    if (l == NULL) {
        printf("Fin de la liste\n");
    } else {
        afficheElement(l->val);
        afficheListe_r(l->suiv);
    }
}

void detruireElement(Element e){ }

void detruire_i(Liste l){
    Liste suivant, courant = l;
    while (!estVide(courant)) {
		suivant = courant->suiv;
		detruireElement(courant->val);
        free(courant);
        courant = suivant; 
    }
}

void detruire_r(Liste l){
	if (!estVide(l)) {
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
    }
}

Liste ajoutFin_i(Element v, Liste l) {
	Liste nouvelleListe = creer(v);
	Liste p = l;
	if (estVide(p)) {
        return nouvelleListe;
    }
	while(!estVide(p->suiv)){
		p =p ->suiv;
	}
	p->suiv= nouvelleListe;
	return l;
}

Liste ajoutFin_r(Element v, Liste l) {
	if (l != NULL) {
        l->suiv = ajoutFin_r(v,l->suiv);
		return l;
	}
	Liste nouvelleListe = creer(v);
	return nouvelleListe;
}

bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

Liste cherche_i(Element v,Liste l) {
	while (l != NULL) {
		if (equalsElement(v, l->val)) {
			return l;
		}
		l = l->suiv;
    }
	return NULL;
}

Liste cherche_r(Element v,Liste l) {
	if (l == NULL) {
		return NULL;
	}
	if (equalsElement(v, l->val)) {
        return l;
    }  
	return cherche_r(v, l->suiv);
}

Liste retirePremier_i(Element v, Liste l) {
    Liste prec = NULL; 
    Liste courant = l; 
    while (courant != NULL) {
        if (courant->val == v) {
            if (prec != NULL) {
                prec->suiv = courant->suiv;
            } else {
                l = courant->suiv;
            }
            free(courant);
            break;
        }
        prec = courant;
        courant = courant->suiv;
    }
    return l;
}

Liste retirePremier_r(Element v, Liste l) {
    if (l == NULL) {
        return NULL;
    }
    if (l->val == v) {
        Liste suivant = l->suiv; 
        free(l); 
        return suivant;
    }
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}

void afficheEnvers_r(Liste l) {
    if (l != NULL) {
		afficheEnvers_r(l->suiv);
    	printf("%d ", l->val);
    }
}