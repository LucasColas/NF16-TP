#include "tp4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

t_ListePositions* creer_liste_positions() {
    t_ListePositions* liste_positions = malloc(sizeof(t_ListePositions));
    if (!liste_positions) {
        printf("Erreur");
        return NULL;

    }
    return liste_positions;
}

t_Index* creer_index() {

    t_Index* nouveau_index = malloc(sizeof(t_Index));
    if (!nouveau_index) {
        printf("erreur\n");
        return NULL;
    }
    //printf("Index cree \n");
    return nouveau_index;
}


int ajouter_position(t_ListePositions *listeP, int ligne, int ordre, int num_phrase) {
    //printf("%d\n", ligne);
    //printf("%d\n", ordre);
    //printf("%d\n", num_phrase);
    t_Position* noeud = malloc(sizeof(t_Position));
    if (listeP->debut != NULL) {
        printf("%d", listeP->debut->numero_ligne);
    }
    if (!noeud) {
        printf("Erreur malloc\n");
        return 0;
    }
    else {
        printf("Succes \n");
    }
    noeud->numero_ligne=ligne;
    noeud->ordre=ordre;
    noeud->numero_phrase=num_phrase;
    noeud->suivant=NULL;


    if (listeP->debut==NULL){
        printf("Debut null \n");
        listeP->debut=noeud;
        listeP->nb_elements+=1;

    }
    else if (ligne<listeP->debut->numero_ligne||(ligne==listeP->debut->numero_ligne&&ordre<listeP->debut->ordre)){
        //printf("dans else if \n");
        noeud->suivant=listeP->debut;
        listeP->debut=noeud;
        listeP->nb_elements+=1;
    }
    else {
        //printf("dans else \n");
        t_Position* pos=listeP->debut;
        t_Position* apres=pos->suivant;
        while((apres!=NULL) && (ligne> apres->numero_ligne)){
              pos=pos->suivant;
              apres=pos->suivant;
              }
        if(apres==NULL){
            pos->suivant=noeud;
        }
        else if (ligne!= apres->numero_ligne){
            noeud->suivant=apres;
            pos->suivant=noeud;
        }
        else{
                while((apres!=NULL) && (ligne == apres->numero_ligne) && (ordre> apres->ordre)){
                      pos=pos->suivant;
                      apres=pos->suivant;
                }
                if(apres==NULL){
                    pos->suivant=noeud;
                }
                else {
                    noeud->suivant=apres;
                    pos->suivant=noeud;
                }
        }
        listeP->nb_elements+=1;
    }
    printf("Position ajoutee \n");
    return 1;
}

int fusion_pos(t_ListePositions *listeP, t_Position* noeud,int ligne, int ordre, int num_phrase) {
    //printf("%d\n", ligne);
    //printf("%d\n", ordre);
    //printf("%d\n", num_phrase);
    if (listeP->debut != NULL) {
        //printf("%d", listeP->debut->numero_ligne);
    }

    else {
        printf("Succes\n");
    }

    if (listeP->debut==NULL){
        printf("Debut null\n");
        listeP->debut=noeud;
        listeP->nb_elements+=1;

    }
    else if (ligne<listeP->debut->numero_ligne||(ligne==listeP->debut->numero_ligne&&ordre<listeP->debut->ordre)){
        //printf("dans else if \n");
        noeud->suivant=listeP->debut;
        listeP->debut=noeud;
        listeP->nb_elements+=1;
    }
    else {
        //printf("dans else \n");
        t_Position* pos=listeP->debut;
        t_Position* apres=pos->suivant;
        while((apres!=NULL) && (ligne> apres->numero_ligne)){
              pos=pos->suivant;
              apres=pos->suivant;
              }
        if(apres==NULL){
            pos->suivant=noeud;
        }
        else if (ligne!= apres->numero_ligne){
            noeud->suivant=apres;
            pos->suivant=noeud;
        }
        else{
                while((apres!=NULL) && (ligne == apres->numero_ligne) && (ordre> apres->ordre)){
                      pos=pos->suivant;
                      apres=pos->suivant;
                }
                if(apres==NULL){
                    pos->suivant=noeud;
                }
                else {
                    noeud->suivant=apres;
                    pos->suivant=noeud;
                }
        }
        listeP->nb_elements+=1;
    }
    //printf("Position ajoutee \n");
    return 1;
}

