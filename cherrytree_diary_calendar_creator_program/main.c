#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ct_dcc_main.h"

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    char *text;
    FILE *file;
    ct_dcc_config conf_st;

    if ((text = malloc(SIZE_TEXT_BUFF))) {
        printf("Allocation ok.\n");
        text[0] = 0;
    } else {
        printf("Allocation error.\n");
        exit(0);
    }

    if (ct_dcc_start(text, &conf_st)) {
        printf("Create ok.\n");
    } else {
        printf("Create error.\n");
        exit(0);
    }

    file = fopen(FILE_NAME FILE_EXTENSION, "w+");
    if (fwrite(text, strlen(text), 1, file)) {
        printf("Write ok.\n");
    } else {
        printf("Write error.\n");
    }
    fclose(file);

    if (!(system("cherrytree ./" FILE_NAME FILE_EXTENSION " & exit"))) {
        printf("Open ok.\n");
    } else {
        printf("Open error.\n");
    }
    free(text);

    return 0;
}
