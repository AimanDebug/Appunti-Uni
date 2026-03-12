# `bash`

## Che cos'è

Una shell:

* permette di **interagire con l'S.O**. in modo diretto: si lanciano comandi
* **scripting**: scrivere programmi con lo scopo di **automatizzare** operazioni ripetitive

> [!INFO]
>
> Gli utenti tipici sono gli **amministratori di sistema** e i **sistemisti**.


## Espressioni

```bash
val=5+5
echo $val # 5 + 5
echo $((val * 5)) # 50
```

> [!WARNING]
>
> I valori devono essere interi


### Operatore virgola `,`

```bash
echo $((val=5, v=3, val*v)) # 15
```

Come in altri linguaggi, valuta le espressioni da sinistra a destra,
restituendo il valore dell'ultima espressione.

## Strutture di controllo

### `if`

```bash
# if [[ -e file.txt ]]; then        # superfluo, -e è implicito con -f
if [[ -f file.txt ]]; then          # se file.txt esiste
        cat file.txt
fi
# fi
```

Esegue il blocco `then` se la condizione esce con 0.

> [!NOTE]
>
> ``[[ ]]``  è un costrutto che permette di testare condizioni, restituisce 0 se la condizione è vera, 1 altrimenti.

### `case`

```bash
echo "Da quanti anni sei iscritto a questo corso?"
read anni
case $anni in
        1) echo "Benvenuto!"
        ;;
        2) echo "Bentornato!"
        ;;
        3) echo "Wow, sei un veterano!"
        ;;
        4) echo "CAPISCO..."
        ;;
        5) echo "ANCORA QUI?"
        ;;
        6) echo "BASTAAAA"
        ;;
        7) echo "RECIDIVO"
        ;;
esac
```

### Funzioni

```bash
function saluta {
        echo "Ciao $1!"
}
```

> [!TIP]
>
> $1, $2, ... sono i parametri passati alla funzione, $0 è il nome della funzione stessa.

> [!ATTENTION]
>
> \$10 non è il decimo parametro, ma \$1 seguito da 0. Per accedere al decimo parametro, bisogna usare `${10}`.

### Pattern matching

```bash
[[ ciao =~ ^c ]]; echo $? # 0
[[ ciao =~ o$ ]]; echo $? # 0
[[ c =~ [a-d] ]]; echo $? # 0
```
