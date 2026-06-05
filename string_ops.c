// String Operations in C without using string.h functions
#include <stdio.h>

int strLen(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void strRev(char* s) {
    int len = strLen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int isPalindrome(char* s) {
    int len = strLen(s);
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i]) return 0;
    return 1;
}

void strToUpper(char* s) {
    for (int i = 0; s[i]; i++)
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
}

int countVowels(char* s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char c = s[i] | 32;
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') count++;
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Length: %d\n", strLen(str));
    printf("Vowels: %d\n", countVowels(str));
    printf("Palindrome: %s\n", isPalindrome(str) ? "Yes" : "No");

    strToUpper(str);
    printf("Uppercase: %s\n", str);

    strRev(str);
    printf("Reversed: %s\n", str);

    return 0;
}
