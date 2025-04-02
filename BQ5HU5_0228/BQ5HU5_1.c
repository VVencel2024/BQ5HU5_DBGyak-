#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256

void convert_to_uppercase(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Hiba a fájl megnyitásakor");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file)) {
        for (int i = 0; line[i]; i++) {
            line[i] = toupper((unsigned char)line[i]);
        }
        printf("%s", line);
    }
    
    fclose(file);
}

int main() {
    char filename[MAX_LINE];
    printf("File name: ");
    fgets(filename, MAX_LINE, stdin);
    filename[strcspn(filename, "\n")] = 0;  // Újsor eltávolítása
    
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Hiba a fájl létrehozásakor");
        return EXIT_FAILURE;
    }
    
    char line[MAX_LINE];
    printf("Adja meg a hallgató nevét és neptunkódját (# a befejezéshez):\n");
    
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (line[0] == '#' && line[1] == '\n') break; // Ha csak # van
        fputs(line, file);
    }
    
    fclose(file);
    
    printf("\nA fájl tartalma nagybetűsen:\n");
    convert_to_uppercase(filename);
    
    return 0;
}
