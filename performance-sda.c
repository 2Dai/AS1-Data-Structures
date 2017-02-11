/********************************************************************************   
 *   Auteur   : Iffrig-Bourfa Dylan 
 *  Objectif : Performance de la sda
 ******************************************************************************/

#define TYPE_LCA 1
#define TYPE_TH 2
#define TYPE_TABLE TYPE_SDA

#include <stdio.h>
#include <stdlib.h>
#include "lca.h"
#include <string.h>
#if TYPE_TABLE == TYPE_TH
#include "th.h"
#include "fonctions-hachage.h"
#endif

void fill_sda(sda_t* sda){
    add_data_sda(sda,"a",42);
    add_data_sda(sda,"b",42);
    add_data_sda(sda,"c",42);
    add_data_sda(sda,"d",42);
    add_data_sda(sda,"e",42);
    
}

void perf_add(sda_t* sda){
    for(int i=0; i<0xffffff;i++){
        add_data_sda(sda,"test",42);
    }
}

void perf_data_linked(sda_t* sda){
    for(int i=0; i<0xffffff;i++){
       data_linked_sda(*sda,"test");
    }
}

void perf_clean(sda_t* sda){
    clean_sda(sda);
}


int main(void){
sda_t sda;
#if TYPE_TABLE == TYPE_TH
ptrHash hashFonction = hash_fonction1; // fonction hashage par default
int size = 15;
init_sda(&sda,size, hashFonction);
#else
init_sda(&sda);
#endif

fill_sda(&sda);
perf_add(&sda); //ajoute des données un grand nmb de fois
perf_data_linked(&sda); // idem
perf_clean(&sda);
destroy_sda(&sda);
return 0;
}
