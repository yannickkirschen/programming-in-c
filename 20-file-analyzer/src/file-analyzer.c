#include <stdio.h>

int analyze_file(char *file_name, int *byteCount) {
    FILE *file;

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: can't open file.\n");
        return -1;
    }

    while (!feof(file)) {
        byteCount[fgetc(file)]++;
    }

    fclose(file);
    return 0;
}

void print_analysis_result(int *byteCount) {
    for (int i = 0; i < 255; i++) {
        if (byteCount[i]) {
            printf("Byte %i occurs %i time(s).\n", i, byteCount[i]);
        }
    }
}

void print_analysis_bar_result(const int *byteCount) {
    for (int i = 0; i < 255; i++) {
        if (byteCount[i]) {
            printf("%03i: ", i);

            for (int j = 0; j < byteCount[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: file-analyzer <FILE>\n");
        return -1;
    }

    int byteCount[255] = {0};
    analyze_file(argv[1], byteCount);
    print_analysis_result(byteCount);
//    print_analysis_bar_result(byteCount);
}
