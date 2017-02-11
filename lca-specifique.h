#ifndef LCA_SPECIFIQUE__H
#define LCA_SPECIFIQUE__H

#include "types.h"

struct lca {
	Clef key;
	Donnee data;
	struct lca* next;
};

typedef struct lca* lca_t;

void init_lca(lca_t* lca);
	/* Initialiser la lca en la faisant pointer
     * sur NULL;
	 *
	 * Nécessite :
	 *	lca != NULL;
	 *
	 * Assure :
	 *	empty_lca(*lca);
	 */

#endif
