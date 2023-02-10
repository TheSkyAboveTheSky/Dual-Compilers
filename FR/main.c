#include "analyseur_lexical.h"
#include "analyseur_syntaxique.h"
#include "analyseur_lexical.c"
#include "analyseur_syntaxique.c"
int main()
{
        int testNumber;
        scanf("%d", &testNumber);
        /* L'ouverture du fichier*/
        char fileName[100];
        sprintf(fileName,"./Test/test%d.txt",testNumber);
        program = fopen(fileName, "r");
        if (program == NULL)
        {
                perror("Error while opening the file");
                exit(1);
        }

        /* Le résultat de l'analyseur lexical */
        NextChar();
        getToken();
        printf("\nAnalyseur lexical:La liste des Tokens\n");
        do
        {
                // l'affichage du résultat de l'analyseur lexical
                printf("%s_token\n", currentToken.name);
                insertion_syntax(currentToken.name, currentToken.value);
                getToken();
        } while (strcmp(currentToken.name, "EOF"));
        /* Le résultat de l'analyseur syntaxique*/
        printf("\nL'analyse lexicale a ete bien effectuee!\n=========================\n");
        afficherListe_syntax(chaine_syntax);
        PROGRAM();
        if (chaine_syntax == NULL)
                printf("\nL'analyse syntaxique a ete bien effectuee!\n");
}