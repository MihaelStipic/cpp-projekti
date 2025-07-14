# C++ Projekti

Ovaj repozitorij sadrži nekoliko manjih projekata napisanih u programskom jeziku C++. Svaki projekt nalazi se u zasebnoj `.cpp` datoteci i može se samostalno pokrenuti.

## Popis projekata

### 1. Banka.cpp

**Opis:**  
Simulacija jednostavnog bankovnog sustava s osnovnim funkcijama za upravljanje računom.

Program se sastoji od dvije glavne klase:


**Account** – predstavlja pojedinačni bankovni račun s podacima o vlasniku, broju računa, trenutnom stanju i zapisima transakcija.

**Bank** – upravlja više računa, omogućuje kreiranje novih računa, uplate, isplate, pregled računa i listu svih računa.


## **Funkcionalnosti:**
- Kreiranje bankovnih računa
- Uplata i isplata novca
- Prikaz stanja računa
- Evidencija svih transakcija
- Lista svih računa u sustavu
- Jednostavno sučelje u konzoli
  
### Kako pokrenuti:

```bash
g++ Banka.cpp -o banka
```
Zatim, za Windows korisnike:
```bash
./banka.exe
```
Za Linux ili MacOS:
```bash
./banka
```


---

### 2. TicTacToe.cpp

**Opis:**  
Konzolna verzija igre "Križić-kružić" za dva igrača.

Program se sastoji od tri glavne klase:


**Player** – klasa koja predstavlja igrača s imenom i simbolom.

**Board** – klasa koja predstavlja ploču za igru, upravlja pozicijama, prikazom i provjerom pobjednika ili popunjenosti ploče.

**Game** – klasa koja upravlja tijekom igre, naizmjeničnim unosima igrača, provjerom pobjednika i ispisom rezultata.


## **Funkcionalnosti:**
- Igra za dva igrača (simboli 'X' i 'O')
- Unos pozicije na ploči (0–8) s provjerom valjanosti poteza
- Prikaz ploče s označenim pozicijama i simbolima
- Automatska provjera pobjednika nakon svakog poteza
- Detekcija neriješenog ishoda ako su sve pozicije popunjene
- Jednostavno tekstualno sučelje za konzolu

## Kako pokrenuti:

```bash
g++ TicTacToe.cpp -o tictactoe
```
Zatim, za Windows korisnike:
```bash
./tictactoe.exe
```
Za Linux ili MacOS:
```bash
./tictactoe
```
