#include <stdio.h>
#include <memory.h>

// Declare structures
struct Student;

// Declare functions
void printStudent(struct Student);

// Initialize structures
struct Student {
    char name[100];
    int age;
    int studentNumber;
};

int main() {
    struct Student student1;
    struct Student student2;

    // Student 1 specs
    strcpy(student1.name, "Naam");
    student1.age = 18;
    student1.studentNumber = 10040;

    // Student 2 specs
    strcpy(student2.name, "Naam2");
    student2.age = 19;
    student2.studentNumber = 10041;

    printStudent(student1);
    printStudent(student2);
}

void printStudent(struct Student student) {
    printf("Student specs: %s %d %d\n", student.name, student.age, student.studentNumber);
}
