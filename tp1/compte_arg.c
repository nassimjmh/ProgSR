#include <stdlib.h>
#include <stdio.h>

//Exercice 1

// gcc -Wall -Wextra -g compte_arg.c -o compte_arg
int main(int argc, char* argv[]){
    int somme = 0;
    int n;
    for (int i=1; i < argc; i++){
        //n = atoi(argv[i]);
        if (sscanf(argv[i], "%d", &n))
        somme+=n;
    }
    printf("%d\n",somme);
    return somme;
}