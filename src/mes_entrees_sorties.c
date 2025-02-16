#include <stdlib.h>
#include <stdio.h>
#include "mes_entrees_sorties.h"

char *lire_fichier(char *nom_fichier)
{
    FILE *fichier = fopen(nom_fichier, "r");
    if (!fichier)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    fseek(fichier, 0, SEEK_END);
    long taille = ftell(fichier);
    rewind(fichier);

    char *contenu = (char *)malloc((taille + 1) * sizeof(char));
    if (!contenu)
    {
        perror("Erreur d'allocation mémoire");
        fclose(fichier);
        return NULL;
    }

    fread(contenu, sizeof(char), taille, fichier);
    contenu[taille] = '\0';

    fclose(fichier);
    return contenu;
}

void ecrire_fichier(char *nom_fichier, char *contenu)
{
    FILE *fichier = fopen(nom_fichier, "w");
    if (!fichier)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    fprintf(fichier, "%s", contenu);
    fclose(fichier);
}

matrice_t *copier_fichier(char *nom_fichier)
{
    
}