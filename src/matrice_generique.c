#include <stdio.h>
#include <stdlib.h>
#include "matrice_generique.h"

size_t coeff_matrice_gen_size(coeff_type type)
{
    switch (type)
    {
    case TYPE_UINT8:
        return sizeof(unsigned char);
        break;

    case TYPE_INT:
        return sizeof(int);
        break;

    case TYPE_FLOAT:
        return sizeof(float);
        break;

    default:
        fprintf(stderr, "ERREUR type non supporte...");
        exit(EXIT_FAILURE);
    }
}

matrice_gen_t *allouer_matrice_gen(unsigned int nb_lig, unsigned int nb_col, coeff_type type)
{
    matrice_gen_t *m = (matrice_gen_t *)malloc(sizeof(matrice_gen_t));

    // tester si m != null
    m->nb_lig = nb_lig;
    m->nb_col = nb_lig;

    m->coeffs = (void **)malloc((m->nb_lig) * sizeof(void *));
    // tester si le pointeur renvoye != null

    for (unsigned int i = 0; i < m->nb_lig; i++)
    {
        m->coeffs[i] = (void *)malloc((m->nb_col) * coeff_matrice_gen_size(m->type));
    }

    return m;
}

void desallouer_matrice_gen(matrice_gen_t **m)
{
    for (unsigned int i = 0; i < (*m)->nb_lig; i++)
    {
        free((*m)->coeffs[i]);
    }
    free((*m)->coeffs);
    free(*m);
    *m = NULL;
    return;
}