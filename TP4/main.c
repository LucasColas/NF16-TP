#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tp4.h"

int main() {

    printf("Hello World\n");
    //printf("Apres creer index");
    t_ListePositions* test = creer_liste_positions();
    /*
    test->debut->numero_ligne = 2;
    printf("%d", test->debut->numero_ligne);
    test->debut->numero_phrase = 4;
    printf("%d", test->debut->numero_phrase);
    test->debut->ordre = 5;
    printf("%d", test->debut->ordre);
    test->debut->suivant = NULL;
    printf("Suivant \n");
    */
    /*
    t_Index* index = creer_index();
    index->racine->mot = strdup("Alpaga");
    //printf("%s", index->racine->mot);
    t_ListePositions lis = index->racine->positions;
    lis.nb_elements = 0;
    lis.debut = NULL;
    t_ListePositions* lis_ptr = &lis;
    ajouter_position(lis_ptr, 3,4,4);
    index->racine->positions = *lis_ptr;
    index->racine->filsDroit = NULL;
    index->racine->filsGauche = NULL;

    //printf("%d", index->racine->positions.debut->numero_ligne);

    t_Noeud* noeud2 = malloc(sizeof(t_Noeud));
    printf("strdup");
    noeud2->filsGauche = NULL;
    noeud2->filsDroit = NULL;
    noeud2->mot = strdup("bateau");
    printf("Ajout noeud2");
    ajouter_noeud(index, noeud2);
    //printf("%s", index->racine->filsDroit->mot);
    rechercher_mot(index, "bateau");
    */
    t_Index* index = creer_index();
    index->racine = NULL;
    index->nb_mots_total = 0;
    index->nb_mots_differents = 0;


    int choix;
    char mot_user[100];
    l_Noeud* tete = NULL;
    t_Noeud* noeud_rech;
    t_Position* pos;
    int H;
    char c;

    int choixMenu;

    do {
        printf("\n========================================");
        printf("\n  1 - Charger un fichier");
        printf("\n  2 - Caracteristiques de l'index");
        printf("\n  3 - Afficher Index ");
        printf("\n  4 - Rechercher un mot");
        printf("\n  5 - Afficher le mot avec le max d'apparitions");
        printf("\n  6 - Afficher les occurences d'un mot");
        printf("\n  7 - Construire le texte à partir de l'index");
        printf("\n  8 - Quitter");
        printf("\n========================================");
        printf("\nVotre choix : ");
        scanf("%d", &choixMenu);
        viderBuffer();

        switch(choixMenu) {
        case 1 :
            /*C:\\Users\\lucas\\Desktop\\Cours\\NF16\\TP4\\
            */
            indexer_fichier(index, "..//texte_tp4.txt");
            printf("Nombre de mots lus : %d\n", index->nb_mots_total);
            break;

        case 2 :
            H = indexEquilibre(index->racine);
            if (H) {
                printf("Equilibre \n");

            }

            else {
                printf("Pas equilibre\n");
            }

            printf("Nombre de mots differents : %d\n", index->nb_mots_differents);
            break;

        case 3 :
            afficher_index(index);
            break;

        case 4 :
            printf("Rechercher un mot : ");
            scanf("%s", mot_user);
            viderBuffer();
            noeud_rech = rechercher_mot(index, mot_user);
            if (noeud_rech == NULL) {
                printf("Mot non trouve\n");
            }
            else {
                pos = noeud_rech->positions.debut;
                while (pos != NULL) {
                    printf("num ligne : %d\n", pos->numero_ligne);
                    printf("num ordre : %d\n", pos->ordre);
                    //printf("num phrase : %d\n", pos->numero_phrase);
                    printf("phrase : %d\n", pos->numero_phrase);
                    printf("\n");
                    pos = pos->suivant;
                }
            }
            break;

        case 5 :
            afficher_max_apparition(index);
            break;

        case 6 :
            printf("Le mot a recherche : \n");
            scanf("%s", mot_user);
            viderBuffer();
            afficher_occurences_mot(index, mot_user);
            break;

        case 7 :
            construire_texte(index, "C:\\Users\\lucas\\Desktop\\Cours\\NF16\\TP4\\texte2.txt");
            break;


            //viderBuffer();

        case 8:
            freeIndex(index->racine);
            free(index);
            index = NULL;
            break;

        }

    } while (choixMenu != 8);
    printf("\n\n*** FIN DU PROGRAMME ***\n");


    return 0;
}
