#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define REP_A 1901
#define REP_M 1
#define REP_J 1


/*
 * Nom de la fonction : jours_annee
 * Entrée:
 *   int a: Une année comprise entre 1901 et 2099
 * Sortie:
 *   int jours : Le nombre de jours depuis 1901 jusqu'à cette année
 */
int jours_annee(int a)
{
  return (a - REP_A) * 365 +   (a - REP_A) / 4;
}

/*
 * Nom de la fonction : longueur_mois
 * Entrées:
 *  int a : Une année comprise entre 1901 et 2099
 *  int m : Le mois
 * Sortie:
 *  int nombreJours : Le nombre de jour dans le mois
 */
int longueur_mois(int a, int m)
{
  return m == 2 ? (a % 4? 28 : 29) : 30 + ((m + m / 8) & 1);
}

/*
 * Nom de la fonction : jours_mois
 * Entrées:
 *   short int mois : Le mois
 *   int an : L'année
 * Sortie:
 *   int nombreJours : Le nombre de jours du début de l'année jusqu'au début 
 *  du mois.
 */
int jours_mois(short int mois, int an)
{
  int nombreJours = 0, m;
  for(m = mois - 1; m >= 1; --m) nombreJours += longueur_mois(an, m);
  return nombreJours;
}

/* Nom de la fonction : nom_jour
 * Entrées:
 *  int an : Une année comprise entre 1901 et 2099
 *  int mois : Le mois
 *  int jour : Le jour
 * Sortie:
 *  char* : Le nom du jour en français
 * Description :  
 *  Retourne le nom du jour pour une date comprise entre 1-1-1901 et 31-12-2099
 */
char* nom_jour(int an, int mois, int jour)
{
  switch((jours_annee(an) + jours_mois(mois, an) + jour - 1) % 7)
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

/* Nom de la fonction : verifie_date
 * Entrées:
 *   int jour : Le jour
 *   int mois : Le mois
 *   int an : L'année
 * Sortie:
 *  int valide : 1 si la date est valide et 0 dans l'autre cas
 * Description:
 *   Vérifie si l'année est comprise entre 1901 et 2099, le mois entre 1 et 12
 *  et le nombre des jours selon le mois.
 */
int verifie_date(int j, int m, int a)
{
  if(m < 1 ||
     m > 12 ||
     j < 1 ||
     a < 1901 ||
     a > 2099 ||
     j > ((m == 2)? 28 + !(a % 4) : 30 + (((m * 9) / 8 ) & 1))
    )
    return 0;
  return 1;
}

int main(void)
{
  int j, m, a;
  printf("Entrez une date (jj/mm/aaaa) : ");
  scanf("%d/%d/%d", &j, &m, &a);

  if(verifie_date(j, m, a))
      printf("Le %d/%d/%d est un %s\n", j, m, a, nom_jour(a, m, j));
  else printf("Date invalide\n");

  return 0;
}

