# Puntatori a Funzioni

In C le funzioni non sono variabili (tipi di dato), ma possiamo otternere
dei **puntatori** a funzioni definite nel programma o in librerie.

Tali puntatori possono quindi essere passati come **parametro** per **invocare**
la funzione puntato in seguito.

```c
tipo_di_ritorno (*identificatore) (argomenti...);
```

Ad esempio:

```c
int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int main()
{
    int (*pippo)(int, int);
    int a = 1, b = 2;

    pippo = add;
    printf("a: %d, b: %d, pippo(a, b): %d\n", a, b, pippo(a, b));
    // -> a: 1, b: 2, pippo(a, b): 3

    pippo = mul;
    printf("a: %d, b: %d, pippo(a, b): %d\n", a, b, pippo(a, b));
    // -> a: 1, b: 2, pippo(a, b): 2

    return 0;
}
```

## Funzione `qsort`: uso di `void*`

`qsort` realizza un algoritmo di quicksort che generalizza i dati su cui lavora.

In `stdlib.h`:

```c
void qsort (void* base, size_t num, size_t size, int (*compar)(const void*, const void*));
```

> [!WARNING]
>
> La genericità va eliminata completamente all'interno della funzione compar:
> Essa dovrà fare il casting al tipo giusto:
>
> ```c
> int intComp(const void* a, const void* b)
> {
>     return *((int*)a) - *((int*)b);
> }
>
> // An eternity of lines later
> qsort (someArrayPtr, arrayLength, sizeof(int), intComp);
> ```
