/*******************************************************************************
 *  Auteur   : Iffrig-Bourfa Dylan
 *  Objectif : Implantation du module fonctions-hachages.
 ******************************************************************************/

#include "fonctions-hachage.h"
#include <string.h>

/*description des sous programmes dans fonctions_hachages.h*/

int hash_fonction1(Clef key){
	return(strlen(key));
}

int hash_fonction2(Clef key){
	return((int)(key[0]));
}

int hash_fonction3(Clef key){
	int hashCode;
	for(int i=0;i<strlen(key);i++){
		hashCode+=(int)(key[i]);
	}
	return(hashCode);
}

int hash_fonction4(Clef key){
	int hashCode = 0;
	for(int i=0; i<strlen(key);i++){
		hashCode*=31 + (int)(key[i]);
	}
	return(hashCode);
}
	