t_Noeud* trouver_mot(t_Noeud* racine, char *mot) {

    if (racine == NULL) {
        return NULL;
    }
    //printf("Mot : %s\n", racine->mot);
    char val_noeud[100];
    strcpy(val_noeud, racine->mot);
    //printf("strcpy\n");
    for (int i = 0; val_noeud[i] != '\0'; i++) {
        val_noeud[i] = tolower(val_noeud[i]);
    }
    if (strcmp(mot, val_noeud) == 0) {
        //printf("Mot trouve\n");
        //printf("Le mot : %s\n", racine->mot);
        //printf("Mot trouve et affiche\n");
        return racine;
    }

    if (strcmp(mot, val_noeud) > 0) {
        return trouver_mot(racine->filsDroit, mot);

    }
    else {
        return trouver_mot(racine->filsGauche, mot);
    }


}
t_Noeud* rechercher_mot(t_Index *index, char *mot)
{
        if (index == NULL) {
            printf("index vide\n");
        }
        if (index->nb_mots_total == 0) {
            printf("arbre vide\n");
        }
        t_Noeud* parcoureur;
        parcoureur = index->racine;
        char mot_lower[100];
        strcpy(mot_lower, mot);
        for (int i = 0; mot_lower[i] != '\0'; i++) {
            mot_lower[i] = tolower(mot_lower[i]);
        }
        t_Noeud* racine = index->racine;
        while (racine != NULL) {
            char mot_noeud[100];
            strcpy(mot_noeud, racine->mot);
            for (int i = 0; mot_noeud[i] != '\0'; i++) {
                mot_noeud[i] = tolower(mot_noeud[i]);
            }

            if (strcmp(mot_lower, mot_noeud) == 0) {
                printf("Mot trouve \n");
                return racine;
            }

            else if (strcmp(mot_lower, mot_noeud) > 0) {
                racine = racine->filsDroit;
            }

            else {
                racine = racine->filsGauche;
            }

        }

        return NULL;
}



