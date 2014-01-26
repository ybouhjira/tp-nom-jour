#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define REP_ANNEE 1901
#define REP_MOIS 1
#define REP_JOUR 1

int jours_annee(int annee)
{
  return (annee - REP_ANNEE) * 365 +   (annee - REP_ANNEE)/4;
}

int longueur_mois(int an, int mois)
{
  assert(1 <= mois && mois <= 12);
  return mois == 2 ? an % 4? 28 : 29 : 30 + (((mois * 9) / 8) & 1);
}

int jours_mois(short int mois, int an)
{
  int nombreJours = 0, m;
  for(m = mois - 1; m >= 1; --m) nombreJours += longueur_mois(an, m);
  return nombreJours;
}

char* nom_jour(int an, int mois, int jour)
{

  int indice = (jours_annee(an) + jours_mois(mois, an) + jour - 1) % 7;

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
  int j, m, a;
  printf("Entrez une date (jj/mm/aaaa) : ");
  scanf("%d/%d/%d", &j, &m, &a);

  if(verifie_date(j, m, a))
    {
      printf("Le %d/%d/%d est un %s\n", j, m, a, nom_jour(a, m, j));
    }
  else printf("Date invalide\n");

  return 0;
}

