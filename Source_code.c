#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Admin(void);
void Student(void);
void Student_Login(void);
void Admin_Login(void); 


int main(void)
{
    int User;
    FILE *catalogue;
    catalogue = fopen("catalogue.txt", "a+");

start:
    printf("-----------------WELCOME TO JIIT LIBRARY-----------------\n\n");
    printf("Please select your category:\n");
    printf("\t 1. Admin\n");
    printf("\t 2. Student\n");
    printf("Enter your choice here: ");

    if (scanf("%d", &User) != 1)
    {
        printf("Invalid input. Please enter a number.\n\n\n");
        while (getchar() != '\n');
        goto start;
    }
    printf("\n\n");
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
    fclose(catalogue);
    return 0;
}
void Admin(void)
{
    int Choice;
    FILE *student_file;
    student_file = fopen("students.txt", "a+");
    FILE *IT_College_Library_Catalogue;
    IT_College_Library_Catalogue = fopen("IT_College_Library_Catalogue.txt", "a+");
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
           { 
            int num;
            if (student_file == NULL)
            {
                printf("Error opening student file.\n");
                return;
            }
            printf("How many students do you want to add? ");
            scanf("%d", &num);
            printf("\n");
            char name[50], roll_number[20], email[50];
            fprintf(student_file, "Name,Roll Number,Email\n");
            for (int i = 0; i < num; i++)
            {
                printf("Enter the name of student %d: ", i + 1);
                fgets(name, sizeof(name), stdin); // Read string with spaces
                name[strcspn(name, "\n")] = '\0'; // Remove newline character from the end of the string
                printf("Enter the roll number of student %d: ", i + 1);
                fgets(roll_number, sizeof(roll_number), stdin); // Read string with spaces
                roll_number[strcspn(roll_number, "\n")] = '\0'; // Remove newline character from the end of the string
                printf("Enter the email of student %d: ", i + 1);
                fgets(email, sizeof(email), stdin); // Read string with spaces
                email[strcspn(email, "\n")] = '\0'; // Remove newline character from the end of the string
                fprintf(student_file, "%s,%s,%s\n", name, roll_number, email);  
            }
            fclose(student_file);
            printf("Students added successfully.\n");   
            printf("The changes will be reflected in the students.txt file.\n");
            break;}

        case 2:
            {
            if (IT_College_Library_Catalogue == NULL)
            {
                printf("Error opening library catalogue file.\n");
                return;
            }
            char book_name[100], author_name[100], publisher_name[100];
            char num_books[10];
            int total_books = 0;
            printf("How many books do you want to add? ");
            scanf("%d", &total_books);
            fprintf(IT_College_Library_Catalogue, "Book Name,Author Name,Publisher Name,Number of Books\n");
            for (int i = 0; i < total_books; i++)
            {
                printf("Enter the name of book %d: ", i + 1);
                getchar(); // Clear the newline character from the input buffer
                fgets(book_name, sizeof(book_name), stdin); // Read string with spaces
                book_name[strcspn(book_name, "\n")] = '\0'; // Remove newline character from the end of the string
                printf("Enter the author name of book %d: ", i + 1);
                fgets(author_name, sizeof(author_name), stdin); // Read string with spaces
                author_name[strcspn(author_name, "\n")] = '\0'; // Remove newline character from the end of the string
                printf("Enter the publisher name of book %d: ", i + 1);
                fgets(publisher_name, sizeof(publisher_name), stdin); // Read string with spaces
                publisher_name[strcspn(publisher_name, "\n")] = '\0'; // Remove newline character from the end of the string
                printf("Enter the quantity of copies of the books added to the library %d: ", i + 1);
                scanf("%s", num_books); // Read number of books as string
                num_books[strcspn(num_books, "\n")] = '\0'; // Remove newline character from the end of the string
                fprintf(IT_College_Library_Catalogue, "%s,%s,%s,%s\n", book_name, author_name, publisher_name, num_books);
            }

            fclose(IT_College_Library_Catalogue);
            printf("Books added to the library successfully.\n");
            printf("The changes will be reflected in the IT_College_Library_Catalogue.txt file.\n");
            break;
            }
        case 3:
            {printf("\nTo check the availability of a book:\n");
            printf("\t1.Enter the name of the book:\n");
            printf("\t2.Enter the author name:\n");
            printf("\t3.Enter the publisher name:\n");
            break;}

        case 4:
            {
                FILE *catalogue;
                char book_name[100],author_name[100],publisher_name[100];
                int num_books;
                int total_books = 0;
                catalogue = fopen("IT_College_Library_Catalogue.txt", "r"); 
                if (catalogue == NULL)
                {
                    printf("Error opening library catalogue file.\n");
                    return;
                }
                fscanf(catalogue,"%*[^\n]\n");//To remove the first line of the csv file 
                while (fscanf(catalogue, "%[^,],%[^,],%[^,],%d\n", 
                    book_name, 
                    author_name, 
                    publisher_name, 
                    &num_books) == 4)
                {
                    total_books += num_books;
                }
                fclose(catalogue);
                printf("\nLibrary Statistics Dashboard\n");
                printf("1.Total number of books in the library : %d\n",total_books);
                printf("2.Total number of book currently present in the library : \n");
                printf("3.Total Issued Books :\n");
                printf("4.Total registered students : \n");
                break;
        }

        default:
            {printf("Invalid Admin choice.\n");
            break;}
    }
}
void Student(void)
{
    int Choice;

    printf("\nWelcome to the Student Dashboard\n");
    printf("What do you want to do?\n");
    printf("\t 1. Issue a book\n");
    printf("\t 2. Return a book\n");
    printf("\t 3. Check pending fine\n");
    printf("\t 4. Search for a book\n");
    printf("Enter your choice here: ");

    if (scanf("%d", &Choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (Choice)
    {
        case 1:
            {printf("\nEnter the following details of the book:\n");
            printf("\t1. Book Name\n");
            printf("\t2. Author Name\n");
            printf("\t3. Publisher Name\n");
            printf("\t4.Enter the number of days for which you want to issue the book: ");
            /* Add input handling for book details and issue date. */
            break;}

        case 2:
            {printf("\nEnter the following details of the book:\n");
            printf("\t1. Book Name\n");
            printf("\t2. Author Name\n");
            printf("\t3. Publisher Name\n");
            break;
            }
        case 3:
            {printf("\nEnter the name of the book you issued: ");
            printf("\nEnter the name of the author of the book  : ");
            break;}

        case 4:
            {printf("\nEnter the name of the book: ");
            break;}

        default:
            {printf("Invalid choice.\n");
            printf("Please enter  a valid choice. \n");
            break;}
    } 
}
