#include "ct_diary_calendar_creator_node.h"
#include "ct_diary_calendar_creator_table.h"
#include "ct_diary_calendar_creator_data.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    UNUSED(argc);
    UNUSED(argv);

    printf("BEG ALLOCATION\n");
    char *text;
    text = malloc(SIZE_TEXT);
    if (text) {
        printf("Allocation ok.\n");
        text[0] = 0;
    } else {
        printf("Allocation error.\n");
        exit(0);
    }
    printf("END ALLOCATION\n\n");

    data_st d;
    data_init(&d, 0, 0, 0, 0);

    printf("BEG CREATE\n");
    strcat(text, "<?xml version=\"1.0\"?>\n");
    strcat(text, "<cherrytree>\n");
    diary_node_main(d, text);
    strcat(text, "</cherrytree>\n");
    printf("END CREATE\n\n");

#if FILE_WRITE == TRUE
    printf("BEG WRITE\n");
    FILE *file;
    file = fopen(FILE_NAME FILE_EXTENSION, "w+");
    if (fwrite(text, strlen(text), 1, file)) {
        printf("Write ok.\n");
    } else {
        printf("Write error.\n");
    }
    fclose(file);
    printf("END WRITE\n\n");
#endif

#if FILE_OPEN == TRUE
    printf("BEG OPEN\n");
    if (!(system("cherrytree ./" FILE_NAME FILE_EXTENSION " & exit"))) {
        printf("Open ok.\n");
    } else {
        printf("Open error.\n");
    }
    printf("END OPEN\n\n");
#endif

    free(text);
    return 0;
}
