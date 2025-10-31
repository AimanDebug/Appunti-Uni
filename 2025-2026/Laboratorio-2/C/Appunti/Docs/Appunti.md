# Struttura di un programma C

Un programma C e' generalmente suddiviso in 4 parti:

* codice
* dati statici: variabili globali
* stack: usato per immagazzinare gli **stack frame**, e quindi i loro contenuti:
    * variabili automatiche
    * ecc.
* heap

# Identificatore, commenti e costanti

## Identificatori

Stringe che iniziano per lettere o `_` usati per:

* nomi di variabili, funzioni, strutture, ecc.

## Commenti

`//` Line comment
`/**/` Muli-line comment

## Costanti

TODO: finish this part lol

# Variabile, blocchi di codice e scoping

## Variabile

Locazione di memoria che contiene un valore di un certo tipo

# Operatori

## Aritmetici

`+`, `-`, `*`, `/`

## Logici

### Booleani

`!`, `&&`, `||`

### Numerici

`==`, ecc.

### Assegnamento

`=`, `+=`, ecc.

## Assegnamento

a = b = c = 0 === a = b

# Tipi di dato

C e' strongly-typed

## Primitivi

### Interi

* char
* int: grandezza dipendente dall'architettura
* float
* double

### Qualificatori

* `short`, `long` per `int`: short < long
* `signed`, `unsigned`
