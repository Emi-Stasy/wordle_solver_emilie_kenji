# wordle_solver_emilie_kenji
## Description

Ce projet consiste à développer un solver pour le jeu Wordle en langage C.
Le programme utilise une base de données de mots (bdd_wordle.txt) et applique
des filtres pour réduire progressivement la liste jusqu’à trouver le mot correct.

---

## Structure du projet
```bash
   .
├── bin
├── include
│   └── solver.h
├── README.md
├── ressource
│   └── bdd_wordle.txt
└── src
    ├── main.c
    └── solver.c

```
---

## Installation
###  1. Cloner le projet

```bash
   cd Documents
   git clone <url-du-repo>
   cd wordle_solver_nom1_nom2
```
###  2. Verifier les fichiers

Assurez-vous que :
- Le dossier 'ressource/' contient 'bdd_wordle.txt'
- Les fichier '.c' sont dans 'src/'

## Compilation

Depuis la racine du projet :

```bash
  gcc -o bin/wordle_solver src/nom_fichier.c 
```
## Execution

```bash
  cd bin
  ./wordle_solver
```
---

## Fonctionnement du programme

Le programme charge une liste de mots et permet d’appliquer des filtres pour trouver la solution du Wordle.

---

##  Filtres implémentés
# Explication des fonctions – Wordle Solver en C

##  Introduction

Ce document explique les principales fonctions du programme Wordle Solver.
Le programme permet de charger une liste de mots et d’appliquer différents filtres pour réduire les possibilités.

---

##  1. Fonction `charger_dict`

```bash
int charger_dict(char mots[][LEN_MOT], const char *chemin)
```

### Rôle

Charge les mots depuis un fichier texte (`bdd_wordle.txt`) et les stocke dans un tableau.

###  Fonctionnement

* Ouvre le fichier avec `fopen`
* Lit chaque ligne avec `fgets`
* Supprime le `\n` avec `strcspn`
* Vérifie que :

  * le mot fait exactement 5 lettres
  * contient uniquement des lettres (`isalpha`)
* Ajoute le mot dans le tableau `mots`
* Retourne le nombre de mots chargés

### Exemple

```bash
int nb = charger_dict(mots, "ressource/bdd_wordle.txt");
```

---

## 2. Fonction `afficher_mots`

```bash
void afficher_mots(char mots[][LEN_MOT], int nb, const char *mot)
```

###  Rôle

Affiche tous les mots contenus dans le tableau.

###  Fonctionnement

* Affiche le nombre total de mots
* Parcourt le tableau avec une boucle
* Affiche chaque mot avec `printf`

### Remarque

Le paramètre `mot` n’est pas utilisé dans la fonction (inutile ici).

---

##  3. Fonction `filtre_contient`

```bash
int filtre_contient(char mots[][LEN_MOT], int nb, char lettre, char res[][LEN_MOT])
```

### Rôle

Garde uniquement les mots contenant une lettre donnée.

### Fonctionnement

* Parcourt tous les mots
* Utilise `strchr` pour vérifier si la lettre est présente
* Si oui → copie le mot dans `res`
* Retourne le nombre de mots filtrés

### Exemple

```bash
filtre_contient(mots, nb, 'a', resultat);
```

---

## 4. Fonction `filtre_exclut`

```bash
int filtre_exclut(char mots[][LEN_MOT], int nb, char lettre, char res[][LEN_MOT])
```

###  Rôle

Supprime tous les mots contenant une lettre donnée.

### Fonctionnement

* Parcourt tous les mots
* Vérifie que la lettre n’est PAS présente (`strchr == NULL`)
* Si la lettre est absente → copie dans `res`
* Retourne le nombre de mots restants

###  Exemple

```bash
filtre_exclut(mots, nb, 'x', resultat);
```

---

## 5. Fonction `filtre_position`

```bash
int filtre_position(char mots[][LEN_MOT], int nb, char lettre, int pos, char res[][LEN_MOT])
```

##  Rôle

Garde uniquement les mots ayant une lettre spécifique à une position donnée.

## Fonctionnement

* Parcourt tous les mots
* Vérifie si :

  ```bash
  mots[i][pos] == lettre
  ```
* Si vrai → copie dans `res`
* Retourne le nombre de mots filtrés

### Exemple

```bash
filtre_position(mots, nb, 'a', 2, resultat);
```

 Cela signifie : lettre **'a' en position 2**

---

## Résumé des filtres

| Fonction          | Description                                           |
| ----------------- | ----------------------------------------------------- |
| `filtre_contient` | Garde les mots contenant une lettre                   |
| `filtre_exclut`   | Supprime les mots contenant une lettre                |
| `filtre_position` | Garde les mots avec une lettre à une position précise |

---

##  Points importants

* Tous les mots font **5 lettres**
* `LEN_MOT = 6` (pour inclure `\0`)
* Toujours vérifier que :

  * le fichier est bien ouvert
  * les tableaux ne dépassent pas leur taille

---

## Améliorations possibles

* Ajouter filtre multi-lettres
* Ajouter filtre par substring
* Ajouter couleurs (type Wordle)
* Interface utilisateur améliorée

---

##  Conclusion

Ces fonctions permettent de :

* Charger une base de mots
* Appliquer des filtres
* Réduire progressivement les possibilités

C’est la base d’un **Wordle Solver intelligent**

---
