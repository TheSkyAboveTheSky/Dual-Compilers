#include "analyseur_lexical.h"
#include "analyseur_syntaxique.h"
#include "analyseur_lexical.c"
#include "analyseur_syntaxique.c"
int main()
{
char * fichieralire;
fichieralire = (char*)malloc(sizeof(char));
scanf("%s", fichieralire);
/**************************************************************** L'ouverture du fichier *****************************************************************/
program = fopen(fichieralire, "r"); 
if(program == NULL){
        perror("Error while opening the file");
        exit(1);
}

/**************************************************************** Le r�sultat de l'analyseur lexical *****************************************************/
        NextChar();
        getToken();
        printf("\nAnalyseur lexical:La liste des Tokens\n");
    do{
         // l'affichage du r�sultat de l'analyseur lexical
         printf("%s_token\n",currentToken.name);
         insertion_syntax(currentToken.name,currentToken.value);
         getToken();
    }while(strcmp(currentToken.name,"EOF"));
/**************************************************************** Le r�sultat de l'analyseur syntaxique *****************************************************/
   printf("Lexical sala\n=========================\n");
   afficherListe_syntax(chaine_syntax);
   PROGRAM();
   if(chaine_syntax==NULL) printf("\nBRAVO!!!\n");
}
