#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

/*Data Structures*/
struct t_position {
    int numero_ligne;
    int ordre;
    int numero_phrase;
    struct t_position* suivant;
};

typedef struct t_position t_Position;

struct t_listePositions{
    t_Position* debut;
    int nb_elements;

};

typedef struct t_listePositions t_ListePositions;



typedef struct l_noeud l_Noeud;
struct l_noeud {
    char* mot;
    int num_ligne;
    int ordre;
    int num_phrase;
    struct l_noeud* suivant;
};


typedef struct t_noeud t_Noeud;
struct t_noeud {
    char* mot;
    int nb_occurences;
    t_ListePositions positions;
    t_Noeud* filsGauche;
    t_Noeud* filsDroit;
};




struct t_index {
    t_Noeud* racine;
    int nb_mots_differents;
    int nb_mots_total;
};

typedef struct t_index t_Index;


t_ListePositions* creer_liste_positions();

int ajouter_position(t_ListePositions* listeP, int ligne, int ordre, int num_phrase);

t_Index* creer_index();

t_Noeud* rechercher_mot(t_Index *index, char *mot);

int ajouter_noeud(t_Index* index, t_Noeud* noeud);
int Fonctiontest(t_Index *index, t_Noeud *noeud);

int indexer_fichier(t_Index* index, char* filename);

void afficher_index(t_Index * index);

void afficher_max_apparition(t_Index* index);

void afficher_occurences_mot(t_Index* index, char* mot);

void viderBuffer();
int indexer_fichier(t_Index *, char *);
void pre_order_traversal(t_Noeud*);
void afficher_max_apparition(t_Index *);
void afficher_index(t_Index *);
void creation_liste(t_Noeud*, l_Noeud**);
void trie_liste_ligne(l_Noeud**);
void trie_liste_ordre(l_Noeud**);
int indexEquilibre(t_Noeud *);
void affiche_phrase(l_Noeud**, int);
void afficher_occurences_mot(t_Index *, char *);
void construction_texte(l_Noeud**, char*);
void freeIndex(t_Noeud*);

#endif // TP4_H_INCLUDED
