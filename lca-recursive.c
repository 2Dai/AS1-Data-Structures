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
	if(lca == NULL){ //condition d'arret de la recursion si NON trouvé
		return false;
	}
	else if(!strcmp(key,lca->key)){ // cndtion d'arret si trouvé
		return true;
	}
    else{
		used_key_lca(lca->next,key);
	}
}

void print_lca(lca_t lca){
    if(lca){
	        printf("-->[ \"%s\"=%d ]", lca->key, lca->data);
            print_lca(lca->next);
    }
	else{
            printf("--E\n");
	}
}

Donnee data_linked_lca(lca_t lca, Clef key){
        if(!strcmp(lca->key,key)){
		    return(lca->data);
	} 
	else{
		data_linked_lca(lca->next, key);
	}
}

void add_data_lca(lca_t *lca, Clef key, Donnee data){
	lca_t lcaTemp;
    if(!used_key_lca(*lca, key)){ // si la clé est pas utilisée
		    lcaTemp = *lca;
            *lca = malloc(sizeof(struct lca));
            (*lca)->key=malloc((strlen(key)+1)*sizeof(char));
            strcpy((*lca)->key,key);
            (*lca)->next = lcaTemp;
            (*lca)->data = data;
    }
    else{
		if(!strcmp((*lca)->key,key)){
			(*lca)->data = data;
	    }
		else{
			add_data_lca(&(*lca)->next, key, data);
        }
    }
}

void delete_data_lca(lca_t* lca, Clef key){
    lca_t lcaDestroy;
    if(used_key_lca(*lca,key)){
        if(!strcmp((*lca)->key,key)){
	        lcaDestroy = *lca;
            *lca = (*lca)->next;
            free(lcaDestroy->key);
	        lcaDestroy->key = NULL;
            free(lcaDestroy);
	        lcaDestroy = NULL;
        }
	    else{
		    delete_data_lca(&(*lca)->next,key);
	    }
   }
}

void clean_lca(lca_t* lca){
	if(*lca){
	    clean_lca(&(*lca)->next);
	    free((*lca)->key);
	    (*lca)->key = NULL;
	    free(*lca);
	    *lca = NULL;
	}
}
	
void destroy_lca(lca_t* lca){
	clean_lca(lca);
}