int ajouter_noeud(t_Index *index, t_Noeud *noeud)
{
    //printf("%d\n", noeud->positions.debut->numero_ligne);
    if(index->racine==NULL)
    {
        //printf("racine nulle\n");
        //printf("Affectation parcoureur a noeud");
        char val_noeud[100];
        //printf("mot : %s\n", noeud->mot);
        strcpy(val_noeud, noeud->mot);
        for (int i = 0; val_noeud[i] != '\0'; i++) {
            val_noeud[i] = tolower(val_noeud[i]);
        }
        index->racine = noeud;
        strcpy(index->racine->mot, val_noeud);
        index->nb_mots_differents = 1;
        index->nb_mots_total = 1;
        //printf("Mot quand index etait null a la base : %s", index->racine->mot);
        //printf("Fin affectation\n");
        return 1;
    }
    t_Noeud* curr = index->racine;
    t_Noeud* x = curr;
    char val_noeud[100];
    //printf("mot : %s\n", noeud->mot);
    strcpy(val_noeud, noeud->mot);
    for (int i = 0; val_noeud[i] != '\0'; i++) {
        val_noeud[i] = tolower(val_noeud[i]);
    }
    strcpy(noeud->mot, val_noeud);

    //printf("val noeud : %s\n", val_noeud);
    /*if (strcmp(val_noeud, "la") == 0) {
        printf("mot original : %s", noeud->mot);
        printf(" la\n");

    }*/

    while (curr != NULL) {
        //printf("in while\n");
        x = curr;
        char val_noeud_acc[100];
        //printf("strcpy \n");
        strcpy(val_noeud_acc, x->mot);
        //printf("copie \n");
        for (int i = 0; val_noeud_acc[i] != '\0'; i++) {
            val_noeud_acc[i] = tolower(val_noeud_acc[i]);
        }
        //printf("%s\n", val_noeud_acc);


        int comp = strcmp(val_noeud, val_noeud_acc);
        if (comp == 0) {
            //printf("Les chaines sont identiques\n");
            //printf("%s", val_noeud);
            //printf("%s", val_noeud_acc);
            t_ListePositions* liste = &(x->positions);
            fusion_pos(liste, noeud->positions.debut, noeud->positions.debut->numero_ligne, noeud->positions.debut->ordre, noeud->positions.debut->numero_phrase);

            x->nb_occurences++;
            index->nb_mots_total++;
            /*if (strcmp(val_noeud_acc, "la") == 0) {
                printf("nb occ de la : %d\n", x->nb_occurences);
                printf("num ligne : %d\n", noeud->positions.debut->numero_ligne);
                printf("ordre : %d\n", noeud->positions.debut->ordre);
                printf("num phrase : %d\n\n\n", noeud->positions.debut->numero_phrase);
                //printf("premiere pos %d\n", x->positions.debut->numero_ligne);

            }*/

            //printf("Fusion \n");
            return 0;

        }

        if (comp < 0) {
            //printf("Passe dans fils gauche\n");
            curr = x->filsGauche;

        }

        else {
            //printf("Passe dans fils droit\n");
            curr = x->filsDroit;
        }

    }
    //printf("Apres while \n");

    char val_noeud_acc[100];
    strcpy(val_noeud_acc, x->mot);
    for (int i = 0; val_noeud_acc[i] != '\0'; i++) {
        val_noeud_acc[i] = tolower(val_noeud_acc[i]);
    }
    //printf("Val noeud acc : %s\n", val_noeud_acc);

    int comp = strcmp(val_noeud, val_noeud_acc);
    if (comp == 0) {
        //printf("Les chaines sont identiques");
        return 0;

    }

    if (comp < 0) {
        //printf("Ajoute dans fils gauche");
        x->filsGauche = noeud;
        x->filsGauche->filsGauche = NULL;
        x->filsGauche->filsDroit = NULL;
        index->nb_mots_total++;
        index->nb_mots_differents++;
    }

    else {
        //printf("Ajoute dans fils droit");
        x->filsDroit = noeud;
        x->filsDroit->filsGauche = NULL;
        x->filsDroit->filsDroit = NULL;
        index->nb_mots_total++;
        index->nb_mots_differents++;
    }

    return 1;

    /*
    while(parcoureur->filsDroit!=NULL)
    {
        int comp=strcmp(tolower(parcoureur->mot),tolower(noeud->mot));
        if(comp>0)
        {
            t_Noeud* precedent=parcoureur->filsGauche;
            precedent->filsDroit=noeud;
            noeud->filsGauche=parcoureur->filsGauche;
            parcoureur->filsGauche=noeud;
            noeud->filsDroit=parcoureur;
            return 1;
        }
        if(comp==0)
        {
            return 0;
        }
    }
    parcoureur->filsDroit=noeud;
    noeud->filsGauche=parcoureur;
    */

}


void viderBuffer() //Vide le buffer
{
  int c;
  do {
    c = getchar();

  } while (c != EOF && c != '\n');
}

int height(t_Noeud* racine) {

    if (racine==NULL) {
        return 0;
    }

    int left = height(racine->filsGauche);
    int right = height(racine->filsDroit);

    if (left >= right) {
        return (left+1);
    }

    else {
        return (right+1);
    }
}

int indexEquilibre(t_Noeud *racine)
{

    if (racine == NULL) {
        printf("Arbre null\n");
        return 1;
    }

    int l = height(racine->filsGauche);
    int r = height(racine->filsDroit);
    return (abs(l - r) <= 1 && indexEquilibre(racine->filsGauche) && indexEquilibre(racine->filsDroit));

}


