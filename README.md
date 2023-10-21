[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
# Projet Compilation

# Réalisé par :                    Encadré par:

## Said Mounji

## Hossame Torchi                        Mr. Rachid Oulad Haj Thami

## Mohamed Sadik

## Mouad Toubil

# I. Introduction

## 1.1 Objectif

L’objectif de ce projet est de créer un compilateur qui supporte les deux langages (Arabe dialecte et Français)  utilisées au Maroc, pour que notre projet atteint un plus grand nombre d’audience dans notre pays.

Ce qui est souhaitable est d’aider les débutants à mieux s’intégrer dans le monde du coding du langage C en leur fournissant un langage plus proche à leurs langages fréquemment utilisés que le langage machine.

## 1.2 Utilité

Ce projet de compilation est extrêmement utile car il permet de regrouper différents éléments en un seul et même endroit. La disponibilité de deux versions, en arabe et en français, en fait une solution encore plus attractive pour les utilisateurs qui peuvent ainsi choisir la langue qui leur convient le mieux. Cette polyvalence permet également d'atteindre un public plus large et de couvrir un plus grand nombre de besoins. En somme, le projet de compilation avec ses deux versions est un outil incontournable pour les personnes et les organisations qui cherchent à regrouper et à présenter de l'information de manière efficace et accessible.

# II. Construction du langage ARABE (Darija)

## 2.1 Blocs de programme

Notre programme développé dual-compiler partie 1 “Darija”est composé de trois parties :

| MDECLARI | Afin de commencer le bloc de déclaration.  |
| --- | --- |
| DALA | Afin de spécifier le bloc dans lequel les fonctions vont être définies.  |
| KHADEM | Afin de commencer le bloc des instructions. |

## 2.2 La partie déclaration

Notre langage est un langage non typé, la déclaration se fait de deux manières :

| TABT | Afin de déclarer les constantes. |
| --- | --- |
| MTGHAYER | Afin de déclarer les variables.  |

## 2.3 Les instrcutions

| KTEB | Afin de déclarer les variables. |
| --- | --- |
| 9RA | Afin de lire des variables. |
| ILA … ILAMAKANCH | Afin d’exprimer IF...ELSE. |
| MA7EDO | Afin d’exprimer la boucle while. |
| 3LA7SSAB | Afin d’exprimer SWITCH. |
| WACH | Afin d’exprimer CASE. |
| HBESS | Afin d’exprimer BREAK.  |
| CHI7AJAKHRA | Afin d’exprimer DEFAULT.  |
| 3EYET | Afin d’appeler une fonction déclarée par l’utilisateur. |
| BDA() SALI() ZIDB() | Afin d’exprimer la boucle for().  |

## 2.4 Les fonctions déclarées par l’utilisateur

La déclaration d’une fonction définie par l’utilisateur se fait au sein du bloc FCT en utilisant les mots clés
suivants :

| KHAWYA | Afin d’exprimer que la fonction ne retourne rien . |
| --- | --- |
| 3AMRA | Afin d’exprimer que la fonction retourne un résultat. |
| REJE3 | Afin d’exprimer RETURN. |

## 2.5 Les fonctions définies par le langage

| wach3adadwla7arf | Afin de vérifier si l’argument donné est un chiffre ou caractère. |
| --- | --- |
| wach7arf | Afin de vérifier si l’argument donné est un caractère ou non. |
| wach3adad | Afin de vérifier si l’argument donné est un chiffre ou non. |
| wach3alama | Afin de vérifier si l’argument donné est un point de ponctuation. |
| Vabsolue | Afin d’exprimer la fonction valeur absolue. |
| lba9i | Afin d’exprimer la fonction modulo. |
| sin | Afin d’exprimer la fonction sin. |
| cos | cos Afin de d’exprimer la fonction cos. |
| tan | Afin d’exprimer la fonction tan . |
| sqrt | Afin d’exprimer la fonction racine carré. |
| log | Afin d’exprimer la fonction logarithme. |
| exp | Afin d’exprimer la fonction exponentielle. |
| puissance | Afin d’exprimer la focntion puissance. |
| 9ssem | Afin d’exprimer la fonction division. |
| asin | Afin d’exprimer la fonction asin. |
| acos | Afin d’exprimer la fonction acos. |
| atan | Afin d’exprimer la fonction atan. |
| l3adad | Afin d’exprimer la fonction atoi. |
| kifmakan | Afin d’exprimer la fonction rand. |
| hez7et | Afin d’exprimer la fonction strcpy. |
| 9aren | Afin d’exprimer la fonction strcmp. |
| jme3 | Afin d’exprimer la fonction strcat. |
| toul | Afin d’exprimer la fonction strlen. |

## 2.6 Les symboles utilisés au niveau du langage

| = | Afin d’exprimer l’égalité. |
| --- | --- |
| {...} | Afin d’exprimer le début et la fin d’un bloc. |
| [...] | Afin de contenir un ensemble de valeurs affectées à un tableau. |
| "...” | Afin d’exprimer une chaîne de caractères. |
| , | Afin de séparer un ensemble de valeurs ou variables ou constantes. |
| ; | Afin d’exprimer la fin d’une instruction. |

## 2.7 Analyseur lexical

## 2.7.1 La structure des tokens

Avant de décomposer le code entré par l’utilisateur en des tockens, nous avons travaillé sur la déclaration
d’une structure dans laquelle nous allons sauvegarder les informations de chaque tocken trouvé dans le code.

```c
typedef struct{
	char name[lenName];
	char value[lenValue];
} Token;
Token currentToken;
```

## 2.7.2 Les fonctions utilisées dans le code lexical

Lors de la réalisation de cet analyseur nous avons utilisé ub ensemble de fonctions à savoir :

| Nextchar() | Afin de récupérer le prochain caractère dans le code créé par l’utilisateur. |
| --- | --- |
| SyntaxError() | Afin de générer les messages d’erreurs et sortir du programme. |
| ignoreWhiteSpaces() | Afin d’ignorer les espaces blancs. |
| getToken | Afin de récupérer un token. |
| isNumber() | Afin de vérifier si le tocken courant est un nombre. |
| isWord() | Afin de vérifier si le tocken courant est un mot. |
| isSpecial() | Afin de vérifier si le token est un symbole spécial. |

## 2.8 Analyseur syntaxique

## 2.8.1 La structure de programme

Notre programme est décomposé en principe en 3 blocs dont la structure est la suivante :

```c
MDECLARI{
 ...
}
DALA{
 ...
}
KHADEM{
 ...
}
```

## 2.8.2 La grammaire

```c
PROGRAM ::= MDECLARI DEF DALA FONCTION KHADEM BLOCK
DEF ::= (CONSTS VARS )
CONSTS ::= TABT CONSTID [,CONSTID]; | epsilon
CONSTID ::= ID ALPHA
ALPHA :: = (Num) = \[TABCONST\] | =ALPHANUM
TABCONST :: = NUM[, NUM] | "STRING" [, "STRING"]
VARS ::= MTGHAYER ID VAR [,ID VAR ]; l epsilon
VAR ::= epsilon | (NUM)
ALPHANUM := NUM | "STRING"
FONCTION ::= { KHAWYA|3AMRA ID (PARAM) {
DEF
INSTS
[ REJE3 (NUM|ID); ]
[khawya | 3amra ID(PARAM) {
DEF
INSTS
[ reje3 (NUM|ID);] ] } |  epsilon }
BLOCK ::= [ INSTS ]
INSTS ::= INST
INST ::= AFFECT INST  | SI INST | ECRIRE INST | LIRE INST | FOR INST I WHILE INSTI SWITCH INST | APPELFCT INST l epsilon
AFFECT ::= ID AFFEC;
AFFEC ::= = AFFEC2 | AFFECTAB
AFFECTAB ::= (NUM) = EXPR
AFFEC2 ::= EXPR \[TABCONST\]
SI ::= ILA COND { INSTS} | [ILAMAKANCH ( INSTS )]
ECRIRE ::= kteb ( ECRIREA ) ;
ECRIREA ::= ID ECRIREB | "STRING" ECRIREB
ECRIREB ::= + ECRIREA | epsilon
LIRE ::= 9ra(ID[, ID]);
FOR ::= BDA (ID=NUM) SALI (ID=NUM) ZIDB (+| - NUM) ( INSTS)

WHILE ::= ma7ed(COND){INSTS }
SWITCH ::= 3la7assab (ID) {
wach ALPHANUM: INSTS [Baraka;]
[wach ALPHANUM: INSTS
[Baraka;]]
Ta7aja: INSTS [baraka;]
PARAM = ID[,ID]
EXPR ::= TERM [+1- TERM]
TERM :: = FACT [*|/ FACT]
FACT ::= ID I NUM | (EXPR)
ID ::= LETTRE [LETTRE | CHIFFRE]
NUM ::= CHIFFRE [CHIFFRE]
CHIFERE 1= 0..9
LETTRE ::= a l b l..|z|Al..iz
COND ::= ( EXPR RELOP EXPR)
RELOP ::= == I<>| <|> | <= | >=
APPELECT = 3eyet APPEL.
APPEL: =FCTDEFC1| FCTDEFC2 | FCTDEFC3 | FCTDEFC4| FCTDEFC5 | FCTDEC
FCTDEC:= ID(VAL|,VAL]);
VAL ::= ID I NUM "STRING"

FCTDEFC1 ::= wach3adadwlaTarf (ID)     |
wachTarf (ID) |
wach3adad (ID) |
wach3alama (ID) |
Vabsolue (ID) |
Iba9i (ID) |
sin (ID) |
COS (ID) |
tan (ID) |
sqrt (ID) |
log(ID) |
exp (ID) |
puissance (ID) |
9ssem (ID) |
asin (ID) |
acos (ID) |
atan (ID) |
l3addad (ID) |
ki fmakan (ID) |
FCTDEEC2 ::= khroj (NUM)
FCTDEFC3 1:: hez7et (ID,ARG1) | jme3 (ID,ARG1)
FCTDEFC4 ::= toul (ARG1)
FCTDBFC5 ::= 9aren (ARG1, ARG1)
ARGI ::= ID | "STRING”

```

# III. Construction du langage FRAN**Ç**AIS

## 3.1 Blocs de programme

Notre programme développé dual-compiler partie 1 “Darija”est composé de trois parties :

| DECLARATION | Afin de commencer le bloc de déclaration.  |
| --- | --- |
| FONCTION | Afin de spécifier le bloc dans lequel les fonctions vont être définies.  |
| PRINCIPAL | Afin de commencer le bloc des instructions. |

## 3.2 La partie déclaration

Notre langage est un langage non typé, la déclaration se fait de deux manières :

| CTE | Afin de déclarer les constantes. |
| --- | --- |
| VAR | Afin de déclarer les variables.  |

## 3.3 Les instrcutions

| ECRIRE | Afin de déclarer les variables. |
| --- | --- |
| LIRE | Afin de lire des variables. |
| SI … SINON | Afin d’exprimer IF...ELSE. |
| TANTQUE | Afin d’exprimer la boucle while. |
| SELON | Afin d’exprimer SWITCH. |
| CAS | Afin d’exprimer CASE. |
| ARRETE | Afin d’exprimer BREAK.  |
| AUTRE | Afin d’exprimer DEFAULT.  |
| APPEL | Afin d’appeler une fonction déclarée par l’utilisateur. |
| DE() A() AVEC() | Afin d’exprimer la boucle for().  |

## 3.4 Les fonctions déclarées par l’utilisateur

La déclaration d’une fonction définie par l’utilisateur se fait au sein du bloc FONCTION en utilisant les mots clés
suivants :

| VIDE | Afin d’exprimer que la fonction ne retourne rien . |
| --- | --- |
| TYPE | Afin d’exprimer que la fonction retourne un résultat. |
| RETOURNER | Afin d’exprimer RETURN. |

## 3.5 Les fonctions définies par le langage

| CHIFFREOUCARACTERE | Afin de vérifier si l’argument donné est un chiffre ou caractère. |
| --- | --- |
| ESTCARACTERE | Afin de vérifier si l’argument donné est un caractère ou non. |
| ESTCHIFFRE | Afin de vérifier si l’argument donné est un chiffre ou non. |
| ESTSYMBOLE | Afin de vérifier si l’argument donné est un point de ponctuation. |
| Vabsolue | Afin d’exprimer la fonction valeur absolue. |
| MODULO | Afin d’exprimer la fonction modulo. |
| sin | Afin d’exprimer la fonction sin. |
| cos | cos Afin de d’exprimer la fonction cos. |
| tan | Afin d’exprimer la fonction tan . |
| sqrt | Afin d’exprimer la fonction racine carré. |
| log | Afin d’exprimer la fonction logarithme. |
| exp | Afin d’exprimer la fonction exponentielle. |
| puissance | Afin d’exprimer la focntion puissance. |
| DIVISE | Afin d’exprimer la fonction division. |
| asin | Afin d’exprimer la fonction asin. |
| acos | Afin d’exprimer la fonction acos. |
| atan | Afin d’exprimer la fonction atan. |
| VERSCHIFFRE | Afin d’exprimer la fonction atoi. |
| ALEATOIRE | Afin d’exprimer la fonction rand. |
| COPIER | Afin d’exprimer la fonction strcpy. |
| COMPARE | Afin d’exprimer la fonction strcmp. |
| CONCATENER | Afin d’exprimer la fonction strcat. |
| LONGUEUR | Afin d’exprimer la fonction strlen. |

## 3.6 Les symboles utilisés au niveau du langage

| = | Afin d’exprimer l’égalité. |
| --- | --- |
| {...} | Afin d’exprimer le début et la fin d’un bloc. |
| [...] | Afin de contenir un ensemble de valeurs affectées à un tableau. |
| "...” | Afin d’exprimer une chaîne de caractères. |
| , | Afin de séparer un ensemble de valeurs ou variables ou constantes. |
| ; | Afin d’exprimer la fin d’une instruction. |

## 3.7 Analyseur lexical

## 3.7.1 La structure des tokens

Avant de décomposer le code entré par l’utilisateur en des tockens, nous avons travaillé sur la déclaration
d’une structure dans laquelle nous allons sauvegarder les informations de chaque tocken trouvé dans le code.

```c
typedef struct{
	char name[lenName];
	char value[lenValue];
} Token;
Token currentToken;
```

## 3.7.2 Les fonctions utilisées dans le code lexical

Lors de la réalisation de cet analyseur nous avons utilisé ub ensemble de fonctions à savoir :

| Nextchar() | Afin de récupérer le prochain caractère dans le code créé par l’utilisateur. |
| --- | --- |
| SyntaxError() | Afin de générer les messages d’erreurs et sortir du programme. |
| ignoreWhiteSpaces() | Afin d’ignorer les espaces blancs. |
| getToken | Afin de récupérer un token. |
| isNumber() | Afin de vérifier si le tocken courant est un nombre. |
| isWord() | Afin de vérifier si le tocken courant est un mot. |
| isSpecial() | Afin de vérifier si le token est un symbole spécial. |

## 3.8 Analyseur syntaxique

## 3.8.1 La structure de programme

Notre programme est décomposé en principe en 3 blocs dont la structure est la suivante :

```c
DECLARATION{
 ...
}
FONCTION{
 ...
}
PRINCIPAL{
 ...
}
```