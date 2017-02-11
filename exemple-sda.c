/*******************************************************************************
 *  Auteur   : Iffrig-Bourfa Dylan 
 *  Objectif : Un exemple d'utilisation d'une SDA.
 ******************************************************************************/
#define TYPE_LCA 1
#define TYPE_TH 2
#define TYPE_TABLE TYPE_SDA

#include <stdio.h>
#include "seatest.h"
#include "sda.h"
#if TYPE_TABLE == TYPE_TH
#include "fonctions-hachage.h"
#endif

int main() {
    sda_t dict;
#if TYPE_TABLE == TYPE_LCA
    // Initialiser dict comme une LCA.
    init_sda(&dict);
#else
    // Initialiser dict comme une TH de taille 11 avec la fonction taille.
    ptrHash ptrf1 = hash_fonction1;
    init_sda(&dict,11,ptrf1);
#endif


    char clef[] = "aaa"; 
    // Enregistrer -1 avec cle dans dict.
    add_data_sda(&dict, clef, -1);
    // Vérifier que clef est une clef utilisée
    assert_true(used_key_sda(dict, clef));
    // Vérifier que la valeur de clef est -1
    assert_true(data_linked_sda(dict,clef)==-1);

    clef[0] = 'b';
    // Enregistrer -2 avec cle dans dict.
    add_data_sda(&dict,clef, -2);
    // Vérifier que clef est une clef utilisée
    assert_true(used_key_sda(dict, clef));
    // Vérifier que la valeur de clef est -2
    assert_true(data_linked_sda(dict,clef)==-2);
    // Vérifier que "aaa" est une clef utilisée
    assert_true(used_key_sda(dict,"aaa"));
    // Vérifier que la valeur de la clef "aaa" est -1
    assert_true(data_linked_sda(dict,"aaa")==-1);

    destroy_sda(&dict);
}
