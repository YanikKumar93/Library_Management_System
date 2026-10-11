#include<stdio.h>
int main()
{
    int User;
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
}
