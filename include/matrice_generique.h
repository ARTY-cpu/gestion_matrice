#ifndef MATRICE_GENERIQUE_H
#define MATRICE_GENERIQUE_H

#include <stddef.h> // Pour size_t

// enum des types de coeff supportés
typedef enum
{
    TYPE_UINT8,
    TYPE_INT,
    TYPE_FLOAT
} coeff_type;

// Struct matrice générique
typedef struct
{
    unsigned int nb_lig;
    unsigned int nb_col;
    coeff_type type; // type de coeffs dans matrice générique
    void **coeffs;
} matrice_gen_t;

// proto des fonctions du module
size_t coeff_matrice_gen_size(coeff_type type);
matrice_gen_t *allouer_matrice_gen(unsigned int nb_lig, unsigned int nb_col, coeff_type type);

#endif // MATRICE_GENERIQUE_H