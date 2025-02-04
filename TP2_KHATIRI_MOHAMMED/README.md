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
  - k != 1,2,3,4 an error is thrown

## exercice 1:
Utilisation des directives du préprocesseur
- the default case is the case where macro 'DEBUG' is not defined
- to check the case where macro 'DEBUG' is defined, when compiling, use the -DDEBUG option:
```sh
g++ -o Exo_1 main.cpp -std=c++17 -DEXO=1
```

## exercice 2:
Utilisation de la fonction main
## exercice 3:
Espaces de noms et portée des variables
- when running the code, you can use the following command to test different additions:
```sh
./Exo4 argument1 argument2 argument3 ... argumentN
```
## exercice 4:
Entrée et sortie avec cin et cout

(check the [code](main.cpp) and [TP2 pdf](TP2.pdf) for more details)