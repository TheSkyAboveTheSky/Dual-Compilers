#include "analyseur_lexical.h"

// Les Mots cles
const char *keywords_list[] = {"ZIDB", "MDECLARI", "REJE3", "KHADEM", "TABT", "MTGHAYER", "ILA", "ILAMAKANCH",
                               "MA7EDO", "BDA", "SALI", "KTEB", "WACH", "HBESS", "CHI7AJAKHRA", "KHAWYA", "HEZ7ET", "JME3", "TOUL", "WACH3ADADWLA7ARF", "WACH7ARF", "WACH3ADAD", "WACH3ALAMA", "VABSOLUE",
                               "LBA9I", "SIN", "COS", "TAN", "SQRT", "LOG", "EXP", "PUISSANCE", "ASIN", "ACOS", "ATAN", "L3ADAD", "KIFMAKAN", "KHROJ", "DALA"};
const char *specialTokens_list[] = {"CRO", "CRF", "PV", "PT", "PLUS", "MOINS", "MULT", "DIV", "VIR", "AFF", "EG", "INF", "INFEG", "SUP", "SUPEG", "DIFF", "PO", "PF", "AO", "AF", "DP"};
const char *specialTokens_symb[] = {"[", "]", ";", ".", "+", "-", "*", "/", ",", "=", "==", "<", "<=", ">", ">=", "!=", "(", ")", "{", "}", ":"};

int keywords_list_size = sizeof(keywords_list) / sizeof(keywords_list[0]);
int specialTokens_list_size = sizeof(specialTokens_list) / sizeof(specialTokens_list[0]);
#define NBRKEYWORDS keywords_list_size
#define NBRSPECIALTOKENS specialTokens_list_size
testguill = 0;
nbreguill = 1;

char NextChar()
{
    return currentChar = getc(program);
}

void LexError(char *message)
{
    printf("%s\n", message);
    exit(1);
}

// une fct li kat2ignori les espaces w les commentaires...
void ignoreWhiteSpaces()
{
    while (currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
    {
        NextChar();
    }
    // Ignorer les commentaires %...%
    if (currentChar == '%')
    {
        while ((currentChar = NextChar()) != '%' && currentChar != EOF)
            ;
        currentChar = NextChar();
        while (currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
        {
            NextChar();
        }
    }
}

// mn b3d ma9rina caractére wa7ed b nextchar had la fct kat3iyet les fcts li ghay9raw lina kalma kamla
Token getToken()
{
    // vider le token
    memset(currentToken.name, '\0', lenName);
    memset(currentToken.value, '\0', lenValue);
    // sauter les espaces
    ignoreWhiteSpaces();
    if (currentChar == EOF)
    {
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

boolean isNumber()
{
    if (!isdigit(currentChar))
        return FALSE;
    char num[MAXDIGIT + 1];
    char word[MAXCHAR];

    int cmp = 0;
    int i = 0;

    num[0] = currentChar;
    i++;

    if ((num[i] = currentChar = NextChar()) == '.')
    {
        while (++i <= MAXDIGIT && isdigit(num[i] = currentChar = NextChar()))
            ;
        if (i > MAXDIGIT)
            LexError("Number has several digit");
        num[i] = '\0';
        strcpy(currentToken.name, "NUM");
        strcpy(currentToken.value, num);
        return TRUE;
    }

    else
    {
        int t = isdigit(num[i]);
        if (t == 0 && isalnum(num[i]) != 0)
        {
            int j = 1;
            word[0] = num[0];
            word[1] = toupper(num[1]);
            while (++j <= MAXCHAR && (isalnum(word[j] = currentChar = toupper(NextChar()))))
                ;
            if (j == MAXCHAR)
                LexError("there is many characters in this word");
            word[j] = '\0';
            if (strcmp(word, "3LA7ASSAB") == 0)
            {
                strcpy(currentToken.name, "3LA7SSAB");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "9RA") == 0)
            {
                strcpy(currentToken.name, "9RA");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "9AREN") == 0)
            {
                strcpy(currentToken.name, "9AREN");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "3AMRA") == 0)
            {
                strcpy(currentToken.name, "3AMRA");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "7AZMA") == 0)
            {
                strcpy(currentToken.name, "7AZMA");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "9SSEM") == 0)
            {
                strcpy(currentToken.name, "9SSEM");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "3EYET3AMRA") == 0)
            {
                strcpy(currentToken.name, "3EYET3AMRA");
                strcpy(currentToken.value, word);

                return TRUE;
            }
            else if (strcmp(word, "3EYETKHAWYA") == 0)
            {
                strcpy(currentToken.name, "3EYETKHAWYA");
                strcpy(currentToken.value, word);

                return TRUE;
            }
        }

        else if (t == 0 && isalnum(num[i]) == 0)
        {
            num[1] = '\0';
            strcpy(currentToken.name, "NUM");
            strcpy(currentToken.value, num);
            return TRUE;
        }

        else if (t != 0 && isalnum(num[i]) != 0)
        {
            while (++i <= MAXDIGIT && isdigit(num[i] = currentChar = NextChar()))
                ;
            if (num[i] == '.')
                while (++i <= MAXDIGIT && isdigit(num[i] = currentChar = NextChar()))
                    ;
            if (i > MAXDIGIT)
                LexError("Number has several digit");
            num[i] = '\0';
            strcpy(currentToken.name, "NUM");
            strcpy(currentToken.value, num);
            return TRUE;
        }
    }
}

