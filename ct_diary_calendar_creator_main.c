#include "ct_diary_calendar_creator_main.h"

int main(int argc, char *argv[]){
    UNUSED(argc);
    UNUSED(argv);

    data_st d;

#if CREATE_TEXT == TRUE
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
#endif

#if CREATE_TEXT == TRUE
    printf("BEG CREATE\n");
    strcat(text, "<?xml version=\"1.0\"?>\n");
    strcat(text, "<cherrytree>\n");
    diary_node_main(d, text);
    strcat(text, "</cherrytree>\n");
    printf("END CREATE\n\n");
#endif

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

#if CREATE_TEXT == TRUE
    free(text);
#endif
    return 0;
}
