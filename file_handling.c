// File Handling in C - Read, Write, Append
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) { perror("Cannot open file"); return; }

    fprintf(fp, "Line 1: Hello from C file handling!\n");
    fprintf(fp, "Line 2: Writing data to a file.\n");
    fprintf(fp, "Line 3: This is a test file.\n");
    fclose(fp);
    printf("Data written to %s\n", filename);
}

void readFromFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) { perror("Cannot open file"); return; }

    char line[256];
    printf("\nContents of %s:\n", filename);
    while (fgets(line, sizeof(line), fp))
        printf("  %s", line);
    fclose(fp);
}

void appendToFile(const char* filename, const char* text) {
    FILE* fp = fopen(filename, "a");
    if (!fp) { perror("Cannot open file"); return; }
    fprintf(fp, "%s\n", text);
    fclose(fp);
    printf("Appended to %s\n", filename);
}

int countLines(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return -1;
    int count = 0; char ch;
    while ((ch = fgetc(fp)) != EOF) if (ch == '\n') count++;
    fclose(fp);
    return count;
}

int main() {
    const char* file = "test_output.txt";
    writeToFile(file);
    appendToFile(file, "Line 4: Appended line.");
    readFromFile(file);
    printf("\nTotal lines: %d\n", countLines(file));
    remove(file); // cleanup
    return 0;
}
