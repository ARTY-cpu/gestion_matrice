#include "matrice_float.h"
#ifndef MES_ENTREES_SORTIES_H
#define MES_ENTREES_SORTIES_H

char *lire_fichier(char *nom_fichier);
void ecrire_fichier(char *nom_fichier, char *contenu);
matrice_t *copier_fichier(char *nom_fichier);

#endif // MES_ENTREES_SORTIES_H