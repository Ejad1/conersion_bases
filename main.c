#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Déclaration des variables
    int m,m1,b1,b2,c1,c2,l,i,j,r,p,q,tab[100];
    char c[100] = "0";
    char n[100],permu[100];
    // Fin de la déclaration

    printf("Entrer un chiffre : ");
    scanf("%s",&n);
    printf("\nDans quelle base est le chiffre ? : ");
    scanf("%d",&b1);
    printf("\nDans quelle base voulez-vous convertir %s ? :",n);
    scanf("%d",&b2);

    // On calcul la longueur du mot avec strlen() et on convertit le mot en entier avec atoi()
    m = atoi(n);
    l = strlen(n);

    // On procède à la convertion du nombre en base 10 s'il ne l'est pas déjà
    m1 = m;
    j = 0;
    c1 = 0;
    if (b1 != 10) {
        for(i=1; i<=l; i++) {
            r = m1%10;
            p = r*(pow(b1,j));
            // c1 est la valeur du nombe en base 10
            c1 = c1 + p;
            j = j + 1;
            m1 = m1/10;
        }
    }

    // On passe maintenant à la onvertion dans la base b2
    if (b2 == 10) {
        printf("\nLe nombre %d en base 10 est %d",m,c1);
    }
    else {
        if (b1 == 10) {
            q = b2 + 1;
            j = 0;
            while (q>b2) {
                r = m1%b2;
                tab[j] = r;
                m1 = m1/b2;
                q = m1;
                j = j + 1;
            }
            tab[j] = q;
            printf("\nLe nombre %s en base %d est : ",n,b2);
            for (i=j;i>=0;i--) {
                printf("%d",tab[i]);
            }
        }
        else {
            q = b2 + 1;
            c2 = c1;
            j = 0;
            while (q>b2) {
                r = c2%b2;
                tab[j] = r;
                c2 = c2/b2;
                q = c2;
                j = j + 1;
            }
            tab[j] = q;
            printf("\nLe chiffre %s en base %d est : ",n,b2);
            for (i=j;i>=0;i--) {
                printf("%d", tab[i]);
            }
        }
    }
    printf("\n");
    printf("\nMerci d'avoir utilisé notre programme de convertion de base. Au revoir et a bientot \n");
    printf("\n");
    system("pause");

    return 0;
}
