/*******************************************************************************
 *  Auteur   : Iffrig-Bourfa Dylan 
 *  Objectif : Interpréteur d'un fichier de commandes
 ******************************************************************************/

#define TYPE_LCA 1
#define TYPE_TH 2
#define TYPE_TABLE TYPE_SDA

#include <stdio.h>
#include <stdlib.h>
#include "lca.h"
#include <string.h>
#define SIZE_BUFF_MAX 512
#define SIZE_KEY_MAX 128
#if TYPE_TABLE == TYPE_TH
#include "th.h"
#include "fonctions-hachage.h"
#endif

int main(){
    char buffer[SIZE_BUFF_MAX]; //buffer pour stocker les commandes
    int size=1; //taille par défault
    #if TYPE_TABLE == TYPE_TH
    ptrHash hashFonction = hash_fonction1; // fonction hashage par default
    #endif
    Clef key=malloc(SIZE_KEY_MAX*sizeof(char)); // clé tampon
    Donnee data;

    sda_t sda;
	
    FILE * fichier = NULL;

    fichier = fopen("exemple1.sda","r");

    if(fichier != NULL){
	#if TYPE_TABLE == TYPE_LCA
	init_sda(&sda); //initialise la lca
    #endif
	  while(fscanf(fichier,"%s",buffer)!= EOF){ //condition sur fin du fichier
        if(!strcmp(buffer,"print")){
			printf("> print\n");
        	print_sda(sda);
		}
        else if(!strcmp(buffer,"size")){
          		fscanf(fichier,"%d",&size);
                printf("> size %d\n",size);
		}
		else if(!strcmp(buffer,"hash")){
			fscanf(fichier,"%s",buffer);
            #if TYPE_TABLE == TYPE_TH //code utile uniquement pour th
			if(!strcmp(buffer,"taille"))
				hashFonction = hash_fonction1;
			else if(!strcmp(buffer,"initiale"))
				hashFonction = hash_fonction2;
			else if(!strcmp(buffer,"somme"))
				hashFonction = hash_fonction3;
			else if(!strcmp(buffer,"java"))
				hashFonction = hash_fonction4;
            init_sda(&sda,size, hashFonction); //Initialise la th
            #endif
			printf("> hash %s\n",buffer);
        }
		else if(!strcmp(buffer,"add")){
			fscanf(fichier,"%s",key);
			fscanf(fichier,"%d",&data);
			printf("> add %s %d\n",key,data);
			add_data_sda(&sda, key, data);
		}
		else if(!strcmp(buffer,"value")){
			fscanf(fichier,"%s",key);
			printf("> value %s\n",key);
			if(used_key_sda(sda,key)){
				data=data_linked_sda(sda, key);
				printf("%d\n",data);
			}
			else{
				printf("----\n");
			}
		}
		else if(!strcmp(buffer,"contains")){
			fscanf(fichier,"%s",key);
			printf("> contains %s\n",key);
			if(used_key_sda(sda,key))
				printf("yes\n");
			else
				printf("no\n");
    		}
		else if(!strcmp(buffer,"clear")){
			printf("> clear\n");
			clean_sda(&sda);
		}
		else if(!strcmp(buffer,"end")){
			printf("> end\n");
			destroy_sda(&sda);
		}
	  }
    }
    else{
         printf("erreur de lecture du fichier\n");
    }
    fclose(fichier);
    free(key);
}

