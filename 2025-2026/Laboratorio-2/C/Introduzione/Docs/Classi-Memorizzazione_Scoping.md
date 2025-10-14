# Classi di memorizzazione per variabili, scoping

## Variabili Locali (interne)

Interne a un blocco/funzione, scope: fino alla fine del blocco.

## Variabili Globali (esterne)

Visibili a tutti i file

## Static

### Scope locale

```c
int foo ()
{
    static int pippo = 0;
    return pippo++;
}
```
Memorizzazione: globale
Scope: locale al blocco

### Scope globale

```c
static int pippo = 0;

int foo ()
{
    return pippo++;
}
```

Memorizzazione: globale
Scope: globale al **file**

## File Header `.h`

Contiene **dichiarazioni** di funzioni/variabili e costanti da includere
nei file con `#include`.

Solitamente la definizione delle funzioni va in un file `.c`.

> ![TIP]
> I file `.h` rappresentano un'interfaccia al loro file di implementazione `.c`

## Gestione della memoria

PCB:

* **dati statici**
* **codice**
* **stack**
* **heap**

## Puntatori

Variabili che contengono indirizzi di memoria.

> ![NOTE]
>
> La dimensione di un'indirizzo dipende dall'architettura: e.g.
> 
> * 32 bit (4 byte)
> * 64 bit (8 byte)

```c
int a = 5;
int* pippoPtr = &a;

print("Indirizzo: %x\nValore: %d\n", pippoPtr, *pippoPtr);
```

> ![NOTE]
> 
> ```c
> int** pippoDoublePtr = &pippoPrt;
> ```
