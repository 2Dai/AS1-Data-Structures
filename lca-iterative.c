/*******************************************************************************
 *  Auteur   : Iffrig-Bourfa Dylan
 *  Objectif : Implantation de la LCA
 ******************************************************************************/

#include "lca.h"
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

void init_lca(lca_t *lca){
	*lca=NULL;
}

bool empty_lca(lca_t lca){
	return(!lca);
}

bool used_key_lca(lca_t lca, Clef key){
	bool used = false;
	while(lca && !used){
		if(!strcmp(key,lca->key))
			used=true;
		lca=lca->next;
	}
	return(used);
}

Donnee data_linked_lca(lca_t lca, Clef key){
	while(strcmp(lca->key,key)){
		lca = lca->next;
	}
	return(lca->data);
}

void add_data_lca(lca_t *lca, Clef key, Donnee data){
	lca_t lcaAnchor = *lca;
	if(!used_key_lca(*lca, key)){ //si clé non utilisé
		*lca = malloc(sizeof(struct lca));
		(*lca)->key=malloc((strlen(key)+1)*sizeof(char));
		strcpy((*lca)->key,key);
		(*lca)->next = lcaAnchor;
		(*lca)->data = data;
	}
	else{
		while(strcmp((*lca)->key, key)){ //si clé déjà utilisé
			*lca=(*lca)->next;
		}
		(*lca)->data = data;
		*lca= lcaAnchor; //on recentre la lca à son origine
	}
}

void delete_data_lca(lca_t* lca, Clef key){
    lca_t lcaAnchor = *lca;
    lca_t lcaDestroy;
    lca_t lcaSave;
    if(used_key_lca(*lca,key)){
        if(!strcmp((*lca)->key,key)){ //si c'est la premiere cellule qui est concerné
            lcaDestroy = *lca;
            *lca = (*lca)->next;
            free(lcaDestroy->key);
            free(lcaDestroy);
        }
        else{ 
            lcaSave=*lca;
            while(strcmp((*lca)->key,key)){
                lcaSave=*lca;
                *lca=(*lca)->next;
            }
            lcaDestroy = *lca;
            *lca = (*lca)->next;
            free(lcaDestroy->key);
            free(lcaDestroy);
            lcaSave->next = *lca;
            *lca = lcaAnchor;
        }
    }
}

void clean_lca(lca_t* lca){
    lca_t lcaTemp;
	while(*lca){
		lcaTemp= (*lca)->next;	
        free((*lca)->key);
        (*lca)->key = NULL;
        free(*lca);
        (*lca) = NULL;
        *lca = lcaTemp;
	}
}

void destroy_lca(lca_t* lca){
	clean_lca(lca); //identique à clean pour la lca
}

void print_lca(lca_t lca){
	while(lca){
		printf("-->[ \"%s\"=%d ]", lca->key
					   , lca->data);
		lca=lca->next;
	}
	printf("--E\n");
} 

