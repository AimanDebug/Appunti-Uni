# Preprocessore e direttive di preprocessore

> [!NOTE]
> Le direttive di preprocessore iniziano con il simbolo `#` e non richiedono un punto e virgola alla fine.
> Normalmente finiscono alla fine della linea, ma possono essere estese su più linee utilizzando il carattere di continuazione `\`.

## Inclusione: `include`

```c
#include <filename>
```
Include un file di header standard del sistema.

```c
#include "filename"
```
Include un file header prima nella directory corrente, poi nelle directory standard del sistema.

## Definizione di macro: `define`

```c
#define PI 3.14
#define SQUARE(x) ((x) * (x))
#undef PI
```
> [!ATTENTION]
> La sostituzione delle macro è testuale e non tiene conto dei tipi di dato.

```c
#define AREA_CERCHIO_2 cerchio(2.0)

printf("Area del cerchio di raggio 2: %f\n", AREA_CERCHIO_2);
// Espande a:
printf("Area del cerchio di raggio 2: %f\n", cerchio(2.0));
```

### Macro parametrizzate

```c
#define NOME_MACRO(param1, param2, ..., paramN) testo_macro
```

> [!TIP]
> Ricorda la sostituzione è testuale, i parametri non devono essere per forza tipi di dato.
> Ciò però può portare a risultati inattesi se non si usano le parentesi correttamente.
> 
> ```c
> #define DOUBLE(x) x * 2
>
> int valore = 5;
> int risultato = DOUBLE(valore + 3); // -> 5 + 3 * 2 = 11 != 16
> ```
> La soluzione è racchiudere i parametri tra parentesi:
> 
> ```c
> #define DOUBLE(x) ((x) * 2))
> ```

> [!NOTE]
> Come buona regola si mettono le parentesi attorno al **parametro**
> e **testo**

### Espressioni multiple


## Condizioni

* `#if`
* `#ifdef`
* `#ifndef`
* `#else`
* `#elif`
* `#endif`

### Header guard

```c
#ifndef MYHEADER_H
#define MYHEADER_H
// Contenuto del file header
#endif // MYHEADER_H
```

## Errori e avvisi

```c
#error "Unsupported platform"
```
Interrompe la compilazione e mostra un messaggio di errore.

```c
#warning "This feature is deprecated"
```
Mostra un avviso durante la compilazione senza interromperla

> [!ATTENTION]
> Non è standard, ma è largamente diffusa.

## Controllo di file

```c
#line 42 "myfile.c"
```
Cambia il numero di linea e il nome del file per i messaggi di errore e debug.

## Direttive `pragma`

```c
#pragma once
```
Assicura che un file di header venga incluso una sola volta durante la compilazione.

> [!TIP]
> Le direttive `pragma` sono specifiche del compilatore e possono variare tra diversi compilatori.

## Macro predefinite C11

* `__DATE__` - Data di compilazione (stringa)
* `__TIME__` - Ora di compilazione (stringa)
* `__FILE__` - Nome del file corrente (stringa)
* `__LINE__` - Numero di linea corrente (intero)
* `__STDC__` - Definito come 1 se il compilatore aderisce allo standard C
* `__STDC_VERSION__` - Versione dello standard C (C11 -> 201112L)
