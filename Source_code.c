#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Function declarations */
void Admin(void);
void Student(void);
int main(void)
{
    int User;
start:
    printf("-----------------WELCOME TO JIIT LIBRARY-----------------\n\n");
    printf("Please select your category:\n");
    printf("\t1. Admin\n");
    printf("\t2. Student\n");
    printf("Enter your choice here: ");
    if (scanf("%d", &User) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }
    switch (User)
    {
        case 1:
            Admin();
            break;

        case 2:
            Student();
            break;

        default:
            printf("Please enter a valid user choice.\n\n");
            goto start;
    }
    return 0;
}
void Admin(void)
{
    int Choice;

    printf("\nWelcome to the Admin Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Add a student\n");
    printf("\t2. Add a book\n");
    printf("\t3. Check availability of books\n");
    printf("\t4. Library statistics dashboard\n");
    printf("Enter your choice here: ");

    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (Choice)
    {
        case 1:
            printf("\nTo add a student, provide the following details:\n");
            printf("\tEnter the name of the student: ");
            printf("\n\tEnter the enrollment number of the student: ");
            printf("\n\tEnter the branch of the student: ");
            printf("\n\tEnter the contact number of the student: ");
            printf("\nThe student is added successfully.\n");
            break;

        case 2:
            printf("\nTo add a new book, provide the following details:\n");
            printf("\tEnter the name of the book: ");
            printf("\n\tEnter the name of the author: ");
            printf("\n\tEnter the serial number of the book: ");
            printf("\n\tEnter the shelf number: ");
            printf("\nThe book is added successfully.\n");
            break;

        case 3:
            printf("\nTo check the availability of a book:\n");
            printf("\tEnter the name of the book:\n");
            printf("\tEnter the author name:\n");
            break;

        case 4:
            printf("\nLibrary Statistics Dashboard\n");
            break;

        default:
            printf("Invalid Admin choice.\n");
            break;
    }
}
void Student(void)
{
    int Choice;

    printf("\nWelcome to the Student Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t1. Issue a book\n");
    printf("\t2. Return a book\n");
    printf("\t3. Check pending fine\n");
    printf("\t4. Search for a book\n");
    printf("Enter your choice here: ");

    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (Choice)
    {
        case 1:
            printf("\nEnter the following details of the book:\n");
            printf("\t1. Book Name\n");
            printf("\t2. Author Name\n");
            printf("\t3. Publisher Name\n");
            printf("Enter the number of days for which you want to issue the book: ");
            /* Add input handling for book details and issue date. */
            break;

        case 2:
            printf("\nEnter the following details of the book:\n");
            printf("\t1. Book Name\n");
            printf("\t2. Author Name\n");
            printf("\t3. Publisher Name\n");
            break;

        case 3:
            printf("\nEnter the name of the book you issued: ");
            break;

        case 4:
            printf("\nEnter the name of the book: ");
            break;

        default:
            printf("Invalid Student choice.\n");
            break;
    }
}
