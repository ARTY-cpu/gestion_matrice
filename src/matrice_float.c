#include <stdlib.h>
#include <stdio.h>
#include "matrice_float.h"

matrice_t *allouer_matrice(unsigned int dim1, unsigned int dim2)
{
    matrice_t *m = NULL;
    m = (matrice_t *)malloc(sizeof(matrice_t));
    m->nb_lig = dim1;
    m->nb_col = dim2;
    m->coeffs = (float **)malloc(m->nb_lig * sizeof(float *));

    for (int i = 0; i < m->nb_lig; i++)
    {
        m->coeffs[i] = (float *)malloc(m->nb_col * sizeof(float));
    }

    return m;
}

void saisir_matrice(matrice_t *m)
{
    for (int i = 0; i < m->nb_lig; i++)
    {
        for (int j = 0; j < m->nb_col; j++)
        {
            printf("Entrez valeur pour ligne %d et colonne %d :", i, j);
            scanf("%f", &m->coeffs[i][j]);
        }
    }
    return;
}

void affiche_matrice(matrice_t *m)
{
    if (m == NULL)
    {
        return;
    }

    for (int i = 0; i < m->nb_lig; i++)
    {
        for (int j = 0; j < m->nb_col; j++)
        {
            printf("%f ", m->coeffs[i][j]);
            if (j == m->nb_col - 1)
            {
                printf("\n");
            }
        }
    }
    return;
}

matrice_t *produit_matrice(matrice_t *m1, matrice_t *m2)
{

    if (m1 == NULL || m2 == NULL)
    {
        printf("Erreur : Matrice(s) non definie(s)");
        return NULL;
    }

    if (m1->nb_lig != m2->nb_col)
    {
        printf("Erreur : Calcul Impossible");
        return NULL;
    }

    matrice_t *pm;
    pm = allouer_matrice(m1->nb_lig, m2->nb_col);

    for (int i = 0; i < pm->nb_lig; i++)
    {
        for (int j = 0; j < pm->nb_lig; j++)
        {
            for (int k = 0; k < pm->nb_lig; k++)
            {
                pm->coeffs[i][j] = m1->coeffs[i][k] * m2->coeffs[j][k];
            }
        }
    }

    return pm;
}

void desallouer_matrice(matrice_t **m)
{
    for (int i = 0; i < (*m)->nb_lig; i++)
    {
        free((*m)->coeffs[i]);
    }
    free((*m)->coeffs);
    free((*m));
    (*m) = NULL;
    return;
}