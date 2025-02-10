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
  - k == 6 is the sixth exercise
  - k == 7 is the seventh exercise
  - k == 8 is the eighth exercise
  - k == 9 is the ninth exercise
  - k == 10 is the tenth exercise
  - k == 11 is the eleventh exercise
  - k != 1,2,3,4,5,6,7,8,9,10,11 an error is thrown

## exercise 1
Manipulation d’un tableau C 1D
## exercise 2
Tableau C 2D (matrice)
## exercise 3
Utilisation de std::array
## exercise 4
Utilisation de std::vector
## exercise 5
Utilisation de std::list
## exercise 6
Utilisation de std::set
## exercise 7
Utilisation de std::map
## exercise 8 
Compteur de mots avec std::unordered_map
## exercise 9
Trier un std::vector
## exercise 10
Trouver la Plus Longue Séquence Consécutive dans un std::set
## exercise 11
Implémentation d’un Cache LRU (Least Recently Used)

(check the [code](main.cpp) and [TP3 pdf](TP4.pdf) for more details)