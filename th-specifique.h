// TODO: Donner la définition du type TH (et autres types nécessaires).

// TODO: Donner la spécification des sous-programmes dont la signature est
// spécifique à TH.

#ifndef TH_SPECIFIQUE__H
#define TH_SPECIFIQUE__H
#include "lca-specifique.h"


typedef int (*ptrHash)(Clef);

struct th{
	lca_t* array;
	int size;
	ptrHash hashFonction;
};

typedef struct th th_t;
    /*
     * Necessite size >0:
     * Necessite hashFonction dans {"taille","initiale"
     * ,"somme","java"}
     */

void init_th(th_t* th, int size, ptrHash hashFonction);
	/* Initialiser la th. assigne la taille, la fonction de
     * hachage et initialise toute les valeurs à NULL
	 *
	 * Nécessite :
	 *	size > 0;
	 *
	 * Assure :
	 *	empty_th(*th);
	 */


#endif
