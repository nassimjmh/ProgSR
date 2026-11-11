#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

//Exercice 2.2 : cp_reverse
// 1. vérifier argc
// 2. ouvrir la source en lecture
// 3. ouvrir la dest (créer/vider)
// 4. se placer à la fin, boucle : reculer d'un octet, lire, écrire
// 5. fermer


/*
printf "abcde" > a.txt
gcc -Wall -Wextra -g cp_reverse.c -o cp_reverse
./cp_reverse a.txt b.txt
cat b.txt
*/
int main(int argc, char* argv[]){

    if (argc != 3) {
        fprintf(stderr, "usage: %s source dest\n", argv[0]);
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("open source");
        return 1;
    }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst == -1) {
        perror("open dest");
        close(src);
        return 1;
    }

    char c;
    off_t pos = lseek(src, 0, SEEK_END);
    if (pos == -1) {
        perror("lseek");
        close(src);
        close(dst);
        return 1;
    }

    while (pos > 0) {
        pos--;
        if (lseek(src, pos, SEEK_SET) == -1) {
            perror("lseek");
            break;
        }
        if (read(src, &c, 1) != 1) {
            perror("read");
            break;
        }
        if (write(dst, &c, 1) != 1) {
            perror("write");
            break;
        }
    }

    close(src);
    close(dst);
    return 0;
}