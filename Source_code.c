#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int User;
    FILE *file = fopen("IT_College_Library_Catalogue.csv","r");
    start : printf("-----------------WELCOME TO JIIT LIBRARY-----------------\n\n");
    printf("Please select your category : \n");;
    printf("\t1. Admin\n");
    printf("\t2.Student\n");
    printf("Enter your choice here : ");
    scanf("%d",&User);
    switch(User){
        case 1:
            Admin();
        case 2:
            Student();
        default:
            {printf("Please enter a valid user choice");
            goto start;}
    }
    return 0;
}
Admin()
{
    int Choice;
    printf("Welcome to the Admin Dashboard\n");
    printf("What do you want to do  : \n");
    printf("\t1. Add a student \n");
    printf("\t2. Add a book \n");
    printf("\t3.Check avaliability of books \n");
    printf("\t4.Library statistics dashboard \n");
    printf("Enter your choice here : ");
    scanf("%d",&Choice);
    switch(Choice){
        case 1:{
            printf("To add a student add please provide the following details : \n");
            printf("\tEnter the name of the student : ");
            printf("\tEnter the enrollment number of the student : ");
            printf("\tEnter the branch of the student :");
            printf("\tEnter the contact number of the student withount any prefixes :");
            printf("\n");
            printf("The student is added successfully :");
            
        }
        case 2:{
            printf("To add a new book to the library, please enter the following details about the book :\n");
            printf("\tEnter the name of the book :");
            printf("\tEnter the name of the Author of the book :");
            printf("\tEnter the serial number of the book :");
            printf("\tEnter the shelf number in which the book is placed :");
            printf("\n");
            printf("The book is added successfully :");
        }
        case 3:{}
        case 4:{}
    }
}
Student()
{int Choice;
    printf("Welcome to the Student Dashboard\n");
    printf("What do you want to do  : \n");
    printf("\t1. Issue a book \n");
    printf("\t2. Return a book \n");
    printf("\t3.Check pending fine \n");
    printf("\t4. Search for a book \n");
    printf("Enter your choice here : ");
    scanf("%d",&Choice);
 switch(Choice){
        case 1:{
            printf("Enter following0 details of the book : \n");
            printf("\t1.Book Name\n");
            printf("\t2.Author Name\n");
            printf("\tPublisher name\n");
            printf("Enter the number of days for which you want to issue the book : ");
            //Write a part to take input for system date and time of issue
        }
        case 2:{
            printf("Enter the following details of the book :");
            printf("\t1.Book Name\n");
            printf("\t2.Author Name\n");
            printf("\tPublisher name\n");
        }
        case 3:{
            printf("Enter the name of the book you issued :");
        }
        case 4:{
            printf("Enter the name of the book :");
        }
    }
}
