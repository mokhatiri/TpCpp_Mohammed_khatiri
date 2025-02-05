# To Run:


(where k is the number of the exercise)
## compile the code
use the command:

```sh
g++ -o Exo_k main.cpp -std=c++17 -DEXO=k
```

## run the made executable
use the command:

```sh
./Exo_k
```

## you can also run the already made executables:

first go to the folder 'Exos'

```sh
cd Exos
```

then you can run the exercice 'k' using:

```sh
./Exok
```

for the case of exercice 6:
two executables are given:
  - Exo6_1
  - Exo6_2

# code explaining:

## main part
"main.cpp" is the main file
it contains all the exercises.

when given a number of exercise, it will run the corresponding exercise using preprocessor directives.

each exercise is defined in a separate main function

the macro EXO help you determine wich part is to compile.
when:
  - k == 1 is the first exercise
  - k == 2 is the second exercise
  - k == 3 is the third exercise
  - k == 4 is the fourth exercise
  - k == 5 is the fifth exercise
  - k == 6 is the sixth exercise
  - k != 1,2,3,4,5,6 an error is thrown

## exercice 1:
Analyse de la mémoire d’un tableau
## exercice 2:
Estimation pour le service de nettoyage de tapis
## exercice 3:
Calcul de la factorielle à la compilation avec constexpr
## exercice 4:
Variables Globales et Locales (Shadowing)
## exercice 5:
Utilisation avancée des constantes
## exercice 6:
Détection d’overflow lors d’une multiplication
- you can compile each test of the two tests by:

for test 1: (a = 30000, b=1000)
```sh
g++ -o Exo6_1 main.cpp -std=c++17 -DEXO=6 -DTEST=1
```

for test 2: (a = 300000, b=10000)
```sh
g++ -o Exo6_2 main.cpp -std=c++17 -DEXO=6 -DTEST=2
```


(check the [code](main.cpp) and [TP3 pdf](TP3.pdf) for more details)