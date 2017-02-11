/*******************************************************************************
 *  Auteur  : Xavier CRÉGUT <nom@n7.fr>
 *  Objectif : Spécification d'une sda, structure de données associative
 ******************************************************************************/

#ifndef SDA__H
#define SDA__H

#include <stdbool.h>
#include "sda-specifique.h"

bool empty_sda(sda_t sda);
	/* La sda est elle vide ?
     */

void add_data_sda(sda_t* sda, Clef key, Donnee data);
	/* Ajoute une donnée à la sda.
	 *
	 * Assure :
	 *      data_linked_sda(*sda, key)== data
	 */

void delete_data_sda(sda_t* sda, Clef key);
	/* Supprime une donnée de la sda à partir de la clé.
     * Nécessite :
	 *	sda != NULL
	 *	!empty_sda(*sda)
	 * Assure :
	 *	!used_key_sda(*sda, key)
	 */

bool used_key_sda(sda_t sda, Clef key);
	/* La clé est elle présente dans la sda ?
	 * Nécessite :
	 *   !empty_sda(sda)
	 */

Donnee data_linked_sda(sda_t sda, Clef key);
	/* Retourne la donnée associée à une clé.
	 * Nécessite :
	 *	used_key_sda(sda, key)
	 * Assure:
	 *	La donnée associée key == data_linked_sda(sda, key);
	 */

void clean_sda(sda_t* sda);
	/* Supprime toutes les données qu'elle contient
	 * Nécessite:
	 *	sda != NULL
	 *	!empty_sda(*sda)
	 * Assure :
	 *	empty_sda(*sda)
	 */

void destroy_sda(sda_t* sda);
	/* Libere toutes les ressources qu'utiliste la sda.
	 * Nécessite:
	 *	sda != NULL
	 * Assure:
	 *	sda == NULL
	 */

void print_sda(sda_t sda);
	/* Affiche la sda. */

#endif 
