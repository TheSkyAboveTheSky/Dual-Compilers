#include "analyseur_lexical.h"
#include "analyseur_syntaxique.h"
#include "analyseur_lexical.c"
#include "analyseur_syntaxique.c"
int main()
{
        int testNumber;
        printf("# Choisir le nombre de Test Parmis 1 2 et 3 : \n");
        scanf("%d", &testNumber);
        /** L'ouverture du fichier**/
        char fileName[100];
        /*----------------------------------------------------------------
        *sprintf : 
        */
        sprintf(fileName,"./Test/test%d.txt",testNumber); 
        
        program = fopen(fileName, "r");
        if (program == NULL)
        {
                printf("Error while opening the file");
                exit(1);
        }

        /** Le résultat de l'analyseur lexical **/
        NextChar();
        getToken();
        printf("\n Analyseur lexical: La liste des Tokens \n");
        do
        {
                // l'affichage du résultat de l'analyseur lexical
                printf("%s_token\n", currentToken.name);
                insertion_syntax(currentToken.name, currentToken.value);
                getToken();
        } while (strcmp(currentToken.name, "EOF"));
        /** Le résultat de l'analyseur syntaxique**/
        printf("Analyseur Lexical sala \n ========================= \n");
        afficherListe_syntax(chaine_syntax);
        PROGRAM();
        if (chaine_syntax == NULL)
                printf("\n Analyseur Syntaxique sala bi najaaaa7! \n");
}
