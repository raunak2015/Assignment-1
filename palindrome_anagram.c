// String Palindrome and Anagram checker
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char* s) {
    for (int i = 0; s[i]; i++) s[i] = tolower(s[i]);
}

int isPalindrome(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i]) return 0;
    return 1;
}

int isAnagram(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return 0;
    int freq[256] = {0};
    for (int i = 0; s1[i]; i++) freq[(unsigned char)s1[i]]++;
    for (int i = 0; s2[i]; i++) {
        freq[(unsigned char)s2[i]]--;
        if (freq[(unsigned char)s2[i]] < 0) return 0;
    }
    return 1;
}

int countWords(char* s) {
    int count = 0, inWord = 0;
    for (int i = 0; s[i]; i++) {
        if (!isspace(s[i]) && !inWord) { count++; inWord = 1; }
        else if (isspace(s[i])) inWord = 0;
    }
    return count;
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);
    char orig[100]; strcpy(orig, s1);
    toLowerCase(s1);
    printf("'%s' is %sa palindrome\n", orig, isPalindrome(s1) ? "" : "NOT ");

    printf("Enter second string to check anagram: ");
    scanf("%s", s2);
    char low1[100], low2[100];
    strcpy(low1, s1); strcpy(low2, s2); toLowerCase(low2);
    printf("'%s' and '%s' are %sanagrams\n", s1, s2, isAnagram(low1, low2) ? "" : "NOT ");

    char sentence[200];
    printf("Enter a sentence (with spaces): ");
    fflush(stdin);
    fgets(sentence, sizeof(sentence), stdin);
    printf("Word count: %d\n", countWords(sentence));

    return 0;
}
