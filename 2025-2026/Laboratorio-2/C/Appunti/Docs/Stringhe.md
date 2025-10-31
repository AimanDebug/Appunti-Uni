# Stringhe

Array di caratteri con `'\0'` alla fine ([null termination character](https://en.cppreference.com/w/c/string/byte.html)).

> [!NOTE]
>
> Le costanti letterali per i caratteri in C sono denotate da `''`.
>
> ```c
> char a = 'A'; // <- OK
> char b = "B"; // <- ERROR!
> ```

## Allocazione

Possiamo allocare le stringhe sullo stack mediante array:

```c
char sArr[] = "ciao";
```

Oppure nella memoria globale/statica e riferirle con puntatore:

```c
char* sPtr = "ciao";
```

> [!WARNING]
>
> ```c
> sArr[2] = 'A'; // OK
> sPtr[2] = 'A'; // CRASH: You're accessing read only memory!
> ```

> [!TIP]
>
> Il `%s` in `printf` prende un `char*` e stampa la stringa.

## Operazioni (funzioni di libreria)

* `strlen`: lunghezza
* `strcpy`: copia `src` in `dest`
* `strcmp`: confronto lessicografico
* `strcat`: concate `src` a `dest`, ritorna `dest`
* `strtok`: boh

### `strtok`

`char* strtok(char* str, const char* delim)` restituisce un pointer al prossimo
token

> [!IMPORTANT]
>
> Diversamente da altri linguaggi non si ritorna una array di stringhe,
> ma viene inserito nella stringa **originale** un `'\0'` ogni volta che
> viene trovato il delimitatore e viene ritornato l'indirizzo di inizio
> del token corrente.
>
> ```c
> #include <stdio.h>
> #include <string.h>
>
> int main()
> {
>     char s[100], 

> [!WARNING]
>
> Ciò implica che non può essere usato con stringhe allocate su memoria statica.

## Operazioni su caratteri

`isDigit`

## Conversione da stringa in altri tipi

`int scanf (const char* s, const char* format, ...);` legge da `s` anziché `stdin`.
