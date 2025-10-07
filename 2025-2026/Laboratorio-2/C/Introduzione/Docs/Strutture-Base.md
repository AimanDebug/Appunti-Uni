# Comandi di Base

## Comandi Condizionali

```c
if (espressione)
    comando
else
    comando
```

`espressione` e' una qualunque expr. numerica:

* Se `espressione` ha valore `0` viene interpretato come valore logico **falso**.
* **Qualsiasi** altro valore viene interpretato come **vero**.


> Sono annidabili ma per evitare il **dangling else** base usare un blocco \{\}

### `switch`

```c
switch (espressione) {
    case espressione_costante:
    comando;
    break;

    case espressione_costante:
    comando;
    break;

    default:
    comando;
}
```

Istruzione condizionale a scelta multipla.
`espressione` deve essere di tipo intero e le `espressione_costante`(i) devono essere uniche.
TODO: finisci desc.

## Comandi Iterativi

```c
do
    comando
while (espressione)
```

```c
while (espresssione)
    comando
```

Se `espressione` ha valore diverso da `0` si esegue il comando corpo del ciclo,
e si torna all'inizio del ciclo.

> La differenza tra do-while e while e' che il primo esegue `comando` 1 o piu' volte,
> mentre l'altro 0 o piu' volte.

```c
for (espressione1; espressione2; espressione3)
    comando
```

1. `espressione1` viene valutata all'inizio del ciclo.
2. Se `espressione2` ha valore **vero** allora viene eseguito `comando` altrimenti finisco l'esecuzione.
3. `espressione3` viene eseguita e si torna allo step 2.

> Il `for` e' nato per semplificare llo scorrimento su array.

> E' equivalente a
> ```c
> {
>   espressione1;
>   while (espressione2) {
>       comando;
>       espressione3;
>   }
> }
> ```

### `break`

Causa l'immediata uscita dal *ciclo* che lo contiene o l'istruzione `switch`.

### `continue`

Termina la corrente iterazione di un *ciclo* e comincia la successiva.

## I/O

Libreria standard per I/O: `stdio.h`

Per stampare i valore nello standard output UNIX:
```c
printf(stringa_formattazione, argomenti...)
```

`stringa_formattazione` puo contenere segnaposti: `%`*`<format_specifier>`*

### `scanf()`

Per leggere valori dallo standard input UNIX:

```c
scanf(stringa_formattazione, argomenti...)
```

```c
#include <stdio.h>

int main(void) {
    int alfio = 0;

    // TODO: finire programma per leggere
```

I segnaposti sono uguali a printf a parte `double`: `%lf`

## Tipi di dato

**C** e' strongly-typed

### Primitivi

* `char`
* `int`
* `float`
* `double`

### Qualificatori

TODO: finire qualificatori

> [!CAUTION]
> `short` <= ` ` <= `long` non ci sono garanzie sulla dimensione in byte.

### Conversione **implicita**

Quando utilizziamo delle espressioni che coinvolgono tipi diversi.

> [!TIP]
> Generalmente i tipi di dimensione piu' piccola possono essere convertiti a quelli piu' grandi.
> `char`, `short` -> `int` -> `long` -> `float` -> `double` -> `long double`

Quando assegnamo un valore di una variabile ad un'altra di tipo diverso.

*vince* il tipo della `lvalue` (variabile a sinitra)
Si perde informazione se la parte a sinistra ha tipo piu' *corto*.

### Conversione **esplicita**

Si usa l'operatore di casting `(nome_tipo) espressione`

```c
long a;
float b;
b = (float) a;
```

> [!WARNING]
> Certi tipi non sono compatibili: `const char*` (stringa) non puo' essere convertito a `int`.

> [!TIP]
> Bisogna fare attenzione a dove facciamo il cast
> ```c
> (float)(3/2) // -> 1
> ((float)3 / 2) // -> 1.5
> ```

## Array monodimensionali

```c
tipo nome[espressione_constante_compile_time];
```

Collezioni **omogenea** **contigua** di valori.
Hanno dimensione **statica** che deve essere specificata nella definizione
mediante un'**espressione costante** (se non si usano puntatori)

Per accedere ad un elemento usiamo l'operatore `[indice]`

```c
int test[100]

// MEMORY:      [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]...
// BYTE:         0  1  2  3  4  5  6
```

> [!WARNING]
> Il tipo non e' forzato posso interpretare le celle in un altro modo
> TODO: finisci

## Tipi definiti dall'utente - `struct`

```c
struct nome {
    dichiarazioni_campi
};
```

Si possono definire strutture di dati non omogenee ma **contigue**,
e che introducono un nuovo **tipo** di dato.

> [!IMPORTANT]
> L'ordine in cui i campi sono dichiarati detta l'ordine con cui sono messi in memoria.
> TODO: guarda se anche l'offset

Per accedere a un membro usiamo l'operatore: `variabile**.**membro`

## Tipi di dato custom - `typedef`

```c
typedef char[] String;
```

## Array bidimensionali

```c
    int a[3][3];
```

Si possono definire array N-dimensionali in modo simile a come se ne definisce un normale.

> [!NOTE]
> Si possono avere quante dimensioni si vogliono.
>
> ```c
> int a[3][3][2];
> ```

## Enum

`enum` definisce tipi di dato custom 


## `typedef`

Si usa per rinominare dei tipi esistenti (e.g. nomi di tipi lunghi),
l'identificatore usato diventa un sostitutivo **lessicale** al tipo indicato.

```c
typedef char* String;
```

## Parametri dalla CLI

```c
int main(int argc, char argv[][]);
```

* `argc`: numero di parametri
* `argv`: parametri stessi (stringhe)

> [!NOTE]
> `argv[0]` e' il nome del programma

