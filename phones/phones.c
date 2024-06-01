#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define PHONEBOOK_FILE "phonebook.txt"

void add_entry(const char *name, const char *number) {
    int fd = open(PHONEBOOK_FILE, O_APPEND);
    if (fd == -1) {
        perror("open");
        return;
    }
    dprintf(fd, "%s,%s\n", name, number);
    close(fd);
}

int main() {
    // Create a sample phonebook
    lookup_number("Alice");
    int pid = fork();
    if (pid == 0) {
        // Child process
        lookup_number("Alice");
    }
    pid = fork();
    if (pid == 0) {
        // Child process
        add_entry("Mike", "0526830183");
    }
    


    return 0;
}
