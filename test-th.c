#ifndef TEST_TH__H
#define TEST_TH__H
#include <assert.h>
#include "fonctions-hachage.h"
#include "th.h"
#include "seatest.h"

th_t genere_th(int size, ptrHash ptrf, int nonVide){
	th_t th;
	init_th(&th,size, ptrf);
	if(nonVide){
		add_data_th(&th,"keyA", 0);
		add_data_th(&th,"keyAA", 42);
	}
	return(th);
}
void test_init_th(void){
	th_t thNormal;
	ptrHash ptrf1 = hash_fonction1;
	
	init_th(&thNormal,5,ptrf1);

	assert_true(thNormal.size>0);
	assert_true(empty_th(thNormal));

    destroy_th(&thNormal);
}	
void test_data_linked_th(void){
	ptrHash ptrf1 = hash_fonction1;
	
	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);
	
	assert_true(used_key_th(thNormal, "keyAA"));
	assert_false(used_key_th(thEmpty, "keyAA"));
	
	Donnee data = data_linked_th(thNormal,"keyAA");
	assert_true(data==42);
   
    destroy_th(&thNormal);
    destroy_th(&thEmpty);

}
void test_add_data_th(void){
	ptrHash ptrf1 = hash_fonction1;

	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);
	
	add_data_th(&thNormal,"keyAA",50);
	add_data_th(&thEmpty,"keyAA",50);

	assert_true(data_linked_th(thNormal,"keyAA")==50);
	assert_true(data_linked_th(thEmpty,"keyAA")==50);


    destroy_th(&thEmpty);
    destroy_th(&thNormal);
}
void test_clean_th(void){
	ptrHash ptrf1 = hash_fonction1;

	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);

	clean_th(&thNormal);
	clean_th(&thEmpty);

	assert_true(empty_th(thNormal));
	assert_true(empty_th(thEmpty));

    destroy_th(&thNormal);
    destroy_th(&thEmpty);
}
void test_destroy_th(void){
	ptrHash ptrf1 = hash_fonction1;

	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);

	destroy_th(&thNormal);
	destroy_th(&thEmpty);
	
	assert_true(thNormal.array == NULL);
	assert_true(thEmpty.array == NULL);
}
void test_used_key_th(void){
	ptrHash ptrf1 = hash_fonction1;

	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);
	
	assert_true(used_key_th(thNormal,"keyAA"));
	assert_false(used_key_th(thEmpty,"keyAA"));

    destroy_th(&thNormal);
    destroy_th(&thEmpty);
}	
void test_delete_data_th(void){
	ptrHash ptrf1 = hash_fonction1;

	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);

	delete_data_th(&thNormal,"keyAA");
	delete_data_th(&thEmpty,"keyAA");

	assert_false(used_key_th(thNormal,"keyAA"));
	assert_false(used_key_th(thEmpty,"keyAA"));

    destroy_th(&thNormal);
    destroy_th(&thEmpty);
}
void test_empty_th(void){
	ptrHash ptrf1 = hash_fonction1;

	th_t thNormal = genere_th(5,ptrf1,1);
	th_t thEmpty = genere_th(5,ptrf1,0);

	assert_false(empty_th(thNormal));
	assert_true(empty_th(thEmpty));

    destroy_th(&thNormal);
    destroy_th(&thEmpty);
}

void test_fixture_th(void){
    test_fixture_start();
    run_test(test_init_th);
    run_test(test_data_linked_th);
	run_test(test_add_data_th);
	run_test(test_clean_th);
	run_test(test_delete_data_th);
	run_test(test_destroy_th);
	run_test(test_used_key_th);
	run_test(test_empty_th);
    test_fixture_end();
}


void all_tests(void){
        test_fixture_th();
}
int main(){

//Jeux de tests
ptrHash ptrf1 = hash_fonction1;

th_t thEmpty = genere_th(5,ptrf1,0);
th_t thNormal = genere_th(5,ptrf1,1);

printf("\nJEUX DE TESTS\n");
printf("--- TH VIDE ---\n");
print_th(thEmpty);
printf("\n--- TH NORMAL ---\n");
print_th(thNormal);
printf("\n\n");

destroy_th(&thEmpty);
destroy_th(&thNormal);

return run_tests(all_tests);
}
#endif
