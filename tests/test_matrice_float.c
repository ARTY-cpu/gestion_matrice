#include "matrice_float.h"
#include "stdio.h"
#include <assert.h>

void test_matrice_non_alloue()
{
    matrice_t *mtest = NULL;
    printf("Test matrice non allouee :\n");

    affiche_matrice(mtest);
    assert(produit_matrice(mtest, mtest) == NULL);

    printf("OK\n");
}

void test_desallocation()
{
    matrice_t *mtest;
    mtest = allouer_matrice(2, 3);
    assert(mtest != NULL);
    desallouer_matrice(&mtest);
    assert(mtest == NULL);

    printf("Test desallocation OK\n");
}

int main()
{
    test_matrice_non_alloue();
    test_desallocation();

    printf("Tous les tests sont passes avec succes.\n");
    return 0;
}