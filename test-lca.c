#ifndef TEST_LCA__H
#define TEST_LCA__H
#include "seatest.h"
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "lca.h"
#include "lca-specifique.h"

void ajout_cellule(lca_t* lca,int data, char* key){
    *lca=malloc(sizeof(struct lca));
    (*lca)->key=malloc(sizeof((strlen(key)+1)*sizeof(char)));
    (*lca)->data = data;
    strcpy((*lca)->key,key);
}

lca_t genere_lca(int size){
	lca_t lca;
    	char key[64]="key";
    	lca_t lcaAnchor;
    	init_lca(&lca);
    	if(size<=0){
            return(lca);
    	}
    	else if(size>26){
            size=5;
    	}
    	ajout_cellule(&lca,0,"keyA");
    	lcaAnchor=lca;
    	for(int i=0;i<size-1;i++){
            key[3] = 'A'+(i+1);
	    ajout_cellule(&(lca->next),i+1,key);
            lca=lca->next;
     }
    return(lcaAnchor);
}


void test_init_lca(void){
	lca_t lca;
	init_lca(&lca);
	assert_true(empty_lca(lca));
}

void test_empty_lca(void){
	lca_t lcaEmpty = genere_lca(0);
	lca_t lcaNormal = genere_lca(4);

	assert_true(empty_lca(lcaEmpty));
	assert_false(empty_lca(lcaNormal));
}

void test_used_key_lca(void){
    	lca_t lcaEmpty = genere_lca(0);
    	lca_t lcaNormal = genere_lca(4);
    	lca_t lcaNoKeyD = genere_lca(3);

    	assert_true(used_key_lca(lcaNormal,"keyD"));
    	assert_false(used_key_lca(lcaNoKeyD,"keyD"));
    	assert_false(used_key_lca(lcaEmpty,"keyD"));
}

void test_delete_data_lca(void){
	lca_t lcaNormal = genere_lca(4);
    
	assert_true(used_key_lca(lcaNormal,"keyD"));
	delete_data_lca(&lcaNormal,"keyD");
	assert_false(used_key_lca(lcaNormal,"keyD"));
}
	
void test_data_linked_lca(void){
	lca_t lcaNormal = genere_lca(4);
	Donnee testData;
	
	assert_true(used_key_lca(lcaNormal, "keyD"));
	testData = data_linked_lca(lcaNormal, "keyD");
	assert_true(testData==3);
}

void test_add_data_lca(void){
   	lca_t lcaEmpty = genere_lca(0);
   	lca_t lcaNormal = genere_lca(4);
   	lca_t lcaNoKeyD = genere_lca(3);
    
	add_data_lca(&lcaEmpty,"keyD",42);
	add_data_lca(&lcaNormal,"keyD",42);
	add_data_lca(&lcaNoKeyD,"keyD",42);

	assert_true(data_linked_lca(lcaNormal,"keyD") == 42);
	assert_true(data_linked_lca(lcaEmpty,"keyD") == 42);
	assert_true(data_linked_lca(lcaNoKeyD,"keyD") == 42);

}

void test_clean_lca(void){
	lca_t lcaEmpty = genere_lca(0);
	lca_t lcaNormal = genere_lca(4);

	clean_lca(&lcaNormal);
	clean_lca(&lcaEmpty);
     
	assert_true(empty_lca(lcaEmpty));
	assert_true(empty_lca(lcaNormal));
}

void test_destroy_lca(void){
	// Identique à test_clean_lca
}
void test_fixture_lca( void )
{
        test_fixture_start();         
        run_test(test_init_lca);
    	run_test(test_empty_lca);
    	run_test(test_add_data_lca);
	    run_test(test_delete_data_lca);
        run_test(test_used_key_lca);   
        run_test(test_data_linked_lca);   
        run_test(test_clean_lca);   
        run_test(test_destroy_lca);   
        test_fixture_end();       
}


void all_tests(void){
  	test_fixture_lca();
}
int main(void){

//Jeux de tests

lca_t lcaEmpty = genere_lca(0);
lca_t lcaNoKeyD = genere_lca(3);
lca_t lcaNormal = genere_lca(4);

printf("\nJEUX DE TESTS\n");
printf("--- LCA VIDE ---\n");
print_lca(lcaEmpty);
printf("\n--- LCA NORMAL ---\n");
print_lca(lcaNormal);
printf("\n--- LCA SANS CLE D ---\n");
print_lca(lcaNoKeyD);
printf("\n\n");

destroy_lca(&lcaNormal);
destroy_lca(&lcaNoKeyD);

return run_tests(all_tests);
}

#endif

