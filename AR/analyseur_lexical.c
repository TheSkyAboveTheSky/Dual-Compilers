#include "analyseur_lexical.h"

// Les Mots cles
const char *keywords_list[] = {"ZIDB", "MDECLARI", "REJE3", "KHADEM", "TABT", "MTGHAYER", "ILA", "ILAMAKANCH",
                               "MA7EDO", "BDA", "SALI", "KTEB", "WACH", "HBESS", "CHI7AJAKHRA", "KHAWYA", "HEZ7ET", "JME3", "TOUL", "WACH3ADADWLA7ARF", "WACH7ARF", "WACH3ADAD", "WACH3ALAMA", "VABSOLUE",
                               "LBA9I", "SIN", "COS", "TAN", "SQRT", "LOG", "EXP", "PUISSANCE", "ASIN", "ACOS", "ATAN", "L3ADAD", "KIFMAKAN", "KHROJ", "DALA"};
// Les Symbols
const char *specialTokens_list[] = {"CRO", "CRF", "PV", "PT", "PLUS", "MOINS", "MULT", "DIV", "VIR", "AFF", "EG", "INF", "INFEG", "SUP", "SUPEG", "DIFF", "PO", "PF", "AO", "AF", "DP"};
const char *specialTokens_symb[] = {"[", "]", ";", ".", "+", "-", "*", "/", ",", "=", "==", "<", "<=", ">", ">=", "!=", "(", ")", "{", "}", ":"};

// la taille des tableaux des mots cles et des symboles
int keywords_list_size = sizeof(keywords_list) / sizeof(keywords_list[0]);
int specialTokens_list_size = sizeof(specialTokens_list) / sizeof(specialTokens_list[0]);
// Le nombre de mots cles et de symboles
#define NBRKEYWORDS keywords_list_size
#define NBRSPECIALTOKENS specialTokens_list_size
// nbre et test pour les guillemets
testguill = 0;
nbreguill = 1;

/*-----------------------------------------------------------------------
 * NextChar : Obtient le caractère suivant du flux d'entrée.
 *
 * Cette fonction lit et renvoie le caractère suivant du flux d'entrée.
 *
 * En entrée : Le flux d'entrée
 *
 * En sortie : Le caractère suivant du flux d'entrée.
 *-----------------------------------------------------------------------*/
char NextChar()
{
    /*----------------------------------------------------
    * getc : Lit un caractère à partir d'un flux.
    * int getc(FILE *stream);
    * stream : Flux d'entrée.
    */
    return currentChar = getc(program);
}
/*-----------------------------------------------------------------------
 * LexError : Gère les erreurs lexicales.
 *
 * Cette fonction affiche un message d'erreur lexique et termine le
 * programme en cas d'erreur.
 *
 * En entrée : Le message d'erreur à afficher.
 *-----------------------------------------------------------------------*/
void LexError(char *message)
{
    // afficher le message d'erreur
    /*----------------------------------------------------
    * printf : Affiche un message formaté sur la sortie standard.
    * int printf(const char *format, ...);
    * format : Chaîne de formatage.
    *----------------------------------------------------*/
    printf("%s\n", message);

    // terminer le programme
    /*----------------------------------------------------
    * exit : Termine le programme.
    * void exit(int status);
    * status : Code de retour du programme.
    *-------------------------------------------------------*/
    exit(1);
}

/*-----------------------------------------------------------------------
 * ignoreWhiteSpaces : Ignore les espaces et les commentaires.
 *
 * Cette fonction ignore les espaces, les tabulations et les commentaires
 * dans le code source.
 *-----------------------------------------------------------------------*/
