//1C.Write a program which creates a structure Student which must have the attribute Avg Marks with 3 more attributes sort the list of the student in descending order using Bubble sort.	in c
#include <stdio.h>
#include <string.h>
struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};
int main() {
    struct Student s[100], temp;
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks < s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\nStudents sorted in descending order of Average Marks:\n");
    printf("\n");
    printf("%-10s %-15s %-10s %-10s\n", "Roll No", "Name", "Age", "Avg Marks");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-10d %-10.2f\n", s[i].rollNo, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}
