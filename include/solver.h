#ifndef SOLVER_H
#define SOLVER_H

#define MAX_MOTS 10000
#define LEN_MOTS 6

int charger_dict(char mots[][LEN_MOT], const char *chemin);
void afficher_mot(char mots[][LEN_MOT], int nb);

int filtre_contient(char mots[][LEN_MOT], int nb, char lettre, char res[][LEN_MOT]);
int filtre_exclut(char mots[][LEN_MOT],int nb, char lettre, char res[][LEN_MOT]);
int filtre_position(char mots[][LEN_MOT],int  nb, char lettre, char pos, char res[][LEN_MOT]);


#endif
