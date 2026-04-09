#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "solver.h"

int charger_dict(char mots[][LEN_MOT], const char *chemin){

	FILE *f =fopen(chemin,"r");

	if(!f){
		perror("Erreur ouverture fichier");
		return 0;
	}

	char ligne[32];
	int nb = 0;

	while(fgets(ligne, sizeof(ligne),f) && nb < MAX_MOTS) {

		ligne[strcspn(ligne,"\n")] = '\0';

		if(strlen(ligne) == 5) {
			int ok = 1;
			for(int i = 0; i < 5; i++){
				if(!isalpha(ligne[i])) {
					ok = 0;
					break;
				}
			if (ok) strcpy(mots[nb++], ligne);

			}
		}
	}
	fclose(f);
	return nb;
}

void afficher_mots(char mots[][LEN_MOT], int nb, const char *mot){
	printf("\n%d mot(s) possible(s) :\n", nb);
	for (int i = 0; i < nb; i++){
		printf("%s\n", mots[i]);
	}
}

int filtre_contient(char mots[][LEN_MOT], int nb, char lettre,char res[][LEN_MOT]){
	int count1 = 0;
	for (int i = 0; i < nb; i++){
		if (strchr(mots[i],lettre) != NULL){
			strcpy(res[count1++],mots[i]);
		}
	}

	return count1;
}

int filtre_exclut(char mots[][LEN_MOT], int nb, char lettre, char res[][LEN_MOT]){
	int count2 = 0;
	for (int i = 0; i < nb; i++){
		if (strchr(mots[i],lettre) == NULL){
			strcpy(res[count2++],mots[i]);
		}
	}

	return count2;
}

int filtre_position(char mots[][LEN_MOT], int nb, char lettre, int pos, char res[][LEN_MOT]){

	int count3 = 0;
	for (int i = 0; i < nb; i++){
		if (mots[i][pos] == lettre){
			strcpy(res[count3++],mots[i]);
		}
	}

	return count3;
}
