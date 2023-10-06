#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int Element;

struct noeud_s {
	Element val;
	struct noeud_s* filsGauche;
	struct noeud_s* filsDroit;
};

typedef struct noeud_s Noeud;
typedef Noeud* ArbreBinaire;

bool estVide(ArbreBinaire a);
void initialiser(ArbreBinaire* a);
ArbreBinaire creer(Element e);
ArbreBinaire insere_i(ArbreBinaire a, Element e);
ArbreBinaire insere_r(ArbreBinaire a, Element e);
int nombreDeNoeud(ArbreBinaire a);
int profondeur(ArbreBinaire a, Element e);
int hauteur(ArbreBinaire a);
ArbreBinaire pere(ArbreBinaire a, Element elem);
void afficheRGD_r(ArbreBinaire a);
void afficheGRD_r(ArbreBinaire a);
void afficheGDR_r(ArbreBinaire a);

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a);

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a);

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem);

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x);

void detruire_r(ArbreBinaire a);