int indexer_fichier(t_Index *index, char *filename) {
    //printf("In indexer fichier\n");
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    int phrase_num = 1;
    int ligne_num = 1;
    int ordre_num = 1;

    filePointer = fopen(filename, "r");
    if (!filePointer) {
        printf("Erreur...\n ");
        return 0;
    }
    //printf("Fichier lu\n");
    while(fgets(buffer, bufferLength, filePointer)) {
        //printf("Dans while\n");
        int i = 0;
        ordre_num = 1;
        char mot[100] = "";
        while (buffer[i] != '\0') {
                //printf("%c\n", buffer[i]);
            //printf("%c", buffer[i]);
            int res = isspace(buffer[i]);
            //printf(" %d\n", res);
            if (isspace(buffer[i]) == 0 && buffer[i] != '.') {
                //printf("Parti du mot\n");
                //printf("Pas un espace\n");
                //printf("%c", buffer[i]);
                strncat(mot, &buffer[i], 1);
            }
            else {
                //printf("FIn du mot\n");
                if (mot[0] != '\0') {
                    //printf("Le mot : ");
                    //printf("%s\n", mot);

                    //printf("Ordre : %d\n", ordre_num);
                    //printf("phrase : %d\n", phrase_num);
                    //printf("num ligne : %d\n", ligne_num);
                    //printf("\n\n");
                    t_Noeud* noeud = malloc(sizeof(t_Noeud));
                    if (!noeud) {
                        printf("Erreur malloc");
                    }
                    noeud->nb_occurences = 1;
                    noeud->mot = malloc(100*sizeof(char));
                    strcpy(noeud->mot, mot);


                    noeud->positions.debut = malloc(sizeof(t_Position));
                    noeud->positions.debut->numero_ligne = ligne_num;
                    noeud->positions.debut->numero_phrase = phrase_num;
                    noeud->positions.debut->ordre = ordre_num;
                    noeud->positions.debut->suivant = NULL;
                    noeud->filsDroit = NULL;
                    noeud->filsGauche = NULL;
                    //printf("%s%s\n", mot, noeud->mot);
                    ajouter_noeud(index, noeud);

                    ordre_num++;
                    strcpy(mot, "");
                    if (buffer[i] == '.') {
                        //printf("Le mot est un point\n");
                        //ordre_num++;
                        //création et affectation noeud ici
                        //t_Noeud* noeud = malloc(sizeof(t_Noeud));
                        phrase_num++;
                    }

                }

            }

            i++;

        }
        ligne_num++;
        //printf("%s\n", buffer);
    }
    fclose(filePointer);
    return 1;
}


void pre_order_traversal(t_Noeud* racine) {
   if(racine != NULL) {
      printf("%s \n",racine->mot);
      pre_order_traversal(racine->filsGauche);
      pre_order_traversal(racine->filsDroit);
   }
}

void trouver_max_apparition(t_Noeud* racine, int* o_max, char* mot) {
    if (racine == NULL) {
        return;
    }

    if (racine->nb_occurences > *o_max) {
        //printf("nouveau mac occ\n");
        (*o_max) = racine->nb_occurences;
        //printf("Changement o_max\n");

        strcpy(mot, racine->mot);
        //printf("Changement effectué");
    }

    trouver_max_apparition(racine->filsDroit, o_max, mot);
    trouver_max_apparition(racine->filsGauche, o_max, mot);
}
void afficher_max_apparition(t_Index *index) {
    if (index->racine == NULL) {
        printf("Arbre vide\n");
        return;
    }
    printf("Dans afficher max\n");
    t_Noeud* racine = index->racine;
    t_Noeud* max = NULL;
    int o_max = 0;
    char* mot = malloc(100*sizeof(char));
    trouver_max_apparition(racine, &o_max, mot);
    printf("Occ max : %d\n", o_max);
    printf("mot : %s\n", mot);
}

void recherche_mots(t_Noeud* racine, char c, int lettre_affiche) {


    if (!racine) {

        return;
    }
    recherche_mots(racine->filsGauche, c, lettre_affiche);
    char val_noeud[100];
    strcpy(val_noeud, racine->mot);

    for (int i = 0; val_noeud[i] != '\0'; i++) {
        val_noeud[i] = tolower(val_noeud[i]);
    }
    //printf("val noeud: %s\n", val_noeud);
    if (val_noeud[0] == tolower(c)) {
        if (lettre_affiche == 0) {
            printf("%c\n", c);
            lettre_affiche = 1;
        }
        printf("|--%s\n", val_noeud);
        t_Position* pos = racine->positions.debut;
        while (pos != NULL) {
            printf("|--- l:%d", pos->numero_ligne);
            printf(" o:%d", pos->ordre);
            printf(" p:%d", pos->numero_phrase);
            printf("\n\n");
            pos = pos->suivant;
        }
    }

    recherche_mots(racine->filsDroit, c, lettre_affiche);

}

void afficher_index(t_Index *index) {
    if (index == NULL) {
        printf("Arbre vide \n");
        return;
    }
    if (index->nb_mots_total == 0) {
        printf("arbre vide\n");
        return;
    }

    char c;
    for (c = 'A'; c <= 'Z'; c++) {
        //printf("c : %c\n", c);
        recherche_mots(index->racine, c, 0);
    }

}

