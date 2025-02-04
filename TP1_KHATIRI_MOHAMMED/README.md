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
  - k != 1,2,3,4,5 an error is thrown

## exercice 1:
Aﬀichage d’un message:
## exercice 2:
Lecture et aﬀichage d’un entier
## exercice 3:
Opérations mathématiques
## exercice 4:
Détection et correction d’erreurs de compilation
## exercice 5:
Conversion de température

(check the [code](main.cpp) and [TP1 pdf](TP1.pdf) for more details)