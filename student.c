// Student Record Management using Structures
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student {
    int rollNo;
    char name[50];
    float marks[5];
    float average;
    char grade;
};

char getGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 45) return 'D';
    else return 'F';
}

void calcAverage(struct Student* s) {
    float sum = 0;
    for (int i = 0; i < 5; i++) sum += s->marks[i];
    s->average = sum / 5.0;
    s->grade = getGrade(s->average);
}

void displayStudent(struct Student s) {
    printf("\nRoll No: %d | Name: %s\n", s.rollNo, s.name);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) printf("%.1f ", s.marks[i]);
    printf("\nAverage: %.2f | Grade: %c\n", s.average, s.grade);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    if (n > MAX_STUDENTS) n = MAX_STUDENTS;

    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: "); scanf("%d", &students[i].rollNo);
        printf("Name: "); scanf("%s", students[i].name);
        printf("Enter 5 subject marks:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
        calcAverage(&students[i]);
    }

    printf("\n===== Student Report =====");
    for (int i = 0; i < n; i++)
        displayStudent(students[i]);

    return 0;
}