void ajouter_noeud_liste(l_Noeud** tete, int num_ligne, int ordre, int num_phrase, char* mot) {
    l_Noeud* nouv_noeud = malloc(sizeof(l_Noeud));
    if (!nouv_noeud) {
        printf("erreur\n");
    }
    l_Noeud* dernier = *tete;
    //printf("affectation valeurs\n");
    nouv_noeud->num_ligne = num_ligne;
    nouv_noeud->num_phrase = num_phrase;
    nouv_noeud->ordre = ordre;
    nouv_noeud->mot = malloc(100*sizeof(char));
    strcpy(nouv_noeud->mot, mot);
    nouv_noeud->suivant = NULL;
    //printf("valeurs affectées\n");
    if (*tete == NULL) {
        *tete = nouv_noeud;
        return;
    }

    while (dernier->suivant != NULL) {
        dernier = dernier->suivant;
    }
    dernier->suivant = nouv_noeud;

}


void creation_liste(t_Noeud* racine, l_Noeud** tete) {
    if (racine != NULL) {
        //parcourir jusqu'à la fin des pos
        t_Position* x = racine->positions.debut;
        while (x != NULL) {
            ajouter_noeud_liste(tete, x->numero_ligne, x->ordre, x->numero_phrase, racine->mot);
            x = x->suivant;
        }
        creation_liste(racine->filsGauche, tete);
        creation_liste(racine->filsDroit, tete);
    }

}

void swap(l_Noeud* a, l_Noeud* b) {
    //printf("Dans swap fonction\n");
    int num_ligne = a->num_ligne;
    int ordre = a->ordre;
    int num_phrase = a->num_phrase;
    char mot_temp[100];

    strcpy(mot_temp, a->mot);
    //printf("premier strcpy\n");
    a->num_ligne = b->num_ligne;
    a->num_phrase = b->num_phrase;
    a->ordre = b->ordre;
    strcpy(a->mot, b->mot);
    //printf("deuxieme strcpy\n");
    b->num_ligne = num_ligne;
    b->num_phrase = num_phrase;
    b->ordre = ordre;
    strcpy(b->mot, mot_temp);
    //printf("swap terminé\n");
}

void trie_liste_ligne(l_Noeud** tete) {
    if ((*tete) == NULL || (*tete)->suivant == NULL) {
        return;
    }
    //printf("Dans trie list\n");
    l_Noeud* start = *tete;
    int swapped, i;
    l_Noeud* ptr1;
    l_Noeud* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = start;
        //printf("Dans do while\n");

        while (ptr1->suivant != lptr) {
            //printf("Dans while\n");
            if (ptr1->num_ligne > ptr1->suivant->num_ligne) {
                //printf("Dans if\n");
                swap(ptr1, ptr1->suivant);
                //printf("Après swap\n");
                swapped = 1;
            }
            ptr1 = ptr1->suivant;
        }
        lptr = ptr1;
    }
    while (swapped);

}

void trie_liste_ordre(l_Noeud** tete) {
    if ((*tete) == NULL || (*tete)->suivant == NULL) {
        return;
    }
    //printf("Dans trie list\n");
    l_Noeud* start = *tete;
    int swapped, i;
    l_Noeud* ptr1;
    l_Noeud* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = start;
        //printf("Dans do while\n");

        while (ptr1->suivant != lptr) {
            //printf("Dans while\n");
            if (ptr1->ordre > ptr1->suivant->ordre && ptr1->num_ligne == ptr1->suivant->num_ligne) {
                //printf("Dans if\n");
                swap(ptr1, ptr1->suivant);
                //printf("Après swap\n");
                swapped = 1;
            }
            ptr1 = ptr1->suivant;
        }
        lptr = ptr1;
    }
    while (swapped);

}

void free_liste(l_Noeud** tete) {
    if (*tete == NULL) {
        return;
    }

    l_Noeud* curr = *tete;
    l_Noeud* next = NULL;
    while (curr != NULL) {
        //printf("Suppression");
        next = curr->suivant;
        free(curr->mot);
        free(curr);
        curr = next;
    }
}

void affiche_phrase(l_Noeud** tete, int num_phrase) {
    //printf("Dans affiche phrase\n");
    l_Noeud *temp = *tete;
    while (temp != NULL) {

        if (temp->num_phrase == num_phrase) {
            //printf("Ligne : %d mot : %d",temp->num_ligne, temp->ordre);
            printf("%s ", temp->mot);
        }
        //printf("\n");

        temp = temp->suivant;
    }
    printf("\n");
}


