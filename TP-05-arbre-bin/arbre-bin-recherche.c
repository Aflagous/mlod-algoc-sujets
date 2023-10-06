#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

bool estVide(ArbreBinaire a){
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire nouvelleArbre = (ArbreBinaire)malloc(sizeof(Noeud));
	nouvelleArbre->val = e;
	nouvelleArbre->filsGauche = NULL;
	nouvelleArbre->filsDroit = NULL;
    return nouvelleArbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
// Insère e dans a sachant que a est un arbre binaire de recherche
// Si a contient déjà un élément e, ce dernier n'est pas inséré afin d'éviter les doublons
// Version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
    ArbreBinaire nouvelleArbre = creer(e);
    ArbreBinaire p = a;
    ArbreBinaire prec = NULL; 
    while (p != NULL) {
        prec = p;
        if (p->val > e) {
            p = p->filsGauche;
        } else if (p->val < e) {
            p = p->filsDroit;
        } else {
            free(nouvelleArbre); 
            return a; 
        }
    }
    if (prec == NULL) {
        return nouvelleArbre;
    } else if (prec->val > e) {
        prec->filsGauche = nouvelleArbre;
    } else {
        prec->filsDroit = nouvelleArbre;
    }
    return a;
}

ArbreBinaire insere_r(ArbreBinaire a, Element e) {
    if (a == NULL) {
        return creer(e);
    }
    if (e < a->val) {
        a->filsGauche = insere_r(a->filsGauche, e);
    }
    else if (e > a->val) {
        a->filsDroit = insere_r(a->filsDroit, e);
    }
    return a;
}


int nombreDeNoeud(ArbreBinaire a){
	ArbreBinaire p = a;
	int nombre = 0;
	if (p != NULL){
		return 0;
	}
    nombre = nombre + nombreDeNoeud(p->filsDroit);
	nombre = nombre + nombreDeNoeud(p->filsGauche);
	return nombre;
}
int nombreDeNoeud(ArbreBinaire a) {
    if (a == NULL) {
        return 0;
    }
    return 1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit);
}

int profondeur(ArbreBinaire a, Element e) {
    if (a == NULL) {
        return -1;
    }
    if (a->val == e) {
        return 0;
    }
    int profondeurGauche = profondeur(a->filsGauche, e);
    if (profondeurGauche != -1) {
        return 1 + profondeurGauche;
    }
    int profondeurDroite = profondeur(a->filsDroit, e);
    if (profondeurDroite != -1) {
        return 1 + profondeurDroite;
    }
    return -1;
}


// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (a == NULL) {
        return 0;
    }
	if (hauteur(a->filsGauche) > hauteur(a->filsDroit)) {
		return 1 + hauteur(a->filsGauche);
	}
	return 1 + hauteur(a->filsDroit);
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	ArbreBinaire p = a;
	ArbreBinaire pp = a;
	ArbreBinaire prec = NULL;
	while (p != NULL || pp != NULL) {
        if (p->val == elem || pp->val == elem) {
			if (prec == NULL) {
				return NULL;
			} else {
				return prec;
			}
    	} else {
			p = p->filsDroit;
			pp = p->filsGauche;
		}
    }
}


void afficheRGD_r(ArbreBinaire a){
}

void afficheGRD_r(ArbreBinaire a){
}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