void ignoreWhiteSpaces()
{
    // Ignorer les espaces, les tabulations et les sauts de ligne
    while (currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
    {
        NextChar();
    }
    // Ignorer les commentaires %...%
    if (currentChar == '%')
    {
        while ((currentChar = NextChar()) != '%' && currentChar != EOF);
        currentChar = NextChar();
        while (currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
        {
            NextChar();
        }
    }
}

/*-----------------------------------------------------------------------
 * getToken : Obtient le mot suivant.
 *
 * Cette fonction récupère le prochain token (mot).
 * Elle peut s'agir d'un nombre, d'un mot-clé, d'un opérateur, ou d'un
 * identificateur.
 *-----------------------------------------------------------------------*/
Token getToken()
{
    // vider le token

    /*----------------------------------------------------
    * memset : Remplit un bloc de mémoire avec une valeur.
    * void *memset(void *s, int c, size_t n);
    * s : Pointeur vers le bloc de mémoire à remplir.
    * c : Valeur à affecter.
    * n : Nombre d'octets à remplir.
    *-------------------------------------------------------*/    
    memset(currentToken.name, '\0', lenName);
    memset(currentToken.value, '\0', lenValue);

    //Ignore les espaces et les commentaires    
    ignoreWhiteSpaces();

    // Si le fichier est terminé, on renvoie le token EOF
    if (currentChar == EOF)
    {
        /*----------------------------------------------------
        * strcpy : Copie une chaîne de caractères.
        * char *strcpy(char *dest, const char *src);
        * dest : Chaîne de destination.
        * src : Chaîne source.
        */
        strcpy(currentToken.name, "EOF");
    }
    else if (isNumber())
    {

    }
    else if (isWord())
    {
    }
    else if (isSpecial())
    {
    }
    else
    {
        LexError("Invalid Token");
    }
}
/*-----------------------------------------------------------------------
 * isNumber : Vérifie si le token est un nombre.
 *
 * Cette fonction vérifie si le token est un nombre.
 *
 * En entrée : Le token à vérifier.
 *
 * En sortie : TRUE si le token est un nombre, FALSE sinon.
 *-----------------------------------------------------------------------
*/
boolean isNumber()
{
    // Vérifier si le token est un chiffre , sinon retourner FALSE
    if (!isdigit(currentChar))
        return FALSE;

    char num[MAXDIGIT + 1];
    char word[MAXCHAR];
    int cmp = 0;
    int i = 0;
    num[0] = currentChar;
    i++;
    // Vérifier si le token est un nombre décimal
    if ((num[i] = currentChar = NextChar()) == '.')
    {
        while (++i <= MAXDIGIT && isdigit(num[i] = currentChar = NextChar()));
        if (i > MAXDIGIT)
            LexError("Number has several digit");
        num[i] = '\0';
        // copier le nom et la valuer du token
        strcpy(currentToken.name, "NUM");
        strcpy(currentToken.value, num);
        return TRUE;
    }
}
/*-----------------------------------------------------------------------
 * isWord : Vérifie si le token est un mot.
 *
 * Cette fonction vérifie si le token est un mot.
 *
 * En entrée : Le token à vérifier.
 *
 * En sortie : TRUE si le token est un mot, FALSE sinon.
 *-----------------------------------------------------------------------
*/
boolean isWord()
{
    // Vérifier si le token est un caractère alphabétique , sinon retourner FALSE
    if (!isalpha(currentChar))
        return FALSE;

    char word[MAXCHAR];
    int i = 0, j = 0, cmp = 0;
    /*----------------------------------------------------
    * toupper : Convertit un caractère en majuscule.
    * int toupper(int c);
    * c : Caractère à convertir.
    */
    word[0] = toupper(currentChar);

    while (++i <= MAXCHAR && (isalnum(word[i] = currentChar = toupper(NextChar())) || word[i] == '_'));

    if (i == MAXCHAR)
        LexError("there is many characters in this word");

    word[i] = '\0';

    while ((cmp = strcmp(word, keywords_list[j++])) != 0 && j < NBRKEYWORDS);

    if (cmp == 0)
    {
        strcpy(currentToken.name, keywords_list[j - 1]);
        strcpy(currentToken.value, word);
    }
    // Le cas ou le mot n'est pas un mot clé , donc c'est un identificateur
    else
    {
        if (testguill == 0)
        {
            // Le cas ou on'a pas de guillemets , donc c'est un identificateur simple
            strcpy(currentToken.name, "ID");
            strcpy(currentToken.value, word);
        }
        else
        {
            // Le cas ou on'a des guillemets , donc c'est un String (chaine de caractères)
            // on lu tout le sring , meme si ona plusieurs mots
            while (currentChar != '"')
            {
                word[i] = currentChar;
                i++;
                currentChar = NextChar();
            }
            word[i] = '\0';
            strcpy(currentToken.name, "STRING");
            strcpy(currentToken.value, word);
            nbreguill++;
            testguill = 0;
        }
    }

    return TRUE;
}
/*-----------------------------------------------------------------------
 * isSpecial : Vérifie si le token est un opérateur.
 *
 * Cette fonction vérifie si le token est un opérateur.
 *
 * En entrée : Le token à vérifier.
 *
 * En sortie : TRUE si le token est un opérateur, FALSE sinon.
 *-----------------------------------------------------------------------
*/
boolean isSpecial()
{
    int j;
    int i = 0, cmp = 0;
    char op[3]; // la taille d'un opérateur quelconque ne depasse pas 3
    memset(op, '\0', sizeof(op));

    op[0] = currentChar;

    if (currentChar == '"')
    {
        // on lu les guillemets et on teste si le nbrguill=1 donc il's'agit des premiers guillemets donc le mot qui va suivre doit avoir tockn String
        // c'est pourquoi on a fait testguill=1 ca va nous aider dans le cas du mots
        if (nbreguill == 1)
            testguill = 1;
        // dans ce cas si on lu encore d'autres guillemets elles seront les deuxiemes
        else
            nbreguill = 1;
        op[1] = '\0';
        strcpy(currentToken.name, "GUI");
        strcpy(currentToken.value, op);
        currentChar = NextChar();
        return TRUE;
    }

    if ((op[1] = currentChar = NextChar()) != '=' || op[0] == ')' || op[0] == '}' || op[0] == '(' || op[0] == '{')
        // < ou > ou = ou ( ou ) ou ; ou  . ou + ou  - ou  * ou  /  ou , ou !
        op[1] = '\0';
    else
        NextChar();

    while ((cmp = strcmp(op, specialTokens_symb[i++]) != 0) && i < NBRSPECIALTOKENS)
        ;

    if (cmp != 0)
        return FALSE;
    strcpy(currentToken.name, specialTokens_list[i - 1]);
    strcpy(currentToken.value, op);

    return TRUE;
}