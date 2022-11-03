#include <stdio.h>
#include <string.h>
#include "tp3.h"
#include <stdlib.h>

int test42() {
 printf("Test");
 return 0;
}



T_Electeur creationelecteur() {
    T_Electeur e = NULL;
    e = malloc(sizeof(struct electeur));
    printf("Creation electeur \n");

    /*
    e->choix=NULL;
    strcpy(e->nom, "Z"); //an array is not assignable.
    e->cin_num = NULL;
    e->suivant= NULL;
    */
    //printf("Création électeur \n");


    return e;
}

T_Electeur sentinelle(T_Electeur e) {
    e->choix = -1;
    strcpy(e->nom, "Sentinelle");
    e->cin_num = -1;
    e->suivant = NULL;
}

void afficheliste(T_Electeur e) {
    printf("Affiche liste\n");
    //printf("Nom :\n");
    T_Electeur tmp = e;
    if (tmp == NULL) {
        printf("NULL");
    }
    else {
        if (strcmp(tmp->nom, "Sentinelle") == 0) {
            tmp = tmp->suivant;
        }
        while (tmp != NULL) {
            printf("%s\n", tmp->nom);
            printf("%d\n", tmp->cin_num);
            tmp = tmp->suivant;
        }
    }
    printf("fin affichage liste");
}

void ajoutelecteur(T_Electeur *e, char nom_e[], long ci, int ch) {

    T_Electeur new_node = malloc(sizeof(struct electeur));
    T_Electeur last;
    new_node->cin_num = ci;
    strcpy(new_node->nom, nom_e);
    new_node->suivant = NULL;

    if (*e == NULL){
        new_node->suivant = (*e);
        *e = new_node;
    }
    else {
        last = (*e);
        while (last->suivant != NULL && (strcmp(last->suivant->nom, nom_e) < 0)) {
            last = last->suivant;
        }
        new_node->suivant = last->suivant;
        last->suivant = new_node;
    }
}

int comptelecteur(T_Electeur e) {
    int compte = 0;
    T_Electeur tmp = e;
    printf("compte electeur...\n");
    while (tmp != NULL) {
        if (strcmp(tmp->nom, "Sentinelle") != 0 ) {
            printf("%s", tmp->nom);
            compte++;

        }
        printf("Affichage de compte : ");
        printf("%d\n", compte);
        tmp = tmp->suivant;
    }

    return compte;

}

int trouvelecteur(T_Electeur e, long cin) {
    T_Electeur tmp = e;
    while (tmp != NULL && tmp->cin_num != cin) {
        tmp = tmp->suivant;
    }

    printf("Nom : ");
    printf("%s\n", tmp->nom);


    printf("Carte d'identite : ");
    printf("%ld\n", tmp->cin_num);

    printf("Choix : ");
    printf("%d\n", tmp->choix);
    return 0;

}

void Supprimelecteur(T_Electeur *e,long cin) {
    T_Electeur temp = *e;
    T_Electeur prev;
    if (temp != NULL && temp->cin_num == cin) {
        *e = temp->suivant;
        free(temp);
    }
    while (temp != NULL && temp->cin_num != cin) {
        prev = temp;
        temp = temp->suivant;
    }

    if (temp == NULL) {
        return;
    }

    prev->suivant = temp->suivant;
    free(temp);
}


void decoupeliste(T_Electeur e,T_Electeur *g,T_Electeur *d,T_Electeur*b) {
    T_Electeur tmp = e;

    while (tmp != NULL) {
        if (tmp->choix == 1 || tmp->choix == 2) {
            T_Electeur new_n = creationelecteur();
            new_n->choix = tmp->choix == 1 ? 1 : 2;
            new_n->cin_num = tmp->cin_num;
            strcpy(new_n->nom, tmp->nom);
            new_n->suivant = NULL;
            (*g)->suivant = new_n;
            (*g) = (*g)->suivant;
        }
        else if (tmp->choix == 3 || tmp->choix == 4) {
            T_Electeur new_n = creationelecteur();
            new_n->choix = tmp->choix == 3 ? 3 : 4;
            new_n->cin_num = tmp->cin_num;
            strcpy(new_n->nom, tmp->nom);
            new_n->suivant = NULL;
            (*d)->suivant = new_n;
            (*d) = (*d)->suivant;

        }

        else if (tmp->choix == 5) {
            T_Electeur new_n = creationelecteur();
            new_n->choix = tmp->choix == 3 ? 3 : 4;
            new_n->cin_num = tmp->cin_num;
            strcpy(new_n->nom, tmp->nom);
            new_n->suivant = NULL;
            (*b)->suivant = new_n;
            (*b) = (*b)->suivant;


        }
    }
}

void triliste(T_Electeur *e) {
    T_Electeur result = NULL;
    T_Electeur current = (*e);
    T_Electeur next;

    while (current != NULL) {
        next = current->suivant;

        ajoutelecteur(&result, current->nom, current->cin_num, current->choix);
        current = next;


    }

    *e = result;


}

void libereliste(T_Electeur e) {

    while (e != NULL) {
        T_Electeur tmp = e;
        e = e->suivant;
        free(tmp);
    }

}

