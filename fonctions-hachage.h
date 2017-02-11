/*******************************************************************************
 *  Auteur   : Iffrig-Bourfa Dylan 
 *  Objectif : Quelques fonctions de hachages
 ******************************************************************************/

#ifndef FONCTIONS_HACHAGE__H
#define FONCTIONS_HACHAGE__H

#include "types.h"

int hash_fonction1(Clef key);
	/*
     * Retourne la longueur de la clé : "taille"
	 */

int hash_fonction2(Clef key);
    /*
     * Retourne le code ascii de l'initiale de la clé : "initiale"
     */

int hash_fonction3(Clef key);
	/*
     * Retourne le code ascii de la clé : "somme"
	 * (somme la valeur ascii de tout les caracteres de la clé)
	 */

int hash_fonction4(Clef key);
    /*
     * Retourne la valeur de l'algorithme du sujet: "java"
     */

#endif