boolean isWord()
{

    if (!isalpha(currentChar))
        return FALSE;

    char word[MAXCHAR];
    int i = 0, j = 0, cmp = 0;
    word[0] = toupper(currentChar);

    while (++i <= MAXCHAR && (isalnum(word[i] = currentChar = toupper(NextChar())) || word[i] == '_'))
        ;

    if (i == MAXCHAR)
        LexError("there is many characters in this word");

    word[i] = '\0';

    while ((cmp = strcmp(word, keywords_list[j++])) != 0 && j < NBRKEYWORDS)
        ;

    if (cmp == 0)
    {
        strcpy(currentToken.name, keywords_list[j - 1]);
        strcpy(currentToken.value, word);
    }
    // le cas ila makanch le mot f le tableau des mots cles ==> donc ra howa un identificateur ou string
    else
    {
        if (testguill == 0)
        {
            // hna le cas ila maknch 3ndna des guillemets donc ra automatiquement un id 3adi
            strcpy(currentToken.name, "ID");
            strcpy(currentToken.value, word);
        }
        else
        {
            // hna le cas ila kena deja l9ina des guillemets donc ra automatiquement 7na f string
            // kan9raw string kamla wakha tkoun fiha bzaf dyal les mots
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

boolean isSpecial()
{
    int j;
    int i = 0, cmp = 0;
    char op[3]; // la taille d'un opérateur quelconque ne depasse pas 3
    memset(op, '\0', sizeof(op));

    op[0] = currentChar;

    if (currentChar == '"')
    {
        // hna on a lu les guillemets et on teste si le nbrguill=1 donc rah il s'agit lghuill lewlin donc le mot qui va suivre doit avoir tocken String
        // dakshi 3lash on a fait testguill=1 ca va nous aider fle cas ta3 string
        if (nbreguill == 1)
            testguill = 1;
        // dans ce cas la 9riina des guillemets 3awtani mais puisque nbrguill est diff de 1 danc il s'agit des guill tanyin
        else
            nbreguill = 1;
        op[1] = '\0';
        strcpy(currentToken.name, "GUI");
        strcpy(currentToken.value, op);
        currentChar = NextChar();
        return TRUE;
    }

    // hna zedna ( ) { } bach ila tlass9o m3a egal aprés man3tabrohomch opérateur w nmchiw n9albo 3lihom f tableau
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
