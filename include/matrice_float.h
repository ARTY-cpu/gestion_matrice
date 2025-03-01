#ifndef MATRICE_FLOAT_H
#define MATRICE_FLOAT_H

typedef struct
{
    unsigned int nb_lig;
    unsigned int nb_col;
    float **coeffs;
} matrice_t;

matrice_t *allouer_matrice(unsigned int dim1, unsigned int dim2);

void saisir_matrice(matrice_t *m);

void affiche_matrice(matrice_t *m);

matrice_t *produit_matrice(matrice_t *m1, matrice_t *m2);

void desallouer_matrice(matrice_t **m);

#endif // MATRICE_FLOAT_H