/*******************************************************************************
 *  Auteur   : 
 *  Objectif : Implantation de la table de hachage
 ******************************************************************************/

#include "th.h"
#include "lca.h"
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "assert.h"

void init_th(th_t* th, int size, ptrHash hashFonction){
	th->size=size;
	th->hashFonction = hashFonction;
	th->array=malloc(size*sizeof(lca_t));
	for(int i=0; i<size; i++){
		th->array[i]=NULL;
	}
}

void print_th(th_t th){
	for(int i=0;i<(th.size);i++){
	   printf("  %d[@-]",i);
	   print_lca(th.array[i]);
	}
}
	
bool empty_th(th_t th){
	bool empty = true;
	int i = 0;
	while(empty && th.size>i){
		if(th.array[i]!=NULL)
			empty = false;
		i++;
	}
	return(empty);
}
void add_data_th(th_t* th, Clef key, Donnee data){
	int index;
	index = (*th->hashFonction)(key)%(th->size);
	add_data_lca(&th->array[index], key, data);
}

void delete_data_th(th_t* th, Clef key){
	int index;
	index = (*th->hashFonction)(key)%(th->size);
	delete_data_lca(&th->array[index], key);
}

bool used_key_th(th_t th, Clef key){
	int index;
	index = (th.hashFonction)(key)%(th.size);
	return(used_key_lca(th.array[index], key));
}

Donnee data_linked_th(th_t th, Clef key){
	int index;
	index = (th.hashFonction)(key)%(th.size);
	return(data_linked_lca(th.array[index], key));
} 

void clean_th(th_t* th){
	for(int i=0; i<th->size;i++){
		clean_lca(&th->array[i]);
	}
}

void destroy_th(th_t* th){
	clean_th(th);
	free(th->array);
	th->array=NULL;
}
