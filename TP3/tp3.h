#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

extern struct electeur {
    char nom[50];
    long cin_num;
    int choix;
    struct electeur* suivant;
};

typedef struct electeur* T_Electeur;

int test42();
T_Electeur creationelecteur();
void ajoutelecteur(T_Electeur *, char [], long, int );
T_Electeur sentinelle(T_Electeur);
int comptelecteur(T_Electeur);
int trouvelecteur(T_Electeur, long);
void afficheliste(T_Electeur);
void decoupeliste(T_Electeur,T_Electeur *,T_Electeur *,T_Electeur*);

void Supprimelecteur(T_Electeur *,long);
void decoupeliste(T_Electeur,T_Electeur *,T_Electeur *,T_Electeur*);
void libereliste(T_Electeur);
void triliste(T_Electeur *e);


#endif // TP3_H_INCLUDED
