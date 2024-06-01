#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
void lookup_number(const char *name) {
    int fd = open(PHONEBOOK_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }
    system("grep \"mickey mouse\" phonebook.txt | sed 's/ /#/g' | sed 's/,/ /' | awk '{print $2}'");
    close(fd);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Error\n");
        return 1;
    }
    lookup_number(argv[1]);
    return 0;
}