void afficher_occurences_mot(t_Index *index, char *mot) {
    if (index->racine == NULL) {
        printf("arbre vide");
        return;
    }
    l_Noeud* tete = NULL;
    creation_liste(index->racine, &tete);
    trie_liste_ligne(&tete);
    trie_liste_ordre(&tete);
    t_Noeud* mot_rech = rechercher_mot(index, mot);
    if (mot_rech == NULL) {
        printf("Mot non trouve\n");

    }
    else {
        t_Position* pos = mot_rech->positions.debut;
        printf("Occurences : %d\n", mot_rech->nb_occurences);
        while (pos != NULL) {
            affiche_phrase(&tete, pos->numero_phrase);
            pos = pos->suivant;
        }
    }
    free_liste(&tete);

}

void construction_texte(l_Noeud** tete, char* filename) {
    l_Noeud* temp = *tete;
    int nouvelle_phrase = 1;
    int debut = 1;
    int nouvelle_ligne = 0;
    FILE *f = fopen(filename, "w");

    if (!f) {
        printf("erreur ouverture\n");

    }
    while (temp != NULL) {

        if (nouvelle_phrase) {
            char mot_ac[100];
            strcpy(mot_ac, temp->mot);
            if (mot_ac[0] != '\0') {
                mot_ac[0] = toupper(mot_ac[0]);
            }
            if (temp->suivant != NULL && temp->suivant->num_phrase != temp->num_phrase) {
                if (debut) {
                    fprintf(f,"%s ", mot_ac);
                    printf("%s ", mot_ac);
                    debut = 0;
                }
                else {
                    fprintf("%s ", mot_ac);
                    printf("%s ", mot_ac);
                }

            }
            else {
                if (debut) {
                    fprintf(f,"%s ", mot_ac);
                    printf("%s ", mot_ac);
                    debut = 0;
                }
                else {
                    if (nouvelle_ligne) {
                        fprintf(f,"%s ", mot_ac);
                        printf("%s ", mot_ac);
                    }
                    else {
                        fprintf(f," %s ", mot_ac);
                        printf(" %s ", mot_ac);
                    }

                }

            }

            nouvelle_phrase = 0;
        }
        else {
            if (temp->suivant != NULL && temp->suivant->num_phrase != temp->num_phrase) {
               fprintf(f,"%s", temp->mot);
               printf("%s", temp->mot);
            }
            else {
                if (temp->suivant == NULL) {
                    fprintf(f,"%s", temp->mot);
                    printf("%s", temp->mot);
                    //fprintf(f,".");
                    //printf(".");

                }
                else {
                    fprintf(f,"%s ", temp->mot);
                    printf("%s ", temp->mot);

                }

                //fprintf(f,"%s ", temp->mot);
                //printf("%s ", temp->mot);
            }
        }
        int n_ligne = temp->num_ligne;
        int n_phrase = temp->num_phrase;
        temp = temp->suivant;
        if (temp != NULL && temp->num_phrase != n_phrase) {
            nouvelle_phrase = 1;
            fprintf(f,".");
            printf(".");

        }

        if (temp != NULL && n_ligne != temp->num_ligne) {
            fprintf(f,"\n");
            printf("\n");
        }
        if (temp == NULL) {
            fprintf(f,".");
            printf(".");

        }

    }
    //fprintf(f,".");
    //printf(".");
    fclose(f);
}

void construire_texte(t_Index* index, char* filename) {
    if (index->racine == NULL) {
        printf("Arbre vide\n");
        return;
    }
    l_Noeud* tete = NULL;
    creation_liste(index->racine, &tete);
    trie_liste_ligne(&tete);
    trie_liste_ordre(&tete);
    construction_texte(&tete, filename);
    free_liste(&tete);
}



void freeIndex(t_Noeud* racine) {
    if (racine == NULL) {
        return;
    }
    freeIndex(racine->filsGauche);
    freeIndex(racine->filsDroit);
    free(racine->mot);
    t_Position* tete = racine->positions.debut;
    t_Position* tmp;
    while (tete != NULL) {
        tmp = tete;
        tete = tete->suivant;
        free(tmp);
    }
    free(racine);
}
