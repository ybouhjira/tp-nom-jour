#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP_ANNEE 1901
#define REP_MOIS 1
#define REP_JOUR 1

int jours_annee(int annee)
{
  return (annee - REP_ANNEE) * 365 +   (annee - REP_ANNEE)/4;
}

int jours_mois(short int mois, int annee)
{
  int nbrJours = 0;
  switch (mois-1)
    {
    case 11: nbrJours += 30;
    case 10: nbrJours += 31;
    case 9: nbrJours += 30;
    case 8: nbrJours += 31;
    case 7: nbrJours += 31;
    case 6: nbrJours += 30;
    case 5: nbrJours += 31;
    case 4: nbrJours += 30;
    case 3: nbrJours += 31;
    case 2: nbrJours += (annee % 4 == 0)? 29 : 28;
    case 1: nbrJours += 31;
    }
  return nbrJours;
}

unsigned int jours_date(int annee, int mois, int jour)
{
  return (jours_annee(annee) + jours_mois(mois, annee) + jour - 1);
}

char* nom_jour(short int indice)
{
  switch(indice)
    {
    case 0: return "Mardi";
    case 1: return "Mercredi";
    case 2: return "Jeudi";
    case 3: return "Vendredi";
    case 4: return "Samedi";
    case 5: return "Dimanche";
    default: return "Lundi";
    }
}

int verifie_date(short int jour, short int mois, int annee)
{
  // Test jour
  if(jour < 1 || jour > 31) return 0;
  switch (mois) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      if(jour > 30) return 0;
    case 4: case 6: case 9: case 11:
      if(jour > 31) return 0;
    case 2:
      if((annee % 4 == 0 && jour > 29) || (annee % 4 != 0 && jour > 28))
        return 0;
    }

  // Test mois
  if(mois < 1 || mois > 12) return 0;

  // Test annee
  if((annee < 1901) || (annee > 2099)) return 0;

  return 1;
}

int main(void)
{
  int jour, mois, annee;
  printf("Entrez une date (jj/mm/aaaa) : ");
  scanf("%d/%d/%d", &jour, &mois, &annee);

  if(verifie_date(jour, mois, annee))
    {
      short int indice = jours_date(annee, mois, jour) % 7;
      printf("Le %d/%d/%d est un %s\n", jour, mois, annee, nom_jour(indice));
    }
  else printf("Date invalide\n");

  return 0;
}

