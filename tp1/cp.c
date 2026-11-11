#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define TAILLE 4096

//Exercice 2
// 1. vérifier argc
// 2. ouvrir la source en lecture
// 3. ouvrir la dest (créer/vider)
// 4. boucle : lire, écrire
// 5. fermer


int main(int argc, char* argv[]){

    int nb_read;

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("open source");
        return 1;
    }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst == -1) {
        perror("open dest");
        return 1;
    }
    
    char buf[TAILLE];
    ssize_t n;

    while ((n = read(src, buf, sizeof(buf))) > 0) {
        if (write(dst, buf, n) != n) {
            perror("write");
            close(src);
            close(dst);
            return 1;
        }
    }
    if (n == -1){
        perror("read");
    }

    close(src);
    close(dst);
    return 0;
}